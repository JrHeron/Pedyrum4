#ifndef TOOLS_H
#define TOOLS_H

#include <QObject>
#include <QDebug>

class Tools : public QObject
{
    Q_OBJECT
public:
    explicit Tools(QObject *parent = 0);

    QString currentDay();
    QString currentMonth();
    QString currentMonth2();
    QString currentYear();
    QString currentTime();
    QString secondsToTime(int segunds, bool isLong = false);
    QString upFirstLetter(QString text);

    bool createTextFile(QString fileName);

    QString readFile(QString fileName);

    bool writeFile(QString fileName, QString text);

    /// pensar em um nome melhor
    QDateTime subDate(QString date, QString hour, int minutes); // pega a data e hora e diminui o n�mero de dias.

    QString month(int month);

    QString getDate(Qt::DateFormat format = Qt::SystemLocaleShortDate);

    int dayOfWeek(QString dateS); // pega o dia da semana de determinada data

    QString getDayBeginWeek(QString dateS); // pega o primeiro dia da semana da data especificada

    QString getDayEndWeek(QString dateS); // pega o �ltimo dia da semana da data especificada

    QString daysInMonth(QString dateS);
    QString daysInYear(QString dateS);

    bool betweenDates(QString dateI, QString dateF, QString dateC); // ve se a date se esta entre as outras datas, inclusive

    QString getTime(QString format);

    QString convertDate(QString date, QString separator = "/"); // converte de ddmmyyyy para yyyymmdd
    QString convertDate2(QString date, QString separator = "/"); // reverte a convers�o acima - tenho que ver um nome melhor para isso

    QChar compareDate(QString date0, QString date1); // retorna o numero da data maior

    QChar compareHour(QString hour0, QString hour1); // retorna o numero da data maior

    QString getIndexState(int index);

    // fun��es para trabalhar com horas
    bool betweenHours(QString hourI, QString hourF, QString hourC);
    unsigned int hourNumber(QString hour);

    unsigned int dateNumber(QString date);

    // recebe um valor e converte em formato monet�rio
    QString convertMoney(QString value, QString separator = ",");

    // fun��o que matem�tica que pode ser �til em futuras criptografias
    int modulo(int a, int e, int n); // retorna (a^e)%n

    bool isValidDate(QString dateS);

    bool isValidHour(QString hourS);

    // valida��es
    bool validateCNPJ(QString cnpj);
    bool validateCPF(QString cpf);

signals:

public slots:

};

#endif // TOOLS_H
