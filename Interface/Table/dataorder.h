#ifndef DATAORDER_H
#define DATAORDER_H

#include <QObject>
#include <QDebug>

class DataOrder : public QObject
{
    Q_OBJECT
public:
    explicit DataOrder(QObject *parent = 0);

    QList<int> orderQuantity;
    QList<double> orderValues;
    QList<QString> orderSizes;
    QList<QList<int> > orderPartProduct;
    QList<QList<QString> > orderIdProduct;
    QList<QList<QString> > orderNameProduct;
    QList<QString> orderNoteProduct;

    void print();

signals:

public slots:

};

#endif // DATAORDER_H
