#include "dataorder.h"

DataOrder::DataOrder(QObject *parent) :
    QObject(parent)
{
    orderQuantity.clear();
    orderValues.clear();
    orderSizes.clear();
    orderPartProduct.clear();
    orderIdProduct.clear();
    orderNameProduct.clear();
    orderNoteProduct.clear();
}

void DataOrder::print()
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << "orderQuantity" << orderQuantity.length() << orderQuantity;
    qDebug() << "orderValues" << orderValues.length() << orderValues;
    qDebug() << "orderSizes" << orderSizes.length() << orderSizes;
    qDebug() << "orderPartProduct" << orderPartProduct.length() << orderPartProduct;
    qDebug() << "orderIdProduct" << orderIdProduct.length() << orderIdProduct;
    qDebug() << "orderNameProduct" << orderNameProduct.length() << orderNameProduct;
    qDebug() << "orderNoteProduct" << orderNoteProduct.length() << orderNoteProduct;
    qDebug("-------------------------------");
}
