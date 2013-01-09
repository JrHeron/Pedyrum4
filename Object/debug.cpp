#include "debug.h"

Debug::Debug(QObject *parent) :
    QObject(parent)
{
}

void Debug::debug(QString text)
{
    qDebug() << text;
}
