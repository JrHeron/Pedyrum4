#include "messagealert.h"

MessageAlert::MessageAlert(QWidget *parent) :
    QWidget(parent)
{
    createComponent();
    input();
    connections();
}

MessageAlert::MessageAlert(QWidget *parent, MessageObject *msg) :
    QWidget(parent)
{
    createComponent();
    input();
    setMessage(msg);
}


void MessageAlert::adjustLayout()
{
    lBackground->setGeometry(0,0,this->width(),this->height());

    lImage->setGeometry(this->height() * 0.15,this->height() * 0.15,this->height() * 0.7,this->height() * 0.7);

    lTitle->setGeometry(lImage->x() * 2 + lImage->width(),8, this->width() - (lImage->x() * 3 + lImage->width()),25);

    tbText->setGeometry(lTitle->x(),lTitle->y() + lTitle->height() - 3,lTitle->width(),this->height() - lTitle->y() * 2);

    lClose->setGeometry(this->width() - 17,5,12,10);
}

void MessageAlert::input()
{
    lBackground->setStyleSheet("background-color: rgba(80,80,80,255);"
                               "border: 1px solid rgb(240,240,240,180);"
                               "border-radius: 5px;");

    lImage->setStyleSheet("background-color: rgba(0,0,0,0);");
    lImage->setScaledContents(true);

    QFont f;

    f.setPointSize(12);

    lTitle->setStyleSheet("background-color: rgba(0,0,0,0);"
                          "color: rgba(230,230,230,230);");
    lTitle->setFont(f);

    f.setPointSize(10);

    tbText->setStyleSheet("background-color: rgba(0,0,0,0);"
                          "color: rgba(230,230,230,200);");

    tbText->setFont(f);

    lClose->setImage(URL_CLOSE);
}

void MessageAlert::createComponent()
{
    messageObject = new MessageObject(this);

    lBackground = new QLabel(this);
    lImage = new QLabel(this);
    lTitle = new QLabel(this);
    tbText = new QTextBrowser(this);
    lClose = new Label(this);
    timerShow = new QTimer(this);
}

void MessageAlert::resizeEvent(QResizeEvent *)
{
    adjustLayout();
}

void MessageAlert::setMessage(MessageObject *msg)
{
    messageObject = msg;

    timerShow->setInterval(messageObject->delay());

    lImage->setPixmap(QPixmap(messageObject->image()));

    lTitle->setText(messageObject->title());

    tbText->setText(messageObject->text());
}

MessageObject * MessageAlert::message()
{
    return messageObject;
}

void MessageAlert::onClick_lClose()
{
    timerShow->stop();

    emit hideMessage();
}

void MessageAlert::connections()
{
    connect(lClose,SIGNAL(onClick()),SLOT(onClick_lClose()));

    connect(timerShow,SIGNAL(timeout()),SLOT(onClick_lClose()));
}

void MessageAlert::startDelay()
{
    timerShow->start();
}

