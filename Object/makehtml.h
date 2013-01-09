#ifndef MAKEHTML_H
#define MAKEHTML_H

#include <QObject>
#include <Object/order.h>
#include <Abstract/tools.h>
#include <Abstract/textprinter.h>
#include <Object/config.h>


class MakeHTML : public QObject
{
    Q_OBJECT
public:
    explicit MakeHTML(QObject *parent = 0);

    void start(QSqlDatabase *sdb);

    QString createHTMLOrder(int idOrder = 0);

    void setSizeFont(int size);


signals:

public slots:

    void loadNumberOfCopy();

    void print(QString HTML);

    void createPDF(QString HTML);

    void reload();

public:

    Order *order;
    int typeOrder;

    TextPrinter *printer;

    Tools tools;

    Config *config;

private:
    QString html;

    QString H1;
    QString H2;
    QString H3;
    QString H4;
    QString H5;
    QString H6;

    short int numberOfCopy;
};

#endif // MAKEHTML_H
