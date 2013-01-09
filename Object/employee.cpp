#include "employee.h"
#include <QDebug>

void Employee::start(QSqlDatabase *sdb){
    bd.sdb = *sdb;

    instance();
}

bool Employee::loadData(int idEmployee)
{
    setId(idEmployee);

    if (bd.search("select * from employee where idemployee = " + QString::number(idEmployee))){

        QList<QString> data = bd.loadLine(0);

        id = data[0].toInt();
        name = data[1];
        phone = data[2];
        phoneMobile = data[3];
        radio = data[4];
        street = data[5];
        number = data[6];
        complement = data[7];
        district = data[8];
        cep = data[9];
        jobRole = data[10];
        commission = data[11].toDouble();
        cpf = data[12];
        rg = data[13];
        cc = data[14];
        ag = data[15];
        bank = data[16];
        note = data[17];

        return true;
    }

    clearData();

    return false;
}

bool Employee::instance()
{
    QList<QString> headers;

    headers << tr("ID");
    headers << tr("Nome");
    headers << tr("Telefone");
    headers << tr("Celular");
    headers << tr("Rádio");
    headers << tr("Rua");
    headers << tr("Número");
    headers << tr("Complemento");
    headers << tr("Bairro");
    headers << tr("CEP");
    headers << tr("Cargo");
    headers << tr("Comissão");
    headers << tr("CPF");
    headers << tr("RG");
    headers << tr("Conta Corrente 1");
    headers << tr("Agência 1");
    headers << tr("Banco 1");
    headers << tr("Anotação");

    if (bd.createModelQuery("employee", "select * from employee", headers)){
        if (bd.createCompleter("name", "employee", 1, false, QCompleter::InlineCompletion, BDTools::QueryModel))
            return true;
        else
            return false;
    }
    return false;
}

void Employee::clearData()
{
    id = 0;
    name.clear();
    phone.clear();
    phoneMobile.clear();
    radio.clear();
    street.clear();
    number.clear();
    complement.clear();
    district.clear();
    cep.clear();
    jobRole.clear();
    commission = 0;
    cpf.clear();
    rg.clear();
    cc.clear();
    ag.clear();
    bank.clear();
    note.clear();
}

bool Employee::insert(){
    QList<QString> values;

    QString id = QString::number(bd.generateID("employee", "idemployee"));

    values << id << name << phone << phoneMobile << radio << street << number << complement << district << cep << jobRole << QString::number(commission) << cpf << rg << cc << ag << bank << note;

    bool insert = bd.insert("employee", values);

    if (insert){
        bd.exec("insert into statusemployee values(" + id + ", 'Disponível')");

        refreshModel();
    }
    else
        qDebug() << "[EMPLOYEE] [INSERT] Erro na na inserção";

    return insert;
}

bool Employee::update(int id)
{
    QList<QString> fields, values;

    fields << "name" << "phone" << "phone2" << "nextel" << "street" << "nhouse" << "complement" << "district" << "cep" << "jobrole" << "commission" << "cpf" << "rg" << "cc1" << "ag1" << "bank1" << "note";

    values << name << phone << phoneMobile << radio << street << number << complement << district << cep << jobRole << QString::number(commission) << cpf << rg << cc << ag << bank << note;

    return bd.update("employee", fields, values, "idemployee", QString::number(id));
}

bool Employee::remove(int id)
{
    if (bd.remove("statusemployee", "idemployee", QString::number(id)))
        return bd.remove("employee", "idemployee", QString::number(id));

    return false;
}

void Employee::setFilter(QString filter)
{
    QString sql = QString("select e.* from employee e, statusemployee se where se.idemployee = e.idemployee and %1").arg(filter);

    bd.updateModelQuery("employee", sql);

    refreshModel();
}

void Employee::setFilter(){

    QString filter = "select e.* from employee e, statusemployee se where se.idemployee = e.idemployee ";

    if (areFilterJobRole){
        filter += "and " + filterJobRole + " ";
    }

    if (areFilterStatus){
        filter += QString("and %1").arg(filterStatus);
    }

    bd.updateModelQuery("employee", filter);
}

void Employee::setFilterJobRole(QString jobRole){
    areFilterJobRole = true;

    filterJobRole = QString("jobrole = '%1'").arg(jobRole);

    setFilter();
}

void Employee::setFilterStatus(bool free){
    areFilterStatus = true;

    if (free)
        filterStatus = "se.status = 'Disponível'";
    else
        filterStatus = "se.status = 'Ocupado'";

    setFilter();
}

void Employee::clearFilter()
{
    setFilter();

    refreshModel();
}

double Employee::getValueCommission(QString id, double commission, QString dateI, QString dateF)
{
    // comissão por porcentagem

    QString sql = QString("Select sum(o.valueorder) from employeeorder eo, ordered o, datecloseorder dco where eo.idemployee = %1 and (o.statusorder = 'Fechado' or ispaid = 'true')and dco.dateclose >= '%2' and dco.dateclose <= '%3'").arg(id, tools.convertDate(dateI, "-"), tools.convertDate(dateF, "-"));

    if (bd.search(sql))
        return (bd.loadSimple(0).toDouble() * commission) / 100;

    return 0;
}

void Employee::clearFilterJobRole()
{
    areFilterJobRole = false;

    setFilter();
}

void Employee::refreshModel()
{
    bd.refreshQueryModel("employee");
}
