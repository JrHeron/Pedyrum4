#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableView>
#include <QList>

class TableView : public QTableView
{
    Q_OBJECT
public:
    explicit TableView(QWidget *parent = 0);
    void currentChanged(const QModelIndex &current, const QModelIndex &previous);
    void setConfig();
    void setColumnsHidden(QList<int> columns);

signals:
    void rowChanged(int current);

public slots:

private:

    QList<float> columnsWidth;
    short int scroolWidth;

};

#endif // TABLEVIEW_H
