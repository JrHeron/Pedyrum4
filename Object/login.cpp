#include "login.h"
#include <QDebug>
#include <QMessageBox>

Login::Login(QObject *parent) :
    QObject(parent)
{
}

void Login::start(QSqlDatabase *sdb)
{
    bd.sdb = *sdb;

    // aqui dentro ele já verifica se existe usuário e, caso não exista ele cria um

    if (!bd.search("select * from usersystem")){

        if (!bd.exec("insert into usersystem values(1, 'root', '3114311131113116', 'No primeiro acesso, a senha é root', '3114311131113116')"))
        {
            QString errorMessage = QString(tr("O usuário inicial não pode ser criado.\nErro para informar ao suporte:\n\n%1")).arg(bd.lastError);

            QMessageBox::warning(NULL, tr("Usuário inicial não criado"), errorMessage, QMessageBox::Ok);

            return;
        }

        // como o user inicial é o root do sistema, ele tem acesso a tudo
        bd.exec("insert into accesslevel values(1, 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y')");
    }

    if (! bd.search("select * from statusServer")){

        bd.exec(QString("insert into statusServer values('%1')").arg(encryption.encrypt("false")));

    }

    if (bd.sdb.hostName() == "localhost"){
        qDebug() << "aqui1" << bd.exec(QString("update statusServer set status = '%1'").arg(encryption.encrypt("true")));

    }else{
        qDebug() << "aqui2" << bd.exec(QString("update statusServer set status = '%1'").arg(encryption.encrypt("false")));
    }
}

bool Login::login(QString username, QString password)
{
    QString sql;

    sql = QString("select * from usersystem where username = '%1' and password = '%2'").arg(username, encryption.encrypt(password));

    if (! bd.search(sql)){
        QMessageBox::warning(NULL, ("Dados incorretos"), tr("Dados digitados estão inválidos."), QMessageBox::Ok);

        return false;
    }

    QList<bool> permissions;

    QList<QString> permissionsS;

    sql = QString("select * from accesslevel where iduser = %1").arg(bd.loadSimple(0));

    if (bd.search(sql)){
        permissionsS = bd.loadLine(0);

        foreach(QString p, permissionsS){
            if (p == "true")
                permissions << true;
            else if(p == "false")
                permissions << false;
        }
    }

    emit logado(username, bd.loadSimple(0), permissions);

    return true;
}

void Login::loginWithSecretQuestion(QString username, QString secretanswer){
    QString sql;

    sql = QString("select * from usersystem where username = '%1' and secretanswer = '%2'").arg(username, encryption.encrypt(secretanswer));

    if (! bd.search(sql)){
        QMessageBox::warning(NULL, tr("Dados incorretos"), tr("Reposta secreta está inválida."), QMessageBox::Ok);

        return;
    }else{
        if (bd.exec(QString("update usersystem set password = '%1' where username = '%2'").arg(encryption.encrypt("pedyrum"), username))){

            QMessageBox::information(NULL, tr("Senha resetada"), tr("Resposta correta. Sua senha foi resetada e agora é 'pedyrum' (sem aspas).\nÉ altamente recomendado que se altere essa senha imediatamente."), QMessageBox::Ok);

        }else{
            qDebug() << "'senha não mudada'";

            qDebug() << QString("update usersystem set password = '%1'' where username = '%2'").arg(encryption.encrypt("pedyrum"), username);
        }

        QList<bool> permissions;

        QList<QString> permissionsS;

        sql = QString("select * from accesslevel from where iduser = %1").arg(bd.loadSimple(0));

        if (bd.search(sql)){
            permissionsS = bd.loadLine(0);

            foreach(QString p, permissionsS){
                if (p == "true")
                    permissions << true;
                else if(p == "false")
                    permissions << false;
            }
        }

        emit logado(username, bd.loadSimple(1), permissions);
    }
}

void Login::logout()
{
}

QString Login::secretQuestion(QString username)
{
    QString sql = QString("select secretquestion from usersystem where username = '%1'").arg(username);

    if (bd.search(sql))
        return bd.loadSimple(0);

    QMessageBox::warning(NULL, tr("Username não encontrado"), tr("Nome de usuário \"%1\" não cadastrado.").arg(username), QMessageBox::Ok);

    return "";
}

bool Login::saveSerial(QString serial)
{
    QString sql = QString("insert into buyaccess values('%1')").arg(encryption.encrypt(serial));

    return bd.exec(sql);
}

QString Login::serialBank()
{
    if (bd.search("select * from buyaccess"))
        return encryption.decrypt(bd.loadSimple(0));

    return "";
}

bool Login::isLocal()
{
    if (bd.sdb.hostName() == "localhost")
        return true;

    return false;

}
