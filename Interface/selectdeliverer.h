#ifndef SELECTWAITER_H
#define SELECTWAITER_H

#include <QWidget>
#include <Component/combobox.h>
#include <QLabel>
#include <QPushButton>
#include <QTextBrowser>

class SelectDeliverer : public QWidget
{
    Q_OBJECT
public:
    explicit SelectDeliverer(QWidget *parent = 0);

    void createComponent();

    void statics();

    void connections();

    void resizeEvent(QResizeEvent *);

signals:
    void sendDeliverer(QString idWaiter);

public slots:
    void input();

    void setWaiters(QList<QString> namesWaiters, QList<QString> idsWaiters);

    void onClick_pbConfirm();

private:

    QLabel *lBackground;

    QLabel *lTitle;

    ComboBox *cbWaiters;

    QTextBrowser *textAlert;

    QPushButton *pbConfirm;

    QList<QString> idsWaiters;

};

#endif // SELECTWAITER_H
