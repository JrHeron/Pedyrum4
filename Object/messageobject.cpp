#include "messageobject.h"

MessageObject::MessageObject(QObject *parent) :
    QObject(parent)
{

}

void MessageObject::setText(QString text)
{
     textBody = text;
}

void MessageObject::setTitle(QString text)
{
    titleAlert = text;
}

void MessageObject::setImage(QString image)
{
    urlImage = image;
}

void MessageObject::setDelay(int mseg)
{
    timeShow = mseg;
}

QString MessageObject::text()
{
    return textBody;
}

QString MessageObject::title()
{
    return titleAlert;
}

QString MessageObject::image()
{
    return urlImage;
}

int MessageObject::delay()
{
    return timeShow;
}
