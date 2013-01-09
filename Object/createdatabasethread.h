#ifndef CREATEDATABASETHREAD_H
#define CREATEDATABASETHREAD_H

#include <QThread>
#include <Abstract/bdtools.h>
#include <Abstract/encryption.h>

class CreateDatabaseThread : public QThread
{
    Q_OBJECT
public:
    explicit CreateDatabaseThread(QObject *parent = 0);

    void setDatabase(QString dbName);

    void setSqlDatabase(QString sqlDatabase);

    void setSqlProcedure(QString sqlProcedure);

public: // VARIABLES
    QString dbName;

    QString driver;

    QSqlDatabase sdb;

    QString sqlDatabase;

    QString sqlProcedure;

private:
    BDTools bd;

    Encryption encryption;

signals:

public slots:
    void createDatabase();

signals:
    void databaseCreated(bool = true, QString = "");

    void tablesCreated(bool = true, QString = "");

    void proceduresCreated(bool = true, QString = "");

    void allCreated();
};

#endif // CREATEDATABASETHREAD_H
