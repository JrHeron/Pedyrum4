#ifndef GROUPDESK_H
#define GROUPDESK_H

#include <QWidget>
#include <Component/label.h>
#include <QPropertyAnimation>
#include <Abstract/graphiceffects.h>
#include <Interface/Table/itemdesk.h>
#include <Interface/Table/treatmenttable.h>
#include <Interface/Table/transfer.h>
#include <Interface/Table/media.h>
#include <Interface/Table/jointable.h>
#include <Interface/Table/generaldata.h>
#include <Interface/paymentview.h>
#include <QList>
#include <QStackedWidget>
#include <QKeyEvent>
#include <Component/tableview.h>
#include <Interface/Table/dataorder.h>

typedef unsigned short int usint;

class GroupDesk : public QWidget
{
    Q_OBJECT

public:
    explicit GroupDesk(QWidget *parent = 0, int maximum = 100);

    void createComponent(int maximum );

    void resizeEvent(QResizeEvent *);

    void keyPressEvent(QKeyEvent *);

    void connections();

    void adjustItens();

    void setPaymentView(PaymentView * paymentView);

    void setTableItem(TableView * tableItem);

    usint selected() const {return _selected;}

private:
    void setModels(DataModel * model, DataModel *modelPayments, bool clearModel = false); // seta o model e já ajusta a tabela, caso  o model esteja vazio, seta um model vazio (questão visual)

public slots:

    void closeTable();

    void adjustLayout();

    void input();

    void onClick_lSeletorLeft();

    void onClick_lSeletorRight();

    void onClick_Items(int index);

    void onDoubleClick_Items(int index);

    void onClick_lTreatment();

    void onClick_lJoin();

    void onClick_lTransfer();

    void onClick_lMedia();

    void onClick_pbSaveGroupMedia();

    void onClick_pbLeaveGroupMedia();

    void back();

    void updateData(int index, bool b);

    void groupVisible(bool b,QList<int> list);

    // atuação visual

    void transfer(int i);

    void join(int i);

    void treatment(int i);

    void convertData();

    void receivedModelItems(DataModel * model);

public:
    TreatmentTable *wTreatmentTable;

    QStackedWidget *swPanelsDesk;
    QStackedWidget *swPages;

private:
    GeneralData *_generalData;

    PaymentView *_paymentView;

    TableView *_tableItem;

    usint countValue;
    usint currentIndexItem;

    usint _maximumItens;
    int _selected;

    QWidget *wGroup;

    QWidget *wBackground;
    QLabel *lBackground;
    Label *lSeletorLeft;
    Label *lSeletorRight;


    QWidget *wPanel0;
    QWidget *wPanel1;
    QWidget *wPanel2;
    QWidget *wPanel3;
    QWidget *wPanel4;

    QWidget *wMenuOpen;
    QLabel *lMenuOpen;

    QWidget *wSelect;
    QLabel *lIndex;

    Label *lTreatment;
    QLabel *lTreatmentStatics;

    Label *lJoin;
    QLabel *lJoinStatics;

    Label *lTransfer;
    QLabel *lTransferStatics;

    Label *lMedia;
    QLabel *lMediaStatics;

    Label *lBack;

    Transfer *wTransfer;
    JoinTable *wJoinTable;
    Media *wMedia;    

    QLabel *lGroupVisible;

    QWidget *wGroupMedia;
    QLabel *lGroupMedia;
    QLabel *lGroupMediaTitle;
    SpinBox *SBGroupMedia;
    QPushButton* pbSaveGroupMedia;
    QPushButton* pbLeaveGroupMedia;

public:
    ItemDesk *itemDesk[100];

};

#endif // GROUPDESK_H
