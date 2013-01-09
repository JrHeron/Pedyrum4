#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <Abstract/bdtools.h>
#include <Abstract/tools.h>
#include <Abstract/encryption.h>

class Config : public QObject
{
    Q_OBJECT
public:
    explicit Config(QObject *parent = 0);

    void start(QSqlDatabase *sdb);

    // dados da empresa
    QString bPhone; // esse b é de Business, para não ter que escrever o nome td sempre (é chato)
    QString bName;
    QString bAddress;
    QString bDistrict;
    QString bCity;
    QString bState;

    bool insertDataBusiness();

    void loadDataBusiness();

    // dados do pedido
    int numberOfCopies;
    int fontSize; // inteiro que receberá o indice selecionado no combobox.
    int widthPaper;
    int typeNumering; // idem do fontsize
    int currentNumber;

    bool insertDataOrder();

    void loadDataOrder();

    // dados dos alertas
    QString daysAlertOrder;

    bool insertDataAlertOrder();

    void loadDataAlertOrder();

    // dados do backup
    QString dateLastBackup();

    // formas de pagamento
    QList<QString> getPaymentTypes();

    QList<QString> paymentTypes;

    bool insertDataPayementTypes();

    //rede
    bool saveDataAccessDatabase(QString username, QString password, QString ip, int port);

    bool loadDataNetwork();

    QString username;

    QString password;

    QString ip;

    QString port;

    // contas de usuário
    QString CurrentIdSystemUser;
    QString usernameSystemUser;
    QString passwordSystemUser;
    QString secretQuestionSystemUser;
    QString secretAnswerSystemUser;

    bool canAddAccount();

    bool insertUserAccount();

    bool insertUserAccessLevel(QString id);

    bool updateUserAccount(QString id);

    bool canEditAccount(QString id);

    bool canAlterAccess(QString id);

    QList<QList<QString> > getAllUsers();

    bool removeUser(QString id);

    QString idRoot();

    bool loadDataUser(QString idUser);

    bool cantreatment;
    bool canclient;
    bool canproduct;
    bool canordered;
    bool canemployee;
    bool canalert;
    bool canbill;
    bool cancash;
    bool cancreateuser;
    bool canalteraccess;


    // geral
    BDTools bd;

    Tools tools;

    Encryption e;

signals:

public slots:


};

#endif // CONFIG_H
