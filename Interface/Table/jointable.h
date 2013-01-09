#ifndef JOINTABLE_H
#define JOINTABLE_H

#include <QWidget>
#include <Component/tableview.h>
#include <Component/spinbox.h>
#include <QSpinBox>
#include <Abstract/datamodel.h>
#include <QPushButton>
#include <QList>
#include <QKeyEvent>
#include <QComboBox>
#include <QMap>
#include <Interface/Table/dataitem.h>
#include <QLabel>

typedef unsigned short int usint;

class JoinTable : public QWidget
{
    Q_OBJECT
public:
    explicit JoinTable(QWidget *parent = 0);

    void createComponent();

    void input();

    void connections();

    void adjustLayout();

    void resizeEvent(QResizeEvent *);

signals:
    void back();    
    void updateData(int index, bool expor);

public slots:    

    void keyPressEvent(QKeyEvent *event);

    void onClick_pbAdd();

    void onClick_pbRemove();

    void onClick_pbBack();

    void onClick_pbSave();

    void load(int index);

    bool verification(int newtable);

    bool addingDouble(int newtable);

private:
    usint selected() const {return _selected;}

public:

    DataItem *_data[100];
    usint _selected;

    SpinBox *SBTable;
    QPushButton *pbAdd;

    TableView *tables;
    QPushButton *pbRemove;

    DataModel *model;
    QList<int> tempList;

    QPushButton *pbBack;
    QPushButton *pbSave;

    QLabel *lTextMesa;
};

#endif // JOINTABLE_H
