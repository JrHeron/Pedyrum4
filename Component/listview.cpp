#include "listview.h"

ListView::ListView(QWidget *parent) :
    QListView(parent)
{
    this->setAlternatingRowColors(true);
    this->setSpacing(2);
    this->setIconSize(QSize(40,40));
    this->setFrameStyle(QFrame::NoFrame);
}

QList<QString> ListView::listValues()
{
    return  listItens;
}

bool ListView::ModelToList()
{
    if(this->model()->rowCount() > 0)
    {
        qDebug("[ListView] [bool ListView::ModelToList(int column)] O model está vázio.");
        return false;
    }

    listItens.clear();

    for (int index = 0; index < this->model()->rowCount(); ++index)
    {
        listItens << this->model()->index(index,this->modelColumn()).data().toString();
    }

    return true;
}
