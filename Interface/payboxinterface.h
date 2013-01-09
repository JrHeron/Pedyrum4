#ifndef PAYBOXINTERFACE_H
#define PAYBOXINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <Component/search.h>
#include <Component/seletordate.h>
#include <Component/tableview.h>
#include <QSplitter>
#include <QStackedWidget>
#include <QTextBrowser>
#include <QPropertyAnimation>
#include <Abstract/graphiceffects.h>
#include <QDoubleSpinBox>
#include <Component/combobox.h>
#include <Component/edit.h>
#include <Component/doublespinbox.h>
#include <Abstract/tools.h>
#include <Object/movementcash.h>
#include <QAction>
#include <Component/betweendate.h>
#include <QKeyEvent>

class PayBoxInterface : public QWidget
{
    Q_OBJECT

public:
    explicit PayBoxInterface(QWidget *parent = 0);

    void createComponent();

    void statics();

    void connections();

    void resizeEvent(QResizeEvent *);

    void gotoPanel(int index);

    void hidePanel(bool b);

    bool isAvailable();

    bool isAvailableOpenBox();

    bool isAvailableCloseBox();

    void clearForm();

    void clearFormOpenBox();

    void clearFormCloseBox();


    int textValuePayBoxSize();

signals:
    void gotoAccount(int index);

    void goToPanel(int);

    void fullScreen();

public slots:
    void logout();

    void keyPressEvent(QKeyEvent *event);

    void getSearchPayBox(QString text);

    void input();

    void adjustLayout();

    void adjustSplitter();

    void nextPanel();

    void onClick_lAdd();

    void onClick_lRemove();

    void onClick_pbAccount();

    void onClick_lOpenBox();

    void onClick_lCloseBox();

    void onClick_pbConfirm();

    void onClick_pbLeave();

    void onClick_pbConfirmOpenBox();

    void onClick_pbLeaveOpenBox();

    void onClick_pbConfirmCloseBox();

    void onClick_pbLeaveCloseBox();

    void updateTotalValue(QString value);

    void doubleClicked_tablePayBox(QModelIndex index);

    void onTriggered_actionDate();

    void onTriggered_actionHour();

    void onTriggered_actionDescrition();

    void showBetweenDate(int option);

    void seletorDate(int i);

    void selectedDates(QString dateI, QString dateF);

public:

    Tools tools;

    MovementCash *cash; // botei movementCash nao que ficaria mto grande

    bool isAdd;

    enum typeSearch{
        DESCRIPTION = 0,
        DATE = 1,
        TIME = 2
    };

    typeSearch typeS;

    int idUpdate;

    short int nextPanelIndex;
    short int sizePanel;

    QLabel *lTop;

    Label *lAdd;
    Label *lRemove;
    Label *lOpenBox;
    Label *lCloseBox;

    QTextBrowser *textValuePayBox;

    QPushButton *pbBill;

    SeletorDate *wSeletorDate;

    Search *wSearchPayBox;
    QAction *actionDate;
    QAction *actionHour;
    QAction *actionDescrition;

    QWidget *wPlus;
    QLabel *lPlus;
    DoubleSpinBox *DSBValue;
    ComboBox *cbTypeValue;
    Edit *eDate;
    Edit *eHour;
    QTextEdit *teNotes;
    QPushButton *pbConfirm;
    QPushButton *pbLeave;

    QWidget *wOpenBox;
    QLabel *lBgOpenBox;
    DoubleSpinBox *DSBValueOpenCash;
    Edit *eDateOpenBox;
    Edit *eHourOpenBox;
    QPushButton *pbConfirmOpenBox;
    QPushButton *pbLeaveOpenBox;

    QWidget *wCloseBox;
    QLabel *lBgCloseBox;
    QLabel *lCloseValue;
    Edit *eDateCloseBox;
    Edit *eHourCloseBox;
    QPushButton *pbConfirmCloseBox;
    QPushButton *pbLeaveCloseBox;

    QSplitter *splitter;

    TableView *tablePayBox;

    QStackedWidget *swPanels;

    QWidget *wSpace;
    QLabel *lBackgroundSpace;

    GraphicEffects *panelEffects;

    QPropertyAnimation  *animaUp;
    QPropertyAnimation  *animaDown;

    BetweenDate *wBetweenDate;

};

#endif // PAYBOXINTERFACE_H
