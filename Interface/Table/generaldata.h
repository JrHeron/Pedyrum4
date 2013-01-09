#ifndef GENERALDATA_H
#define GENERALDATA_H

#include <QObject>
#include <Interface/Table/dataitem.h>
#include <Abstract/datamodel.h>
#include <Interface/Table/dataorder.h>

typedef unsigned short int usint;

class GeneralData : public QObject
{
    Q_OBJECT
public:

//    struct DataOrder{
//        QList<int> orderQuantity;
//        QList<double> orderValues;
//        QList<QString> orderSizes;
//        QList<QList<int> > orderPartProduct;
//        QList<QList<QString> > orderIdProduct;
//        QList<QList<QString> > orderNameProduct;
//        QList<QString> orderNoteProduct;
//    };

    explicit GeneralData(QObject *parent = 0);
    void createComponent();

    void input(); // prepara os model vazios, já com cabecalhos

    DataModel *getModelItems(usint index);
    void setModelItems(usint index, DataModel *model);

    DataModel *getModelPayment(usint index);
    void setModelPayment(usint index, DataModel *model);

    DataOrder *getDataOrder(usint index);
    void setDataOrder(usint index, DataOrder *dataOrder);

    DataItem *getDataItem(usint index);

    usint EMPTY_MODEL;

    void clearDataOrder(usint index);

signals:
    void updateData();

public slots:

public:
    DataItem *_dataItem[100];
    DataModel *_modelItems[100];
    DataModel *_modelPayment[100];
    DataOrder *_dataOrder[101];
};

#endif // GENERALDATA_H
