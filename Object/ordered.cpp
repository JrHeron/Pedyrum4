#include "ordered.h"
#include <QDebug>
#include <QMessageBox>

Ordered::Ordered(QObject *parent) :
    QObject(parent)
{
}

void Ordered::start(QSqlDatabase *sdb){
    bd.sdb = *sdb;

    instance();
}

bool Ordered::instance()
{
    QList<QString> headers;

    QString sql;

    headers << tr("Id do pedido") << tr("Data") << tr("Hora") << tr("Tipo") << tr("Valor") << tr("Status") << tr("Número do pedido");

    sql = "select idOrder, dateorder, timeorder, typeorder, valueorder, statusOrder, numberorder from ordered order by dateorder";

    if (bd.createModelQuery("ordered", sql, headers)){

        headers.clear();

        headers << tr("Id") << tr("Funcionário") << tr("Status");

        if (bd.createModelQuery("statusEmployee", "select e.idEmployee, e.name, se.status from employee e, statusEmployee se where lower(e.jobrole) = 'entregador' and e.idemployee = se.idemployee order by e.name", headers)){
            bd.createCompleter("statusEmployee", "statusEmployee", 1, false, QCompleter::PopupCompletion, BDTools::QueryModel);

            return true;
        }

        return false;
    }

    return false;
}

void Ordered::changeStatusOrder(QString id, QString status)
{
    bool update = bd.update("ordered", "statusOrder", status, "idorder", id);

    if (update){
        bd.refreshQueryModel("ordered");
    }

    if (status != "Fechado"){

        if (bd.search(QString("select * from datecloseorder where idorder = '%1'").arg(id))){

            int op = QMessageBox::question(NULL, tr("Pedido já fechado/pago"), tr("Esse pedido já havia sido fechado e/ou já foi marcado como pago, sendo essa informação considerada no fechamento de caixa.\nDeseja deletar essa informação?\n\nObs.: caso ele já tenha sido considerado em um fechamento de caixa anterior, ele será considerado novamente."), tr("Sim"), tr("Não"));

            if (op == 0)
                bd.exec(QString("delete from datecloseorder where idorder = '%1'").arg(id));

        }

        if (status != "A caminho"){
            if (bd.search(QString("select * from employeeorder where idorder = '%1'").arg(id))){

                int op = QMessageBox::question(NULL, tr("Deletar entregador"), tr("Esse pedido já possui um entregador ligado a ele.\nDeseja deletar essa referência?"), tr("Sim"), tr("Não"));

                if (op == 0)
                    bd.exec(QString("delete from employeeorder where idorder = '%1'").arg(id));
            }
        }

    }else{

        QString sql = QString("select * from datecloseorder where idorder = '%1'").arg(id);

        if (! bd.search(sql)){

            bd.exec(QString("insert into datecloseorder values('%1','%2','%3')").arg(id, tools.currentYear() + "-" + tools.currentMonth2() + "-" + tools.currentDay(), tools.currentTime()));

        }

    }
}

void Ordered::changeStatusEmployee(int id, QString status)
{
    if (bd.update("statusEmployee", "status", status, "idemployee", QString::number(id))){
        bd.refreshQueryModel("statusEmployee");
    }
}

void Ordered::refreshModel()
{
    bd.refreshQueryModel("ordered");

    bd.refreshQueryModel("statusEmployee");
}

bool Ordered::remove(QString idOrder)
{
    if (bd.exec("delete from datecloseorder where idorder = '" + idOrder + "'"))
        if (bd.exec("delete from schedule where idOrder = '" + idOrder + "'"))
            if (bd.exec("delete from paymentorder where idOrder = '" + idOrder + "'"))
                if (bd.exec("delete from productitem where idOrder = '" + idOrder + "'"))
                    if (bd.exec("delete from itemorder where idOrder = '" + idOrder + "'"))
                        if (bd.exec("delete from employeeorder where idOrder = '" + idOrder + "'"))
                            if (bd.exec("delete from ordered where idOrder = '" + idOrder + "'")){
                                refreshModel();

                                return true;
                            }

    return false;
}
