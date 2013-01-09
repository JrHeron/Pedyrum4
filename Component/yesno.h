#ifndef YESNO_H
#define YESNO_H

#include <QWidget>
#include <QPushButton>

class YesNo : public QWidget
{
    Q_OBJECT

public:

    explicit YesNo(QWidget *parent = 0,QString Option1 = tr("Yes"), QString Option2 = tr("No"));

    void createComponent();

    void input();

    void resizeEvent(QResizeEvent *);

    void connections();

    void setOption(bool option);

    void setOption(QString textOption);

    bool currentState();

signals:

    void option(bool b);

public slots:

    void onClick_pbYes();
    void onClick_pbNo();

private:

    QString _nameOption1;
    QString _nameOption2;

    QString _stylePressed;

    QPushButton *pbYes;
    QPushButton *pbNo;

    bool state;

};

#endif // YESNO_H
