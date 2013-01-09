#ifndef BILL_H
#define BILL_H

#include <QObject>
#include <Abstract/bdtools.h>
#include <Abstract/tools.h>

class Bill : public QObject
{
    Q_OBJECT
public:
    explicit Bill(QObject *parent = 0);

    void start(QSqlDatabase *sdb);

public:
    int idBill;
    QString name;
    float value;
    QString type;
    QString status;
    QString dateExpiration;
    QString datePayment;
    QString note;


    bool loadData(int id);

    bool instance();

    bool insert(); // ele pega todos os dados da classe e faz o insert no BD
    bool update(int id); // manda o id aqui, ele faz o load com tds os dados
    bool remove(int id);

    QString countBills();

    void emitCountBills();

    void getTotalValue();

    void setFilter();
    void setFilter(QString filter);
    void setFilterTime(QString dateI, QString dateF);

    void clearFilter();

    bool areFilterTime;
    QString filterTime;
    void getBillsDays();
    void getBillsWeek();
    void getBillsMonth();
    void getBillsYear();
    void getBillsCustom(QString dateI, QString dateF);

    bool areFilterType;
    QString filterType;

protected:

signals:
    void count(QString);
    void totalValue(QString);

public:
    BDTools bd;
    Tools tools;

    QString dateIFilter;
    QString dateFFilter;

public slots:
    void refreshModel();

};

#endif // BILL_H
