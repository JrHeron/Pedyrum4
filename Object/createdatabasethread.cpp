#include "createdatabasethread.h"
#include <QMessageBox>
#include <QDebug>

CreateDatabaseThread::CreateDatabaseThread(QObject *parent) :
    QThread(parent)
{
}

void CreateDatabaseThread::setDatabase(QString dbName)
{
    this->dbName = dbName;
}

void CreateDatabaseThread::setSqlDatabase(QString sql){
    this->sqlDatabase = sql;
}

void CreateDatabaseThread::setSqlProcedure(QString sqlProcedure){
    this->sqlProcedure = sqlProcedure;
}

void CreateDatabaseThread::createDatabase()
{
    bd.start("", "createDatabase");

    if (bd.exec(QString("create database %1").arg(dbName))){

        qDebug() << "[CREATE DATABASE] Banco criado";

        databaseCreated();

        bd.sdb.close();

        bd.start(dbName, "createDatabase");

        if (bd.exec(sqlDatabase)){

            qDebug() << "[CREATE DATABASE] tabelas criadas";

            tablesCreated();

            if (bd.exec(sqlProcedure)){

                qDebug() << "[CREATE DATABASE] procedures criadas";

                emit allCreated();

            }else{

                qDebug() << "[CREATE DATABASE] procedures não criadas" << bd.lastError;

                emit proceduresCreated(false, bd.lastError);
            }

        }else{

            qDebug() << "[CREATE DATABASE] tabelas não criadas" << bd.lastError;

            emit tablesCreated(false, bd.lastError);
        }

    }else{
        qDebug() << "[CREATE DATABASE] Banco não criado" << bd.lastError;

        emit databaseCreated(false, bd.lastError);
    }
}
