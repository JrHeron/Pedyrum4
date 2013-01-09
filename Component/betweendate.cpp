#include "betweendate.h"

BetweenDate::BetweenDate(QWidget *parent) :
    QWidget(parent)
{
    createComponent();
    connections();
    input();
}

void BetweenDate::createComponent()
{
    lBackground = new QLabel(this);
    eBeforeDate = new Edit(this, true, tr("Data inicial"));
    eAfterDate = new Edit(this, true, tr("Data final"));
    pbConfirm = new QPushButton(tr("Confirmar"),this);
}

void BetweenDate::connections()
{
    connect(pbConfirm,SIGNAL(clicked()),this,SLOT(onClick_pbConfirm()));

    connect(eBeforeDate,SIGNAL(textChanged(QString)),this,SLOT(onTextChangedBefore(QString)));

    connect(eAfterDate,SIGNAL(textChanged(QString)),this,SLOT(onTextChangedLater(QString)));

    connect(eAfterDate, SIGNAL(returnPressed()), SLOT(onClick_pbConfirm()));
}

void BetweenDate::onClick_pbConfirm()
{
    // aqui terá uma verificação de validade das datas antes do emit

    emit selectedDates(eBeforeDate->text(), eAfterDate->text());
}

void BetweenDate::input()
{
    lBackground->setStyleSheet("background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                               "stop: 1 rgba(170,50,50,230), stop: 0 rgba(125,30,30,190));"
                               "border-radius: 10px;border: 1px solid rgba(255,255,255,255);");

    eBeforeDate->setInputMask("  /  /    ");

    eAfterDate->setInputMask("  /  /    ");

    H_ = 130;

    W_ = 160;

    eBeforeDate->setNextComponent(eAfterDate);
}

void BetweenDate::resizeEvent(QResizeEvent *)
{
    lBackground->setGeometry(0,0,this->width(),this->height());

    eBeforeDate->setGeometry(this->width()/ 2 - 60, 12, 120, 27);

    eAfterDate->setGeometry(eBeforeDate->x(), eBeforeDate->y() + eBeforeDate->height() + 10, 120, 27);

    pbConfirm->setGeometry(this->width()/2 - 45,eAfterDate->y() + eAfterDate->height() + 10,90,30);
}

QString BetweenDate::dateBefore()
{
    return before;
}

QString BetweenDate::laterDate()
{
    return later;
}

void BetweenDate::onTextChangedLater(QString text)
{
    if(eAfterDate->text() != eAfterDate->valueStandart)
        later = text;
}

void BetweenDate::onTextChangedBefore(QString text)
{
    if(eBeforeDate->text() != eBeforeDate->valueStandart)
        before = text;
}
