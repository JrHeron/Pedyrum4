#ifndef ITEMDESK_H
#define ITEMDESK_H

#include <QWidget>
#include <Component/label.h>
#include <Interface/Table/dataitem.h>
#include <QList>

typedef unsigned short int usint;

class ItemDesk : public QWidget
{
    Q_OBJECT
public:

    enum states{
        COMPOUND = 0,
        FATHER = 1,
        CHILDREM = 2,
        FREE = 3,
        MEDIA = 4
    };

    explicit ItemDesk(QWidget *parent = 0, QString name = tr("Mesa"), int number = 0);

    void createComponent();

    void connections();

    void adjustLayout();

    void resizeEvent(QResizeEvent *);

    void input();

    void setNumber(int number);

    void setFree(bool b);

    void setCompoundColor(bool b);

signals:        
    void onClick(int index);
    void onDoubleClicked(int index);
    void groupVisible(bool b,QList<int> list);

private slots:
    void onClickItem();
    void onDoubleClickItem();
    void onMouseFocus(bool b);

public slots:    
    void setFather(bool b);
    void setChildren(bool b);
    void setCompound(bool b);
    void setHover(bool b);

    states isType();

public:

    DataItem *data;

    short int _id;

    states getState();

public:
    Label *lBackground;
    Label *lFather;
    Label *lCompoud;
    Label *lChild;
    Label *lNumber;

};

#endif // ITEMDESK_H
