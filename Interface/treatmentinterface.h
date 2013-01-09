#ifndef TREATMENTINTERFACE_H
#define TREATMENTINTERFACE_H

#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include <Interface/deliveryinterface.h>
#include <Interface/counterinterface.h>
#include <Interface/tableinterface.h>
#include <QKeyEvent>

class TreatmentInterface : public QWidget
{
    Q_OBJECT
public:
    explicit TreatmentInterface(QWidget *parent = 0);
    void createComponent();    
    void resizeEvent(QResizeEvent *);
    void connections();

    void setIdOrderEdit(int type, int id);

public:
    int idOrderEdit;

signals:
    void setInput();
    void toPanel(int index);
    void editOrder(int type, int idOrder);

    void fullScreen();

    void goToPanel(int);
    
public slots:
    void adjustLayout();
    void input();

    void keyPressEvent(QKeyEvent *event);

    void onClick_pbDelivery();
    void onClick_pbTable();
    void onClick_pbCounter();
    void onClick_pbOrdered();

    void logout();

public:
    DeliveryInterface * wDelivery;
    CounterInterface *wCounter;
    TableInterface *wTable;


    QPushButton * pbDelivery;
    QPushButton * pbTable;
    QPushButton * pbCounter;
    QPushButton * pbOrdered;

    QStackedWidget *swPanel;

    QLabel *lBackground;
};

#endif // TREATMENTINTERFACE_H
