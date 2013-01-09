#ifndef LISTVIEW_H
#define LISTVIEW_H

#include <QListView>
#include <QList>

class ListView : public QListView
{
    Q_OBJECT
public:
    explicit ListView(QWidget *parent = 0);

    bool ModelToList();

    QList<QString> listValues();

signals:

public slots:

private:

    QList<QString> listItens;

};

#endif // LISTVIEW_H
