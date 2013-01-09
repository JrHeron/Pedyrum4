#ifndef FUNCTIONARYINTERFACE_H
#define FUNCTIONARYINTERFACE_H

#include <Abstract/graphiceffects.h>
#include <Abstract/tools.h>
#include <Component/combobox.h>
#include <Component/doublespinbox.h>
#include <Component/edit.h>
#include <Component/label.h>
#include <Component/phoneedit.h>
#include <Component/search.h>
#include <Component/spinbox.h>
#include <Component/tableview.h>
#include <Object/employee.h>
#include <QKeyEvent>
#include <QLabel>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QSplitter>
#include <QStackedWidget>
#include <QTabWidget>
#include <QTextBrowser>
#include <QWidget>

const QString CSS_INVALID_EDIT_EMPLOYEE =
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

const QString CSS_VALID_EDIT_EMPLOYEE =
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

class FunctionaryInterface : public QWidget
{
    Q_OBJECT

public:
    explicit FunctionaryInterface(QWidget *parent = 0);
    void createComponent(); // Cria os componentes na tela.    
    void connections();     // cria as coneções.
    void hidePanel(bool b);
    void statics();         // alinha o layout estático.
    bool isAvailable();
    void createProfile();
    void createProfileWithData();

private:
    void resizeEvent(QResizeEvent *);

    inline int row(); // retorna a linha corrente da tableEmployee

signals:
    void goToPanel(int);

    void fullScreen();
    
public slots:
    void adjustSplitter();
    void adjustLayout();
    void gotoPanel(int index);
    void nextPanel();
    void input();           // informa as configs dos componentes

    void keyPressEvent(QKeyEvent *event);      

    void logout();

private slots:
    void onClick_lAdd();
    void onClick_lRemove();
    void onClick_lProfile();
    void onClick_lCalc();
    void onClick_pbConfirm();
    void onClick_pbLeave();

    void textChanged_eCPF(QString text);
    void doubleClicked_tableEmployee(QModelIndex index);
    void currentIndexChanged_cbSelectJobRole(QString text);
    void onClick_pbCalculateCommission();

    void onClick_pbAvailable();
    void onClick_pbUnavailable();

    void getSearchFunctionary(QString text);


public:
    short int nextPanelIndex;
    short int sizePanel;

    QLabel *lTop;

    Label *lAdd;
    Label *lRemove;
    Label *lProfile;
    Label *lCalc;
    QPushButton *pbAvailable;
    QPushButton *pbUnavailable;
    ComboBox * cbSelectJobRole;

    Search *searchFunctionary;

    QWidget *wSpace;
    QLabel *lBackgroundSpace;

    QStackedWidget *swPanels;

    QWidget *wGroupPlus;
    QLabel *lBackgroundPlus;

    // Itens normais.

    Edit *eName;    
    Edit *eCPF;
    Edit *eRG;
    phoneEdit *ePhone;
    phoneEdit *eMobile;
    Edit *eRadio;
    Edit *eCep;
    Edit *eStreet;
    Edit *eNumber;
    Edit *eComplement;
    Edit *eDistrict;            

    ComboBox *cbJobRole;

    QLabel *textPercent;
    DoubleSpinBox *DSBComission;

    Edit *eBank;
    Edit *eCC;
    Edit *eAg;

    QTextEdit *teNoteFunctionary;

    QPushButton *pbConfirm;  //add & save
    QPushButton *pbLeave;    //clear & cancel

    QWidget *wGroupProfile;
    QTextBrowser *tbProfile;

    TableView *tableEmployee;
    QSplitter *splitter;

    GraphicEffects *panelEffects;

    QPropertyAnimation  *  animaUp;
    QPropertyAnimation  *  animaDown;

    Employee *employee;

    Tools tools;
    
    bool isAdd;
    int idEmployeeUpdate;

    QWidget *wCalc;
    QLabel *lCalcbg;

    QLabel *lValueCommission;
    Edit *eBeforeDateCommission;
    Edit *eAfterDateCommission;
    QPushButton *pbCalculateCommission;
};

#endif // FUNCTIONARYINTERFACE_H
