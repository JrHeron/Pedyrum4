#include "phoneedit.h"
#include <QDebug>

phoneEdit::phoneEdit(QWidget *parent, bool usesClear, QString standard, int maximumLetters) :
    Edit(parent)
{
    button = new Label(parent);
    button->hide();

    valueStandart = standard;
    this->setText(valueStandart);
    this->setToolTip(valueStandart);

#if defined(Q_WS_X11)
    {
        QFont f("Sans Serif", 6);
        this->setFont(f);
    }
#endif

#if defined(Q_WS_WIN)
    {
        QFont f("MS Shell Dlq 2", 9);
        this->setFont(f);
    }
#endif

    if(usesClear)
    {
        button->setToolTip(tr("Limpar Campo"));
        button->setCursor(Qt::PointingHandCursor);
        connect(button,SIGNAL(onClick()),this,SLOT(Clear()));
        button->setPixmap(QPixmap(url_clear));
        useClear = true;
    }

    this->setMaxLength(maximumLetters);

    connections();

    setUpperCase(false);

    posN = this->cursorPosition();

    this->installEventFilter(this);

    this->setMaxLength(14);

    del = false;
}

bool phoneEdit::eventFilter(QObject *target, QEvent *event)
{
    if (event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

        if (keyEvent->key() == Qt::Key_Delete || keyEvent->key() == Qt::Key_Backspace)
            del = true;
        else
            del = false;
    }

    // return false, deixa o evento passar
    return false;
}


void phoneEdit::textChanged(QString text){
    if (this->isEmpty())
        return;

    QString phone = text.replace("(", "").replace(")", "").replace("-", "");

    if (phone.length() == 4 && !del){
        phone += "-";
    }else if(phone.length() > 4 && phone.length() <= 9){
        phone = phone.mid(0, 4) + "-" + phone.mid(4);
    }else if(phone.length() > 9){
        phone = "(" + phone.mid(0, 2) + ")" + phone.mid(2, 4) + "-" + phone.mid(6);
    }

    setText(phone);
}

void phoneEdit::cursorPositionChanged(int posO, int posN)
{
    this->posO = posO;
    this->posN = posN;
}
