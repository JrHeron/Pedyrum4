#ifndef DEBUG_H
#define DEBUG_H

#include <QObject>
#include <QDebug>

class Debug : public QObject
{
    Q_OBJECT
public:
    explicit Debug(QObject *parent = 0);

    void debug(QString text);

signals:

public slots:

};

#endif // DEBUG_H
