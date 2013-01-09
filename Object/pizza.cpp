#include "pizza.h"

Pizza::Pizza(QObject *parent) :
    QObject(parent)
{
}

void Pizza::start(QSqlDatabase *sdb){
    bd.sdb = *sdb;

    instance();
}

void Pizza::instance()
{
    bd.createModelQuery("product", "select * from product order by idProduct");

    bd.createCompleter("product", "product", 1, false, QCompleter::PopupCompletion, BDTools::QueryModel);
}

void Pizza::refreshModels()
{
    bd.refreshQueryModel("product");
}
