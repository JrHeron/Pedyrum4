#ifndef CONFNETWORK_H
#define CONFNETWORK_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <Component/edit.h>
#include <Component/combobox.h>
#include <QComboBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QCheckBox>
#include <Abstract/encryption.h>
#include <QToolButton>
#include <QAction>
#include <QStackedWidget>
#include <Object/createdatabasethread.h>

class ConfNetwork : public QWidget
{
    Q_OBJECT
public: // fun��es
    explicit ConfNetwork(QWidget *parent = 0);

    void testConnectionFile();

    void testConnectionInput();

    void resizeEvent(QResizeEvent *); // ajusta os componentes no resize da tela

    bool fieldVerification();

    void createNewTables();


private: // fun��es

    void createComponent(); // cria os componentes

    void input(); // seta as configura��es iniciais do componente

    void connections(); // cria as conex�es

    void statics(); // seta os compoentes n�o alterados no resize.

    QString getIP(); // pega o ip do terminal em uso

    bool isValid(QString text); // verifica se s� tem numeros

    void saveData(QString username, QString password, QString ip, int port);

    void createDatabase();

    bool configPostgres(QString filename);    

private: // vari�veis
    QSqlDatabase sdb; // para testes de conex�o

    Encryption e;

signals:

    void gotoNext(int index);        
    void connected();
    void goToSplash();
    void noConnected();

private slots:

    void adjustLayout();

    void onClick_pbConnect();

    void onTextChanged_ePassword();

    void onTextChanged_ePort();

    void onCurrentIndexChanged_cbTypeConnection(int index);

    void onTriggered_aShowPassword();

    void onClick_lDownloadManual();

    void hideSplash();

    void showSplash();

    void databaseC(bool b, QString s);

    void tablesC(bool b, QString s);

    void proceduresC(bool b, QString s);

    void allC();

public:

    QString dbName;

    QWidget *wGroup;
    QLabel *lBackground;

    QLabel *lLogo;

    QLabel *lIpDisplay; // exibir o ipLocal
    Edit *eUsername; // username do banco de dados
    Edit *ePassword;
    QToolButton *tbViewPassword;
    QAction *aShowPassword;
    ComboBox *cbTypeConection; // pega o tipo de conex�o, como cliente ou como servidor
    Edit *eIP;
    Edit *ePort;
    Edit *eDir;    
    Label *lDownloadManual;

    QPushButton *pbConnect; // conectar

    QStackedWidget *swPanels;

    QWidget *wSplash;
    QLabel *lSplash;

    CreateDatabaseThread *cdThread;

};

#endif // CONFNETWORK_H
