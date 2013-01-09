#ifndef ALERTINTERFACE_H
#define ALERTINTERFACE_H

#include <Abstract/graphiceffects.h>
#include <Abstract/tools.h>
#include <Abstract/tools.h>
#include <Component/betweendate.h>
#include <Component/combobox.h>
#include <Component/edit.h>
#include <Component/label.h>
#include <Component/listview.h>
#include <Component/search.h>
#include <Component/seletordate.h>
#include <Component/tableview.h>
#include <Object/alert.h>
#include <QAction>
#include <QCalendarWidget>
#include <QCheckBox>
#include <QKeyEvent>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QSplitter>
#include <QStackedWidget>
#include <QTextBrowser>
#include <QTimer>
#include <QWidget>
#include <Object/messageobject.h>

class AlertInterface : public QWidget
{
    Q_OBJECT
public:
    explicit AlertInterface(QWidget *parent = 0);

    void createComponent();

    void statics();

    void connections();

    void resizeEvent(QResizeEvent *);

    void gotoPanel(int index);

    void hidePanel(bool b);

    bool isAvailable();

    void updateCountOrdered(QString qnt);

    int textCountAlertSize();

signals:
    void subAlert();

    void plusAlert();

    void goToPanel(int);

    void fullScreen();

private slots:

public slots:
    void logout();

    void selectedDates(QString dateS, QString dateF);

    void keyPressEvent(QKeyEvent *event);

    void seletorDate(int i);

    void count(int c);

    void input();

    void adjustLayout();

    void adjustSplitter();

    void nextPanel();

    void onClick_lAdd();

    void onClick_lRemove();

    void onClick_lProfile();

    void onClick_pbNewsAlerts();

    void onClick_pbAllAlerts();

    void onClick_pbAddList();

    void onClick_pbRemoveList();

    void onClick_pbSaveEditList();

    void onClick_pbLeave();

    void onClick_pbConfirm();

    void onDoubleClick_tbAlert(QModelIndex index);

    void onClick_tbAlert(QModelIndex index);

    void rowChanged_tbAlert(int row);

    void createProfile(QString title, QString subject, QString date, QString hour,
                          QString dateAlert, QString hourAlert, QString body);

    void createProfile();

    void updateHours();

    void onTriggered_actionTitle();

    void onTriggered_actionSubject();

    void onTriggered_actionDate();

    void onTriggered_actionHour();

    void updateVerificationAlert();

    void getSearchAlert(QString text);

    void onClick_pbAlterStatus();

    void onClick_cbIsRead();

    void showBetweenDate(int option);

public:
    enum typeSearch{
        TITLE = 0,
        SUBJECT = 1,
        DATE = 2,
        HOUR = 3
    };

    enum statusAlerts{
        INACTIVE = 0,
        NOTREAD = 1,
        READ = 2
    };

    typeSearch typeS;

    Tools tools;

    bool isAdd;

    unsigned int idAlertUpdate;

    short int sizePanel;

    short int nextPanelIndex;

    QLabel *lTop;

    Label *lAdd;
    Label *lRemove;
    Label *lProfile;
    QTextBrowser *textCountAlert;

    QPushButton *pbNewsAlerts;
    QPushButton *pbAllAlerts;

    QCheckBox *cbIsRead;

    QPushButton *pbAlterStatus;

    SeletorDate *wSeletorDate;

    Search *searchAlert;
    QAction *actionTitle;
    QAction *actionSubject;
    QAction *actionDate;
    QAction *actionHour;

    QSplitter *splitter;

    TableView *tableAlert;

    QWidget *wSpace;
    QLabel *lBackgroundSpace;

    QStackedWidget *swPanels;

    QWidget *wGroupPlus;
    QLabel *lGroupPlus;
    QLabel *lAlertDateText;
    Edit *eTitle;
    Edit *eSubject;
    Edit *eDate;
    Edit *eHour;
    Edit *eDateAlert;
    Edit *eHourAlert;
    QTextEdit *teNotes;

    ComboBox *cbPriority;

    QPushButton *pbLeave;
    QPushButton *pbConfirm;

    QWidget *wGroupProfile;
    QTextBrowser *tbProfile;

    QWidget *wBar;
    QLabel *lBar;
    QLabel *lHours;
    QLabel *lDate;
    QCalendarWidget *cwCalendar;

    QStackedWidget *swTasks;

    QWidget *wlistTasks;
    ListView *listTasks;
    QLabel *listText;
    QPushButton *pbAddList;
    QPushButton *pbRemoveList;

    QWidget *wTaskEdit;
    QTextEdit *teEditTask;
    QPushButton *pbSaveEditList;

    GraphicEffects *panelEffects;

    QPropertyAnimation  *  animaUp;
    QPropertyAnimation  *  animaDown;

    Alert *alert;

    QTimer *timer;
    QTimer *verificationAlert;

    BetweenDate *wBetweenDate;


};

#endif // ALERTINTERFACE_H
