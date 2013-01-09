#include "doublespinbox.h"

DoubleSpinBox::DoubleSpinBox(QWidget *parent) :
    QDoubleSpinBox(parent)
{
    this->installEventFilter(this);

    isNext = false;
}

bool DoubleSpinBox::eventFilter(QObject *target, QEvent *event)
{
    if (event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

        if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return){
            emit returnPressed();

            if (isNext)
                next->setFocus();
        }
    }

    // return false, deixa o evento passar
    return false;
}

void DoubleSpinBox::setNextComponent(QWidget *next)
{
    this->next = next;

    isNext = true;
}
