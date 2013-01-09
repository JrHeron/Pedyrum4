#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <QObject>

class Encryption : public QObject
{
    Q_OBJECT
public:
    explicit Encryption(QObject *parent = 0);

    QString encrypt(QString text);

    QString decrypt(QString text);

    QString encryptWithoutBack(QString text); // criptografia para coisas como senha, para evitar que tenha volta e peguem a senha

    int letterToAscii(QString letter);

    QString asciiToLetter(int ascii);

signals:

public slots:

};

#endif // ENCRYPTION_H
