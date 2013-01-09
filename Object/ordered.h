#ifndef ORDERED_H
#define ORDERED_H

#include <QObject>
#include <Abstract/bdtools.h>
#include <Abstract/tools.h>

class Ordered : public QObject
{
    Q_OBJECT
public:
    explicit Ordered(QObject *parent = 0);

    void start(QSqlDatabase *sdb);

    bool instance();

    void changeStatusOrder(QString id, QString status);

    void changeStatusEmployee(int id, QString status);

    bool remove(QString idOrder);

    BDTools bd;

    Tools tools;

signals:

public slots:

    void refreshModel();

};

#endif // ORDERED_H
