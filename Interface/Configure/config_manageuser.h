#ifndef CONFIG_MANAGEUSER_H
#define CONFIG_MANAGEUSER_H

#include <QWidget>
#include <Component/tableview.h>
#include <Abstract/datamodel.h>
#include <Component/edit.h>
#include <QPushButton>
#include <Component/combobox.h>
#include <Component/spinbox.h>
#include <QTextBrowser>
#include <Object/config.h>
#include <QCheckBox>

class Config_ManageUser : public QWidget
{
    Q_OBJECT
public:
    explicit Config_ManageUser(QWidget *parent = 0);

    void createComponent();

    void input();

    void resizeEvent(QResizeEvent *);

    void connections();

    void statics();

    void clearForm();

    void getAllUsers();

    void setIdRoot(QString idRoot);

    QString getIdRoot();

    void setStateCheckbox(bool state);

signals:
    void updateUser();

public slots:

    void adjustLayout();

    void configureAccount(QString name);

    void onCurrentIndexChanged_cbUseTimeout(int index);

    void doubleClicked_tableUserStandard(QModelIndex index);

    void onClick_pbConfirm();

    void onClick_pbConfirmAccess();

    void onClick_pbLeave();

    void onClick_pbRemoveUser();

    void onTextChanged_ePassword();

    void onTextChanged_eConfirmPassword();

    void currentChanged_wTabs(int index);

    void onClick_pbSaveLogout();

public:
    Config *config;

    QTabWidget *wTabs;
    DataModel *modelUserStandard;

private:

    QString idRoot;

    bool isAdd;

    QString idForUpdate;

    QLabel *lTabs;

    QWidget *wManageUser;
    TableView *tableAccounts;
    QPushButton *pbRemoveUser;
    Edit *eUsername;
    Edit *ePassword;
    Edit *eConfirmPassword;
    Edit *eSecretQuestion;
    Edit *eSecretAnswer;
    QPushButton *pbConfirm;
    QPushButton *pbLeave;

    QWidget *wManageAccess;    
    TableView *tableAccountsAccess;
    QLabel *textaccess;
    QCheckBox *checkTreatment;
    QCheckBox *checkClient;
    QCheckBox *checkProduct;
    QCheckBox *checkOrdered;
    QCheckBox *checkEmployee;
    QCheckBox *checkAlert;
    QCheckBox *checkBill;
    QCheckBox *checkCash;
    QLabel *textConfigure;
    QCheckBox *checkCreateUse;
    QCheckBox *checkAlteraccess;
    QPushButton *pbConfirmaccess;

    QWidget *wLogoutTime;
    ComboBox *cbUseTimeout;

    QTextBrowser *UseText;
    SpinBox *SBTime;
    QPushButton *pbSaveLogout;

};

#endif // CONFIG_MANAGEUSER_H
