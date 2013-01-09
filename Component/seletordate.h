#ifndef SELETORDATE_H
#define SELETORDATE_H

#include <QWidget>
#include <QPushButton>
#include <QString>

const QString redStyle = "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                         "stop:1 rgba(165, 47, 31, 255), stop:0 rgba(180, 60, 40, 255));"
                         "color: rgb(230,230,230);"
                         "border-top: 1px solid rgba(0, 0, 0, 30);"
                         "border-bottom: 1px solid rgba(0, 0, 0, 50);"
                         "border-radius: 0px;";

class SeletorDate : public QWidget
{
    Q_OBJECT
public:
    explicit SeletorDate(QWidget *parent = 0);

    void createComponent();

    void resizeEvent(QResizeEvent *);

    void connections();

    void input();

    void setColor(QRgb color);

    void setColorAlternate(QRgb color);


signals:
    void selected(int index);

private slots:

    void onClick_pbToday();
    void onClick_pbWeek();
    void onClick_pbMonth();
    void onClick_pbYear();
    void onClick_pbPeriod();

public slots:

    void adjustLayout();

public:

    QPushButton *pbToday;
    QPushButton *pbWeek;
    QPushButton *pbMonth;
    QPushButton *pbYear;
    QPushButton *pbPeriod;

private:



};

#endif // SELETORDATE_H
