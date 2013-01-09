#include "tableview.h"
#include <QHeaderView>
#include <QDebug>

TableView::TableView(QWidget *parent) :
    QTableView(parent)
{
    setConfig();
}

void TableView::currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    emit rowChanged(this->currentIndex().row());
}

void TableView::setConfig()
{
    scroolWidth = 16;

    this->setFrameStyle(0);

    QHeaderView *headerV = new QHeaderView(Qt::Vertical);
    headerV->setDefaultSectionSize(22);
    headerV->setVisible(false);

    this->setVerticalHeader(headerV);
    this->setSelectionMode(SingleSelection);
    this->setSelectionBehavior(SelectRows);
    this->setAlternatingRowColors(true);
    this->setEditTriggers(NoEditTriggers);
    this->setSortingEnabled(false);
    this->setFrameStyle(0);

}

void TableView::setColumnsHidden(QList<int> columns)
{
    for (int column = 0; column < columns.count(); ++column)
    {
        setColumnHidden(columns.value(column),true);
    }
}
