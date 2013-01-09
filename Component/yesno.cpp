#include "yesno.h"

YesNo::YesNo(QWidget *parent, QString Option1, QString Option2) :
    QWidget(parent)
{
    _nameOption1 = Option1;
    _nameOption2 = Option2;

    createComponent();

    input();

    connections();
}

void YesNo::createComponent()
{
    pbYes = new QPushButton(_nameOption1,this);
    pbNo = new QPushButton(_nameOption2,this);
}

void YesNo::input()
{

#if defined(Q_WS_X11)
    {
        QFont f("Sans Serif", 5);
        f.setBold(true);
        this->setFont(f);
    }
#endif

#if defined(Q_WS_WIN)
    {
        QFont f("MS Shell Dlq 2", 7);
        f.setBold(true);
        this->setFont(f);
    }
#endif

    pbYes->setFont(this->font());
    pbYes->setCursor(Qt::PointingHandCursor);

    pbNo->setFont(this->font());
    pbNo->setCursor(Qt::PointingHandCursor);


    QString style;

    style = "QPushButton"
            "{"
            "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
            "stop: 1 rgba(230, 230, 230, 255), stop: 0 rgba(250, 250, 250, 255));"
            "color: rgba(100, 100, 100, 255);"
            "border: 1px solid rgba(0, 0, 0,20);"
            "border-top: 1px solid rgba(0, 0, 0, 30);"
            "border-bottom: 1px solid rgba(0, 0, 0, 50);"
            "border-radius: 0px;"
            "}"
            " "
            "QPushButton:hover, QPushButton:default:hover "
            "{ "
            "border-top: 2px solid rgba(0, 0, 0, 30); "
            "border-bottom: 2px solid rgba(0, 0, 0, 50); "
            "background-color: qlineargradient(spread:pad, x1:0.500, y1:0.278136, x2:0.500, y2:1,"
            "stop:1 rgba(255, 255, 255, 255), stop:0 rgba(237, 240, 245, 255)); "
            " }";

    this->setStyleSheet(style);

    pbYes->setStyleSheet("border-left: 1px solid rgba(0, 0, 0, 50);");

    pbNo->setStyleSheet("border-right: 1px solid rgba(0, 0, 0, 50);"
                            "border-left: 1px solid rgba(0, 0, 0, 30); ");

    _stylePressed = "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
            "stop:1 rgba(100, 100, 100, 200), stop:0 rgba(80, 80, 80, 200));"
            "color: rgb(230,230,230);"
            "border-top: 1px solid rgba(0, 0, 0, 30);"
            "border-bottom: 1px solid rgba(0, 0, 0, 50);"
            "border-radius: 0px;";
}

void YesNo::resizeEvent(QResizeEvent *)
{
    pbYes->setGeometry(0,0,this->width()/2, this->height());
    pbNo->setGeometry(pbYes->width(),0,this->width()/2, this->height());
}

void YesNo::onClick_pbYes()
{
    pbYes->setStyleSheet(_stylePressed);

    pbNo->setStyleSheet(this->styleSheet());

    state = true;

    emit option(true);
}

void YesNo::onClick_pbNo()
{
    pbNo->setStyleSheet(_stylePressed);

    pbYes->setStyleSheet(this->styleSheet());

    state = false;

    emit option(false);
}

void YesNo::connections()
{
    connect(pbYes,SIGNAL(clicked()),SLOT(onClick_pbYes()));

    connect(pbNo,SIGNAL(clicked()),SLOT(onClick_pbNo()));
}

void YesNo::setOption(bool option)
{
    if (option)
        onClick_pbYes();
    else
        onClick_pbNo();
}

void YesNo::setOption(QString textOption){
    if (pbYes->text() == textOption)
        setOption(true);
    else
        if (pbNo->text() == textOption)
            setOption(false);
}

bool YesNo::currentState()
{
    return state;
}
