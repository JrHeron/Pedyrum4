#ifndef COUNTERINTERFACE_H
#define COUNTERINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <Interface/paymentview.h>
#include <Component/tableview.h>
#include <QPushButton>
#include <Component/label.h>
#include <Component/search.h>
#include <QTextBrowser>
#include <Object/order.h>
#include <Abstract/datamodel.h>
#include <Interface/pizzamixed.h>
#include <QKeyEvent>
#include <QAction>
#include <Object/makehtml.h>

class CounterInterface : public QWidget
{
    Q_OBJECT
public:
    explicit CounterInterface(QWidget *parent = 0);
    void createComponent();
    void resizeEvent(QResizeEvent *);
    void statics();
    void connections();

    void setPreview();
    void setPreview(QString nome, float value, int quant);

    void updateValues();
    
    void clearOrder();

    Order *order;

    PizzaMixed *wPizzaMixed;

    PaymentView *wPaymentView;

    bool isAvailable();

    bool isAvailableBusiness();

signals:
    void newOrder();

    void setInput();

    void editPizzaMixed(QList<int> listOrderPartProduct, QList<QString> listOrderIdProduct, QList<QString> listOrderNameProduct, QString note, int quantity, double value, QString size, int row);
    
    void fullScreen();

public slots:
    void input();
    void adjustLayout();

    void onClick_lPizza();

    void onClick_pbConfirmProduct();

    void onClick_pbLeaveProduct();

    void slotPizzaMista(QList<int> listOrderPartProduct, QList<QString> listOrderIdProduct, QList<QString> listOrderNameProduct, QString note, int quantity, double value, QString size, bool insert, int row);

    void getSearchProduct(QString text);

    void doubleClicked_tableItem(QModelIndex index);

    void valueChanged_sbAmount(int value);

    void currentIndexChanged_cbSize(int index);

    void onClick_pbRemoveItem();

    void onClick_pbClearOrdered();

    void onClick_pbCancelOrdered();

    void onClick_pbSaveOrdered();

    void keyPressEvent(QKeyEvent *event);

    void onTriggered_actionName();

    void onTriggered_actionNickName();

    void editOrder(int idOrder);

    void loadDataOrder();

    void valueChanged_DSBValueProduct(double value);

private:

    bool bogth;

   QWidget *wProduct;
   QLabel * lProduct;

   Search *searchProduct;   
   QTextBrowser *productPreview;
   ComboBox *cbSize;
   DoubleSpinBox *DSBValueProduct;
   SpinBox *sbAmount;
   Label *lPizza;

   QPushButton *pbConfirmProduct;  //add & save
   QPushButton *pbLeaveProduct;    //clear & cancel,

   QWidget *wProductNotes;
   QLabel *lProductNotes;
   QLabel *lTextNotesProduct;
   QTextEdit *teProductNotes;

   QWidget *wItens;
   QLabel *lItens;

   QPushButton *pbSaveOrdered;
   QPushButton *pbRemoveItem;
   QPushButton *pbClearOrdered;
   QPushButton *pbCancelOrdered;
   TableView *tableItem;

   DataModel *dataModelItems;

   /// dados do pedido

   QList<QString> listSizes, listValues;
   QString productName;

   // dados do produto atualmente selecionado
   QString dataOrderIdProduct;
   QString dataOrderNameProduct;
   QString dataOrderSizeProduct;
   double dataOrderValueProduct;
   int dataOrderQntProduct;
   QString dataOrderNoteProduct;

   double totalValueOrder;
   double totalValueOrderProducts;

   QList<QString> listOrderIdProduct;
   QList<QString> listOrderNameProduct;
   QList<QString> listOrderSizeProduct;
   QList<QString> listOrderValueProduct;
   QList<QString> listOrderQntProduct;
   QList<QString> listOrderNoteProduct;

   int indexSelectedItem;

   // tratamento dos itens
   QList<int> orderQuantity;
   QList<double> orderValues;
   QList<QString> orderSizes;
   QList<QList<int> > orderPartProduct;
   QList<QList<QString> > orderIdProduct;
   QList<QList<QString> > orderNameProduct;
   QList<QString> orderNoteProduct;

   QAction *actionName;
   QAction *actionNickName;

public:

   MakeHTML html;

   bool isAdd;
};

#endif // COUNTERINTERFACE_H
