#ifndef PIZZA_H
#define PIZZA_H

#include <QObject>
#include <Abstract/bdtools.h>

class Pizza : public QObject
{
    Q_OBJECT
public:
    explicit Pizza(QObject *parent = 0);

    void start(QSqlDatabase *sdb);

    BDTools bd;

public:

protected:
    void instance();

private:


signals:

public slots:
    void refreshModels();

};

#endif // PIZZA_H
