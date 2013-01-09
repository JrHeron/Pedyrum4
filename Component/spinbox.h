#ifndef SPINBOX_H
#define SPINBOX_H

#include <QSpinBox>
#include <QKeyEvent>
#include <QDebug>

class SpinBox : public QSpinBox
{
    Q_OBJECT
public:
    explicit SpinBox(QWidget *parent = 0);

    void setNextComponent(QWidget *next);

private:

    QWidget *next;

    bool isNext;

protected:
    bool eventFilter(QObject *, QEvent *);

signals:
    void returnPressed();

public slots:

};

#endif // SPINBOX_H
