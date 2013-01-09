#ifndef DELIVERYINTERFACE_H
#define DELIVERYINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <Component/edit.h>
#include <Component/label.h>
#include <QStackedWidget>
#include <QTextBrowser>
#include <Component/combobox.h>
#include <Component/search.h>
#include <Component/tableview.h>
#include <QCheckBox>
#include <Abstract/graphiceffects.h>
#include <Abstract/datamodel.h>
#include <QPropertyAnimation>
#include <QDebug>
#include <Object/order.h>
#include <QMessageBox>
#include <Interface/pizzamixed.h>
#include <Component/doublespinbox.h>
#include <Component/spinbox.h>
#include <Component/phoneedit.h>
#include <QKeyEvent>
#include <Abstract/tools.h>
#include <QAction>
#include <Object/makehtml.h>

class DeliveryInterface : public QWidget
{
    Q_OBJECT

public:
    explicit DeliveryInterface(QWidget *parent = 0);

    void createComponent();
    void statics();
    void connections();

    void resizeEvent(QResizeEvent *);

    void setPreview();
    void setPreview(QString nome, float value, int quant);

    void showNotesClient(bool b);
    void showNotesProduct(bool b);

    void updateValues();

    void clearOrder();
    
signals:
    void editPizzaMixed(QList<int> listOrderPartProduct, QList<QString> listOrderIdProduct, QList<QString> listOrderNameProduct, QString note, int quantity, double value, QString size, int row);

    void setInput();

    void newOrder();
    
    void fullScreen();

public slots:
    void input();
    void adjustLayout();
    void editOrder(int idOrder);

private:
    bool isAvailable();

    bool isAvailableBusiness();

private slots:

    void keyPressEvent(QKeyEvent *event);

    void onClick_pbSelectPeople();
    void onClick_pbSelectBusiness();            
    void onClick_pbLeaveClient();    //clear & cancel
    void onClick_lPizza();
    void onClick_pbConfirmProduct();  //add & save
    void onClick_pbLeaveProduct();    //clear & cancel,    
    void onClick_pbSaveOrdered();
    void onClick_pbRemoveItem();
    void onClick_pbClearOrdered();
    void onClick_pbCancelOrdered();
    void onClick_pbNumberPayment();
    void onClick_pbAddPaymentForm();
    void onClick_pbRemovePaimentForm();

    void onClick_lNoteClient();
    void onClick_lNoteProduct();

    void hideFinishedClient();
    void hideFinishedProduct();

    void onClick_lSchedule();

    void onTextChanged_ePhone(QString text);
    void onTextChanged_ePhoneBusiness(QString text);

    void onTextChanged_eCep(QString text);
    void onTextChanged_eCepBusiness(QString text);

    void getSearchProduct(QString text);

    void valueChanged_sbAmount(int value);

    void currentIndexChanged_cbSize(int index);

    void doubleClicked_tableItem(QModelIndex index);

    void valueChanged_dsbDeliveryRate(double value);

    void valueChanged_dsbPaid(double value);

    void slotPizzaMista(QList<int> listOrderPartProduct, QList<QString> listOrderIdProduct, QList<QString> listOrderNameProduct, QString note, int quantity, double value, QString size, bool insert, int row);

    void onTriggered_actionName();

    void onTriggered_actionNickName();

    void loadDataOrder();

    void valueChanged_DSBValueProduct(double);
public:
    bool bogth;

    bool isAdd;

    bool isNoteClient;
    bool isNoteProduct;

    short int wScheduleX;
    bool isSchedule;

    QWidget *wClient;
    QLabel * lClient;

    QPushButton *pbSelectPeople;
    QPushButton *pbSelectBusiness;

    QStackedWidget *swSelectClient;

    QWidget *wSelectPeople;
    QWidget *wSelectBusiness;

    phoneEdit *ePhone;
    Edit *eCep;
    Edit *eName;
    Edit *eStreet;
    Edit *eNumber;
    Edit *eComplement;
    Edit *eDistrict;

    phoneEdit *ePhoneBusiness;
    Edit *eCepBusiness;
    Edit *eNameContactBusiness;
    Edit *eNameBusiness;
    Edit *eFantasyNameBusiness;
    Edit *eCNPJBusiness;
    Edit *eStreetBusiness;
    Edit *eNumberBusiness;
    Edit *eComplementBusiness;
    Edit *eDistrictBusiness;

    QPushButton *pbLeaveClient;

    QWidget *wProduct;
    QLabel * lProduct;

    Search *searchProduct;
    QTextBrowser *productPreview;
    DoubleSpinBox *DSBValueProduct;
    ComboBox *cbSize;
    SpinBox *sbAmount;
    Label *lPizza;

    QPushButton *pbConfirmProduct;  //add & save
    QPushButton *pbLeaveProduct;    //clear & cancel,

    QWidget *wItens;
    QLabel *lItens;

    QPushButton *pbSaveOrdered;
    QPushButton *pbRemoveItem;
    QPushButton *pbClearOrdered;
    QPushButton *pbCancelOrdered;
    TableView *tableItem;

    QWidget *wValues;
    QLabel *lValues;
    QLabel *lValuesField;
    QStackedWidget *swValuesFields;

    QWidget *wValuesFields;
    QWidget *wPaymentForm;

    QPushButton *pbNumberPayment;
    QLabel *lSubtotalOrdered;
    DoubleSpinBox *DSBShipping;
    QLabel *lTotalOrdered;
    QCheckBox *isPaid;
    DoubleSpinBox * DSBPaid;
    QLabel *lTransshipment;

    QLabel *lPaymentFormTotal;
    ComboBox *cbPaymentForm;
    DoubleSpinBox *DSBValuePaymentForm;
    QPushButton *pbAddPaymentForm;
    QPushButton *pbRemovePaymentForm;
    TableView *tablePaymentForm;

    Label *lNoteClient;
    Label *lNoteProduct;

    QWidget *wProductNotes;
    QLabel *lProductNotes;
    QLabel *lTextNotesProduct;
    QTextEdit *teProductNotes;

    QWidget *wClientNotes;
    QLabel *lClientNotes;
    QLabel *lTextNotesClient;
    QTextEdit *teClientNotes;

    GraphicEffects *transition;
    QPropertyAnimation *hide;
    QPropertyAnimation *show;

    Label * lSchedule;
    QLabel * lScheduleBg;
    QWidget *wSchedule;
    Edit *eDateDelivery;
    Edit *eHourDelivery;

    int typeClient;

    Order *order;

    QList<QString> listSizes, listValues;
    QString productName;

    DataModel *dataModelItems;
    DataModel *dataModelPayment;

    QList<QString> dataClientI;
    QList<QString> dataClientF;

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

    int idClient;

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

    Tools tools;

    enum{
        NORMAL = 1,
        BUSINESS = 2
    };

    PizzaMixed *wPizzaMixed;

    MakeHTML html;


};

#endif // DELIVERYINTERFACE_H
