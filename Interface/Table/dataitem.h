#ifndef DATAITEM_H
#define DATAITEM_H

#include <QObject>
#include <QList>

class DataItem : public QObject
{
    Q_OBJECT
public:
    explicit DataItem(QObject *parent = 0);

    /// --------- Transferir Conta ---------

    void setFather(int father);
    void setChildren(int children);
    int father();
    int children();
    bool isFather();
    bool isChildren();
    void clearTransfer();

    /// --------- Mesa Composta ---------

    bool isCompound();
    void setCompound(bool b);
    void setCompound(QList<int> indexs);
    QList<int> listCompound();
    void clearCompound();

    /// --------- Propriedades ---------

    void setId(int index);
    int id();

    void setFree(bool b);
    bool isFree();

    void setBartender(int idbartender);
    int bartender();

    double value();

    void setValueSimple(double value);

    void setValueComplex(double value); // valor considerando tds as mesas ligadas a ela

    bool isSimple();

    /// --------- Média ---------

    void setMedia(int countPeople);
    bool isMedia();
    double media();
    int countPeople();

    /// --------- reset values ---------

    void resetValues();


signals:

public slots:

public:

    /// --------- Transferir Conta ---------

    int _father;
    int _children;
    bool _isFather;
    bool _isChildren;

    /// --------- Mesa Composta ---------

    bool _isCompound;
    QList<int> _listCompound;

    /// --------- Propriedades ---------

    int _id;
    bool _isFree;
    int _idBartender;
    double _valueSimple;
    double _valueComplex;

    /// --------- Média ---------

    bool _isMedia;
    double _media;
    short int _countPeople;

};

#endif // DATAITEM_H
