#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>
#include <Abstract/bdtools.h>

class Product : public QObject
{
    Q_OBJECT
public:
    explicit Product(QObject *parent = 0);

public:

    void start(QSqlDatabase *sdb);

    int getIdProduct();
    QString getName();
    QString getNickname();
    QString getNameCategory();
    QString getNameSubCategory();
    QString getNote();
    QList<QString> getSizes();
    QList<QString> getValues();

    void setIdProduct(int idProduct);
    void setName(QString name);
    void setNickname(QString nickname);
    void setIdCategory(QString idCategory);
    void setNameCategory(QString nameCategory);
    void setIdSubCategory(QString idSubCategory);
    void setNameSubCategory(QString nameSubCategory);
    void setNote(QString note);
    void setSizes(QList<QString> listSizes);
    void setValues(QList<QString> listValues);

    bool loadData(int idProduct);

    void clearData();

    void instance(); // terminar


    bool insert();
    bool update(int idProduct);
    bool remove(int idProduct);

    QString countProducts(QString idCategory = "", QString idSubcategory = "");

    void emitCountProducts();

    void setFilter(QString filter);

    void clearFilter();

    void getPrices(); // pelo id do produto ele carrega os valores e os tamanhos para sizes e values para ser carregado na tabela de valores

    QList<QString> getAllCategory();
    QList<QString> getAllSubCategory(QString nameCategory);

protected:
    int idProduct;
    QString name;
    QString nickname;
    QString idCategory;
    QString nameCategory;
    QString idSubCategory;
    QString nameSubCategory;
    QString note;
    QList<QString> listSizes;
    QList<QString> listValues;

public:
    BDTools bd;

signals:
    void count(QString);

protected:
    void getIdCategory();
    void getIdSubCategory();

public slots:
    void refreshModels();

};

#endif // PRODUCT_H
