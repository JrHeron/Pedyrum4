#ifndef CLIENTE_H
#define CLIENTE_H

#include <Object/people.h>
#include <Abstract/bdtools.h>

class Client : public People
{
    Q_OBJECT
public:
    explicit Client();

    ~Client();

    void start(QSqlDatabase *sdb);

    bool loadData(int idClient); // vc seta o id e da um load, ele carrega todos os dados

    bool loadDataBusiness(int idClient); // vc seta o id e da um load, ele carrega todos os dados

    void clearData(); // limpa todos os "campos" da classe

    bool instance(); // instancia o model de client, cria os completers e afins

    bool insert(); // ele pega todos os dados da classe e faz o insert no BD
    bool update(int id); // manda o id aqui, ele faz o load com tds os dados
    bool remove(int id);

    QString countClients(); // retorna a quantidade de clientes

    void emitCountClients(); // emit a quantidade de clientes, para ser pega pelo slot e atualizar o quadrado que carrega essa quantidade

    bool getDataAdress(QString cep);
    bool getDataClient(QString phone);

    bool getDataClientBusiness(QString phone);

    void setFilter(QString filter);
    void clearFilter();

    void setFilterBusiness(QString filter);
    void clearFilterBusiness();

    int totalClients();

public:
    void setShipping(float shipping); // unica variavel especifica do client com relação a pessoa
    void setNameRespondible(QString nameRespondible);
    void setCorporateName(QString corporateName);
    void setFantasyName(QString fantasyName);
    void setCNPJ(QString CNPJ);
    void setTypeClient(int typeClient);
    float getShipping();
    QString getNameRespondible();
    QString getCorporateName();
    QString getFantasyName();
    QString getCNPJ();

protected:
    float shipping;
    QString nameRespondible;
    QString corporateName;
    QString fantasyName;
    QString CNPJ;

public:
    int typeClient; // 1 para normal e 2 para business

public:
    BDTools bd;

signals:
    void count(QString);

public slots:
    void refreshModel();

};

#endif // CLIENTE_H
