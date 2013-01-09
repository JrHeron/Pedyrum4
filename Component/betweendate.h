#ifndef BETWEENDATE_H
#define BETWEENDATE_H

#include <QWidget>
#include <Component/edit.h>
#include <QPushButton>

class BetweenDate : public QWidget
{
    Q_OBJECT
public:
    explicit BetweenDate(QWidget *parent = 0);
    void createComponent();
    void connections();
    void resizeEvent(QResizeEvent *);


signals:
    void selectedDates(QString dateS, QString dateF); // s de start e f de finish

public slots:

    void input();

    void onClick_pbConfirm();

    void onTextChangedBefore(QString text);

    void onTextChangedLater(QString text);

    QString dateBefore();

    QString laterDate();

private:

    QString before;
    QString later;

    QLabel *lBackground;
    Edit *eBeforeDate;
    Edit *eAfterDate;
    QPushButton *pbConfirm;

public:
    short int W_, H_;

};

#endif // BETWEENDATE_H
