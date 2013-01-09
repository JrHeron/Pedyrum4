#ifndef MOVEMENTCASH_H
#define MOVEMENTCASH_H

#include <QObject>
#include <Abstract/bdtools.h>
#include <Abstract/tools.h>

class MovementCash : public QObject
{
    Q_OBJECT
public:
    explicit MovementCash(QObject *parent = 0);

    bool instance();

    void start(QSqlDatabase *sdb);

    bool insert();
    bool update(int id);
    bool remove(int id);

    QString countMovementCash();

    void emitCountMovementCash();

    void getTotalValue();

    void clearFilter();

    bool canOpenCash();

    bool canCloseCash();

    QString valueCloseBox(QString date, QString time);

    Tools tools;

    void setFilter();
    void setFilter(QString filter);
    void setFilterTime(QString dateI, QString dateF);

    bool areFilterTime;
    QString filterTime;
    void getCashDays();
    void getCashWeek();
    void getCashMonth();
    void getCashYear();
    void getCashCustom(QString dateI, QString dateF);

    bool areFilterType;
    QString filterType;

    inline QSqlTableModel *model(); // para facilitar o trabalho com model

signals:
    void count(QString);
    void totalValue(QString);

public:
    int idMovement;
    float value;
    QString type;
    QString date;
    QString hour;
    QString note;

    BDTools bd;

    QString dateIFilter;
    QString dateFFilter;

public slots:
    void refreshModel();

};

#endif // MOVEMENTCASH_H
