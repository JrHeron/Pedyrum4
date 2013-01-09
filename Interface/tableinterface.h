#ifndef TABLEINTERFACE_H
#define TABLEINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <Interface/paymentview.h>
#include <Component/tableview.h>
#include <QPushButton>
#include <Object/order.h>
#include <Abstract/datamodel.h>
#include <Interface/Table/groupdesk.h>

class TableInterface : public QWidget
{
    Q_OBJECT
public:
    explicit TableInterface(QWidget *parent = 0);
    void createComponent();
    void resizeEvent(QResizeEvent *);

signals:
    void setInput();

    void saveOrder();

    void removeProduct(usint index);

    void removeAllProducts();

    void clearOrder();

public slots:
    void input();
    void adjustLayout();
    void connections();

    void onClick_pbSaveOrdered();

    void onClick_pbRemoveItem();

    void onClick_pbClearOrdered();

    void onClick_pbCancelOrdered();

    void doubleClicked_tableItem(QModelIndex index);

public:

    PaymentView *wPaymentView;

    Order *order;

    GroupDesk *wGroupDesk;
private:

    QWidget *wItens;
    QLabel *lItens;

    QPushButton *pbSaveOrdered;
    QPushButton *pbRemoveItem;
    QPushButton *pbClearOrdered;
    QPushButton *pbCancelOrdered;


    TableView *tableItem;


};

#endif // TABLEINTERFACE_H
