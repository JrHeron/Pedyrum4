#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <Object/people.h>
#include <Abstract/bdtools.h>
#include <Abstract/tools.h>

class Employee : public People
{
    Q_OBJECT

public:

    void start(QSqlDatabase *sdb);

    // funções da classe em si (sem ser gets e sets
    bool loadData(int idEmployee); // vc seta o id e da um load, ele carrega todos os dados

    void clearData(); // limpa todos os "campos" da classe

    bool instance(); // instancia o model de client, cria os completers e afins

    bool insert(); // ele pega todos os dados da classe e faz o insert no BD
    bool update(int id); // manda o id aqui, ele faz o load com tds os dados
    bool remove(int id);

    void setFilter(QString filter);

    void setFilter();

    void setFilterJobRole(QString jobRole);

    void clearFilterJobRole();

    void setFilterStatus(bool free);

    bool areFilterStatus;
    bool areFilterJobRole;
    QString filterStatus;
    QString filterJobRole;

    void clearFilter();

    double getValueCommission(QString id, double commission, QString dateI, QString dateF);


public:
    QString phoneMobile;
    QString radio;
    QString jobRole;
    double commission;
    QString cpf;
    QString rg;
    QString cc;
    QString ag;
    QString bank;

    BDTools bd;

    Tools tools;

public slots:
    void refreshModel();

};

#endif // EMPLOYEE_H
