#ifndef PESSOA_H
#define PESSOA_H

#include <QObject>

class People: public QObject
{
    Q_OBJECT
public:
    explicit People();

    void setId(int getId);

    void setName(QString name);
    void setPhone(QString phone);
    void setStreet(QString street);
    void setDistrict(QString district);
    void setNumber(QString number);
    void setComplement(QString complement);
    void setCEP(QString cep);

    void setNote(QString note);

    int getId();

    QString getName();
    QString getPhone();
    QString getStreet();
    QString getDistrict();
    QString getNumber();
    QString getComplement();
    QString getCEP();

    QString getNote();

public: // variaveis
    int id;

    QString name;
    QString phone;

    // dados de endereço
    QString street;
    QString district;
    QString number;
    QString complement;
    QString cep;

    QString note;

signals:

public slots:

};

#endif // PESSOA_H
