#include "item.h"
#include <QDebug>

Item::Item(QWidget *parent, QString urlImage, QString text):
    QWidget(parent)
{
    createComponent();

    setImage(urlImage);

    setText(text);

    setStyle("background-color: rgba(255,255,255,20);");

    lBody->setAlignment(Qt::AlignVCenter);

    setStandard("background-color: rgba(255,255,255,10);");

    connect(space,SIGNAL(onClick()),SLOT(onClick_space()));

    connect(space,SIGNAL(mouseOnImage(bool)),SLOT(showHover(bool)));
}

void Item::createComponent()
{
    image = new QLabel(this);

    lBody = new QLabel(this);

    space = new Label(this,true,100);
}

void Item::setImage(QString urlImage)
{
    image->setPixmap(QPixmap(urlImage));
    image->setScaledContents(true);
}

void Item::setText(QString text)
{
    lBody->setText(text);
}

void Item::setFont(QFont f)
{
    lBody->setFont(f);
}

void Item::adjustLayout()
{
    image->setGeometry(this->height() * 0.2,this->height() * 0.1,
                       this->height() * 0.8, this->height() * 0.8);

    lBody->setGeometry(this->height() * 0.4 + image->width(), this->height() * 0.1,
                       this->width() - (this->width() * 0.2 + image->width()), this->height() * 0.8);

    space->setGeometry(0,0,this->width(),this->height());
}

void Item::setStyle(QString style)
{
    lBody->setStyleSheet(style);
}

void Item::onClick_space()
{
    emit onClick();
}

void Item::setHover(QString style)
{
    Style = style;
}

void Item::showHover(bool b)
{
    if(b)
       space->setStyleSheet(Style);
    else
       space->setStyleSheet(StyleStandard);
}

void Item::resizeEvent(QResizeEvent *)
{
    adjustLayout();
}

void Item::setFontColor(QString styleCor)
{
    lBody->setStyleSheet(styleCor);
}

void Item::setStandard(QString style)
{
    StyleStandard = style;
    space->setStyleSheet(StyleStandard);
}
