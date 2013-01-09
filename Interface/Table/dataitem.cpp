#include "dataitem.h"
#include <QDebug>

DataItem::DataItem(QObject *parent) :
    QObject(parent)
{
    resetValues();

    _id = -1;
}

/// --------- Transferir Conta ---------

void DataItem::setFather(int father) {
    _father = father;
    _isChildren = true;
    _isFather = false;
}

void DataItem::setChildren(int children) {
    _children = children;
    _isChildren = false;
    _isFather = true;
}

int DataItem::father() { return _father; }

int DataItem::children() { return _children; }

bool DataItem::isFather() { return _isFather; }

bool DataItem::isChildren() { return _isChildren; }

/// --------- Mesa Composta ---------

void DataItem::setCompound(bool b) { _isCompound = b; }

void DataItem::setCompound(QList<int> indexs) { _listCompound = indexs; _isCompound = true;}

bool DataItem::isCompound() { return _isCompound; }

/// --------- Propriedades ---------

void DataItem::setId(int index) { _id = index; }

int DataItem::id() { return _id; }

void DataItem::setFree(bool b) { _isFree = b; }

bool DataItem::isFree() { return _isFree; }

void DataItem::setBartender(int idbartender) { _idBartender = idbartender; }

int DataItem::bartender() { return _idBartender; }

void DataItem::setValueSimple(double value) {_valueSimple = value;}

void DataItem::setValueComplex(double value) {_valueComplex = value;}

/// --------- Média ---------

void DataItem::setMedia(int people)
{
    _countPeople = people;
    _media = _valueSimple/_countPeople;
    _isMedia = true;
}

bool DataItem::isMedia() { return _isMedia; }

double DataItem::media() { return _media; }

int DataItem::countPeople() { return _countPeople; }

double DataItem::value() { return _valueSimple; }

QList<int> DataItem::listCompound() { return _listCompound; }

void DataItem::resetValues()
{
    _father = -1;
    _children = -1;
    _isFather = false;
    _isChildren = false;

    _isCompound = false;
    _listCompound.clear();

    _isFree = true;
    _idBartender = -1;
    _valueSimple = 0.00;

    _isMedia = false;
    _countPeople = 1;
    _media = 0.00;
}

void DataItem::clearTransfer()
{
    _father = -1;
    _children = -1;
    _isFather = false;
    _isChildren = false;
}

void DataItem::clearCompound()
{
    _isCompound = false;
    _listCompound.clear();
}

bool DataItem::isSimple()
{
    if(isFather())
        return false;

    if(isChildren())
        return false;

    if(isCompound())
        return false;

    if (isMedia())
        return false;

    return true;
}
