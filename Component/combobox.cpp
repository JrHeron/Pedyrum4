#include "combobox.h"

ComboBox::ComboBox(QWidget *parent) :
    QComboBox(parent)
{
    this->installEventFilter(this);

    isNext = false;
}

bool ComboBox::eventFilter(QObject *target, QEvent *event)
{
    if (event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

        if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return){
            emit returnPressed();

            if (isNext)
                next->setFocus();
        }
    }

    return false;
}

void ComboBox::setNextComponent(QWidget *next)
{
    this->next = next;

    isNext = true;
}

void ComboBox::setListItens(QList<QString> listItens)
{
    itensList = listItens;

    for (int index = 0; index < itensList.count(); ++index)
            this->setItemText(index, itensList.value(index));
}

QList<QString> ComboBox::listItens()
{
    return itensList;
}

int ComboBox::currentIndexText(QString item)
{
    for (int index = 0; index < itensList.count(); ++index)
    {
        if(itensList.value(index) == item)
           return index;
    }

    qDebug("[ComboBox][int currentIndex(QString item)] Item não pode ser encontrado");

    return -1;
}

bool ComboBox::setFocusItem(QString item)
{
    if(currentIndexText(item) != -1)
    {
        this->setCurrentIndex(currentIndexText(item));
        return true;
    }

    return false;
}

void ComboBox::add(QString item)
{
    itensList << item;
    this->addItem(item);
}

bool ComboBox::setCurrentText(QString text)
{
    if(currentIndexText(text) != -1)
    {
        this->setCurrentIndex(currentIndexText(text));
        return true;
    }
    else
        return false;
}
