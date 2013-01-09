#include "spinbox.h"

SpinBox::SpinBox(QWidget *parent) :
    QSpinBox(parent)
{
    this->installEventFilter(this);

    isNext = false;
}

bool SpinBox::eventFilter(QObject *target, QEvent * event){
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

void SpinBox::setNextComponent(QWidget *next)
{
    isNext = true;

    this->next = next;
}
