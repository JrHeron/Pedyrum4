#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QComboBox>
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>
#include <QList>

class ComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit ComboBox(QWidget *parent = 0);

    bool eventFilter(QObject *target, QEvent *event);

    void setNextComponent(QWidget * next);

    void setListItens(QList<QString> list);

    void add(QString item);

    QList<QString> listItens();

    int currentIndexText(QString item);

    bool setCurrentText(QString text);

    bool setFocusItem(QString item);

private:

    QWidget *next;

    bool isNext;

    QList<QString> itensList;

signals:
    void returnPressed();

signals:

public slots:

};

#endif // COMBOBOX_H
