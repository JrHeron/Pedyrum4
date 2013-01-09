#ifndef LOGIN_H
#define LOGIN_H

#include <QObject>
#include <Abstract/encryption.h>
#include <Abstract/bdtools.h>
#include <Abstract/serial.h>

class Login : public QObject
{
    Q_OBJECT
public:
    explicit Login(QObject *parent = 0);

    void start(QSqlDatabase *sdb);

    bool login(QString username, QString password);

    void loginWithSecretQuestion(QString username, QString secretanswer);

    void logout();

    QString secretQuestion(QString username);

    bool saveSerial(QString serial);

    QString serialBank();

    bool isLocal();

signals:
    void logado(QString, QString, QList<bool>);

public slots:


public:

    Encryption encryption;

    BDTools bd;

    Serial serial;

};

#endif // LOGIN_H
