#include "encryption.h"
#include <QDebug>

Encryption::Encryption(QObject *parent) :
    QObject(parent)
{
}

QString Encryption::encrypt(QString text){
    QString textReturn = "";
    foreach(QString letter, text){
        textReturn += QString::number(QString::number(letterToAscii(letter)).length());
        textReturn += QString::number(letterToAscii(letter));
    }

    return textReturn;
}

QString Encryption::decrypt(QString text){
    QString textReturn = "";
    int i = 0;

    QString ascii;
    int qnt;
    while (i < text.length()){
        qnt = text.mid(i, 1).toInt();
        ascii = text.mid(i+1, qnt);
        textReturn += asciiToLetter(ascii.toInt());
        i += qnt + 1;
    }

    return textReturn;
}

QString Encryption::encryptWithoutBack(QString text){
    QString textReturn = "";
    int count = 0;
    foreach(QString letter, text){
        if (count % 2 == 0)
            for (int i = 0; i < QString::number(letterToAscii(letter)).length(); i++)
                textReturn += QString::number(letterToAscii(letter))[QString::number(letterToAscii(letter)).length() - 1 - i];
        else
            textReturn += QString::number(letterToAscii(letter));
    }

    return textReturn;
}

int Encryption::letterToAscii(QString letter){
    QChar c = letter.at(0).toAscii();
    return (int)c.toAscii();
}

QString Encryption::asciiToLetter(int ascii){
    char asciiChar = (char)ascii;
    return QString::fromAscii(&asciiChar).mid(0,1);
}
