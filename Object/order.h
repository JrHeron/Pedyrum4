#ifndef ORDER_H
#define ORDER_H

#include <QObject>
#include <Abstract/bdtools.h>
#include <Abstract/tools.h>
#include <Object/client.h>

typedef unsigned short int usint;

class Order : public QObject
{
    Q_OBJECT
public:
    explicit Order(QString connectionName, QObject *parent = 0);

    BDTools bd;
signals:
    void loadComplete();

public:

    void start(QSqlDatabase *sdb);

    QList<QString> getDataClient(QString phone);
    void setTypeClient(int typeClient);

    bool insertOrder();

    bool isAdd;

    bool insertShedule();

    int nextIdClient();

    bool updateClient(QList<QString> data);

    void loadDataOrder(int idOrder);

    void setIdSelectedBartender(int idSelectedBartender);

    QString phoneClient;

    Client *client;

    int typeClient;
    int idClient;
    double totalValueOrderProducts;
    double valuePaid;
    double valueShipping;
    QList<int> orderQuantity;
    QList<double> orderValues;
    QList<QString> orderSizes;
    QList<QList<int> > orderPartProduct;
    QList<QList<QString> > orderIdProduct;
    QList<QList<QString> > orderNameProduct;
    QList<QString> orderNoteProduct;
    QList<QString> orderPaymentForm;
    QList<QString> orderPaymentFormValue;
    bool isPaid;

    // coisas de mesa
    bool isMedia;
    bool isCompound;
    bool isChildren;
    bool isFather;
    unsigned int idBartender;
    QString linkedTables;
    usint countPeople; 
    usint currentTable;

    // agendamento

    QString dateSchedule;
    QString hourSchedule;

    // dados do cliente

    QString name;
    QString phone;

    // dados de endereço
    QString street;
    QString district;
    QString number;
    QString complement;
    QString cep;

    QString note;

    float shipping;
    QString nameRespondible;
    QString corporateName;
    QString fantasyName;
    QString CNPJ;

    bool insertClient();

    QString idOrder;

    int typeOrder;

    enum{
        DELYVERY = 1,
        TABLE = 2,
        COUNTER = 3
    };

    QList<QString> paymentTypes();
    QList<QList<QString> > bartenders();

    QList<QList<QString> > listBartenders;

    int _idSelectedBartender;

    int totalOrders();

protected:
    void instance();

private:
    Tools tools;

};

#endif // ORDER_H
