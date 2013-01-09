#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H

#include <QWidget>

#include <Component/label.h>
#include <Component/edit.h>
#include <Component/tableview.h>
#include <Component/search.h>
#include <Abstract/graphiceffects.h>
#include <Object/client.h>
#include <QTextBrowser>
#include <QStackedWidget>
#include <Component/doublespinbox.h>
#include <Component/phoneedit.h>
#include <QTextEdit>
#include <QPushButton>
#include <QSplitter>
#include <Abstract/tools.h>
#include <QKeyEvent>

const QString CSS_INVALID_EDIT_CLIENT =
"QLineEdit:focus, QLineEdit:hover"
"{"
"color: rgb(0,0,0);"
"selection-color: GhostWhite;"
"border: 2px solid #009ACD;"
"}"

"QLineEdit "
"{"
"border: 1px solid #B0C4DE;"
"border-radius: 5px;"
"padding: 1px 14px 1px 5px;"
"color:#990000;"
"background-color: rgb(255,255,255);"

"}";

const QString CSS_VALID_EDIT_CLIENT =
"QLineEdit:focus, QLineEdit:hover"
"{"
"color: rgb(0,0,0);"
"selection-color: GhostWhite;"
"border: 2px solid #009ACD;"
"}"

"QLineEdit "
"{"
"border: 1px solid #B0C4DE;"
"border-radius: 5px;"
"padding: 1px 14px 1px 5px;"
"color:#333333;"
"background-color: rgb(255,255,255);"

"}";

class ClientInterface : public QWidget
{
    Q_OBJECT
public:
    explicit ClientInterface(QWidget *parent = 0);
    void createComponent(); // Cria os componentes na tela.

    void connections();     // cria as coneções.
    void hidePanel(bool b);
    void statics();         // alinha o layout estático.

    void createProfile(Client *c);
    void createProfile();

    int textCountClientSize();

private:
    void resizeEvent(QResizeEvent *);    
    bool isAvailable();
    bool isAvailableBusiness();

signals:
    void goToPanel(int);

    void fullScreen();

public slots:        

    void updateCountClients(QString qnt);
    void input();
    void adjustLayout();
    //void getDataAdress();
    void getDataClient(QString phone);
    void getDataClientBusiness(QString phoneBusiness);
    void gotoPanel(int index);
    void adjustSplitter();
    void nextPanel();

    void onDoubleClick_tbClient(QModelIndex index);
    void onClick_tbClient(QModelIndex index);
    void rowChanged_tbClient(int row);

    void onTextChanged_ePhone(QString text);
    void onTextChanged_ePhoneBusiness(QString text);
    void onTextChanged_eCNPJ(QString text);

    void inFocus_ePhoneBusiness(bool focus);

    void inFocus_ePhone(bool focus);

    void editingFinished_ePhone();

    void editingFinished_ePhoneBusiness();

    void logout();

private slots:
    void keyPressEvent(QKeyEvent *event);

    void onClick_lAdd();
    void onClick_lRemove();
    void onClick_lProfile();
    void onClick_pbConfirm();
    void onClick_pbLeave();
    void onClick_pbLeaveBusiness();
    void onClick_pbConfirmBusiness();
    void onClick_lRemoveBusiness();
    void getSearchClient(QString text);
    void onClick_pbSelectPeople();
    void onClick_pbSelectBusiness();

    void onTriggered_actionPhone();
    void onTriggered_actionName();

public:

    short int nextPanelIndex;
    short int sizePanel;

    int idClientUpdate;

    QLabel *lTop;

    Label *lAdd;
    Label *lRemove;
    Label *lProfile;
    QTextBrowser *textCountClient;

    Search *searchClient;

    QWidget *wSpace;
    QLabel *lBackgroundSpace;

    QStackedWidget *swPanels;
    QStackedWidget *swClientType;

    QPushButton *pbSelectPeople;
    QPushButton *pbSelectBusiness;

    TableView *tableClient;
    QSplitter *splitter;

    QWidget *wGroupClient;
    QLabel *lBackgroundPlus;
    phoneEdit *ePhone;
    Edit *eCep;
    Edit *eName;
    Edit *eStreet;
    Edit *eNumber;
    Edit *eComplement;
    Edit *eDistrict;
    DoubleSpinBox *DSBShipping;
    QTextEdit *teNotes;
    QPushButton *pbConfirm;  //add & save
    QPushButton *pbLeave;    //clear & cancel

    QWidget *wGroupBusiness;
    QLabel *lBgPlusBusiness;
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
    DoubleSpinBox *DSBShippingBusiness;
    QTextEdit* teNotesBusiness;
    QPushButton *pbConfirmBusiness;
    QPushButton *pbLeaveBusiness;

    QWidget *wGroupProfile;
    QTextBrowser *tbProfile;

    QWidget *wGroupAnalytics;

    Client *client;

    GraphicEffects *panelEffects;

    QPropertyAnimation  *  animaUp;
    QPropertyAnimation  *  animaDown;

    QAction *actionPhone;
    QAction *actionName;


private:
    bool isAdd;
    bool isAddBusiness;
    float percentSplitter;


    bool bogth;

    int typeSelected;

    enum{
        NORMAL = 1,
        BUSINESS = 2
    };

    Tools tools;
};

#endif // CLIENTINTERFACE_H
