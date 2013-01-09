#ifndef MESSAGEOBJECT_H
#define MESSAGEOBJECT_H

#include <QObject>

class MessageObject : public QObject
{
    Q_OBJECT
public:
    explicit MessageObject(QObject *parent = 0);

signals:

public slots:

    void setText(QString text);

    void setTitle(QString text);

    void setImage(QString image);

    void setDelay(int mseg);

    QString text();

    QString title();

    QString image();

    int delay();

private:
    QString textBody;
    QString titleAlert;
    QString urlImage;
    int timeShow;

};

#endif // MESSAGEOBJECT_H
