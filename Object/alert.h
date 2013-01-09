#ifndef ALERT_H
#define ALERT_H

#include <QObject>
#include <Abstract/bdtools.h>
#include <Abstract/tools.h>
#include <Object/messageobject.h>

class Alert : public QObject
{
    Q_OBJECT
public:
    explicit Alert(QObject *parent = 0);

    void start(QSqlDatabase *sdb);

    bool instance();

    void getCount();

    // dados dos alertas
    QString title;
    QString subject;
    QString date;
    QString hour;
    QString dateAlert;
    QString hourAlert;
    QString priority;
    QString alerted;
    QString note;

    // dados das tarefas
    QString task;

    bool insertTask();
    bool updateTask(int id);
    bool removeTask(int id);

    bool insert();
    bool update(int id);
    bool remove(int id);

    void setFilter();

    void setFilter(QString filter);

    void clearFilter();

    bool areFilterTime; // mostra se há algum tipo de filtro por data ativo.
    QString filterTime; // armazena esse filtro.
    void getAlertsDays(); // pega os alertas da semana
    void getAlertsWeek(); // pega os alertas da semana
    void getAlertsMonth(); // pega os alertas do mes
    void getAlertsYear(); // pega os alertas do ano
    void getAlertsCustom(QString dateI, QString dateF); // pega os alertas do ano

    bool areFilterType; // verifica se tem filtro de tipo (novo ou não) ativo.
    QString filterType;
    void getAlertsNews(bool news);

    void clearData();

    void verifyAlert();

    void alterStatus(QString idAlert, QString newStatus);

    BDTools bd;

    Tools tools;

    MessageObject messageObject;

    QString dateIFilter;
    QString dateFFilter;

signals:
    void count(int);

    void newsAlerts(int, bool);

    void newAlertMessage(MessageObject *messageObject);

public slots:
    void refreshModels();

};

#endif // ALERT_H
