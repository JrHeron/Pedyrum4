#ifndef ACCOUNTFINANCEINTERFACE_H
#define ACCOUNTFINANCEINTERFACE_H

#include <Abstract/graphiceffects.h>
#include <Abstract/tools.h>
#include <Component/betweendate.h>
#include <Component/combobox.h>
#include <Component/doublespinbox.h>
#include <Component/edit.h>
#include <Component/search.h>
#include <Component/seletordate.h>
#include <Component/tableview.h>
#include <Object/bill.h>
#include <QAction>
#include <QKeyEvent>
#include <QLabel>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QSplitter>
#include <QStackedWidget>
#include <QTextBrowser>
#include <QTextEdit>
#include <QWidget>

class AccountFinanceInterface : public QWidget
{
    Q_OBJECT
public:
    explicit AccountFinanceInterface(QWidget *parent = 0);

    void createComponent();

    void statics();

    void connections();

    void resizeEvent(QResizeEvent *);

    void gotoPanel();

    void hidePanel(bool b);

    bool isAvailable();

    void clearBill();

    int textValueAccountsSize();

signals:
    void gotoPayBox(int index);
    void goToPanel(int);
    void fullScreen();

public slots:
    void logout();

    void seletorDate(int i);

    void updateTotalValue(QString value);

    void keyPressEvent(QKeyEvent *event);

    void input();

    void adjustLayout();

    void adjustSplitter();

    void onClick_lAdd();

    void onClick_lRemove();

    void onClick_pbPayBox();

    void onClick_pbConfirm();

    void onClick_pbLeave();

    void currentIndexChanged_cbType(int index);

    void doubleClicked_tableAccount(QModelIndex index);

    void currentIndexChanged_cbShowType(int index);

    void onTriggered_actionName();

    void onTriggered_actionDescription();

    void onTriggered_actionDatePay();

    void onTriggered_actionDateDeadLine();

    void showBetweenDate(int option);

    void selectedDates(QString dateS, QString dateF);

public:
    bool isAdd;

    Tools tools;

    int idUpdate; // id selecionado para edição

    Bill *bill;

    QLabel *lTop;

    Label *lAdd;
    Label *lRemove;

    QTextBrowser *textValueAccounts;

    QPushButton *pbPayBox;

    ComboBox *cbShowType;

    SeletorDate *wSeletorDate;

    Search *searchAccount;
    QAction *actionName;
    QAction *actionDescription;
    QAction *actionDatePay;
    QAction *actionDateDeadLine;

    QSplitter *splitter;

    TableView *tableAccount;

    QWidget *wSpace;
    QLabel *lBackgroundSpace;

    QStackedWidget *swPanels;

    QWidget *wPlus;
    QLabel *lPlus;

    Edit *eName;
    DoubleSpinBox *DSBValue;
    ComboBox  *cbType;
    ComboBox  *cbStatus;
    Edit * eDatePay;
    Edit * eDateDeadLine;
    QTextEdit *teNotes;

    QPushButton *pbConfirm;
    QPushButton *pbLeave;

    GraphicEffects *panelEffects;

    QPropertyAnimation  *animaUp;
    QPropertyAnimation  *animaDown;

    BetweenDate *wBetweenDate;

};

#endif // ACCOUNTFINANCEINTERFACE_H
