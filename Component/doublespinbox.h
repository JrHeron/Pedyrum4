#ifndef DOUBLESPINBOX_H
#define DOUBLESPINBOX_H

#include <QDoubleSpinBox>
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>

class DoubleSpinBox : public QDoubleSpinBox
{
    Q_OBJECT
public:
    explicit DoubleSpinBox(QWidget *parent = 0);

    bool eventFilter(QObject *target, QEvent *event);

    void setNextComponent(QWidget * next);

private:

    QWidget *next;

    bool isNext;

signals:
    void returnPressed();

public slots:

};

#endif // DOUBLESPINBOX_H
