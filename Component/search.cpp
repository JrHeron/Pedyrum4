#include "Component/search.h"
#include <QFont>
#include <QDebug>

Search::Search(QWidget *parent, QString text, bool single):
    QWidget(parent)
{
    textStandard = text;

    isSingle = single;

    createCompleter();
    input();
    connections();

    eSearch->setToolTip("");
}

void Search::createCompleter()
{
    completer = new QCompleter();
    eSearch = new Edit(this,true,textStandard);
    tbMenu = new QToolButton(this);
}

void Search::input()
{
    eSearch->setStyleSheet("border-radius: 8px;"
                           "border: 1px solid rgba(0,0,0,50);");

    eSearch->setStyleSheet("padding: 1px 12px 1px 30px;"
                           "padding-left: 30px;"
                           "color: rgba(0,0,0,150);");

    QFont f;

#if defined(Q_WS_X11)
    f.setPointSize(7);
#endif

#if defined(Q_WS_WIN)
    f.setPointSize(10);
#endif

    f.setItalic(true);

    eSearch->setFont(f);

    if(!isSingle)
    {
        tbMenu->setPopupMode(QToolButton::MenuButtonPopup);
        tbMenu->setIconSize(QSize(22,22));
    }
    else
        tbMenu->setIconSize(QSize(14,14));


    tbMenu->setAutoRaise(true);
    tbMenu->setIcon(QIcon(URL_MENU));

}

void Search::connections()
{
    connect(eSearch,SIGNAL(textChanged(QString)),SLOT(textChanged(QString)));
}

void Search::layout()
{
    tbMenu->setGeometry(0,0,this->height() + (this->height() / 6),this->height());
    eSearch->setGeometry(0,0,this->width(),this->height());
}

int Search::column()
{
    return completer->completionColumn();
}

void Search::setColumn(int column)
{
    completer->setCompletionColumn(column);
}

void Search::setCompleter(QCompleter *autoCompleter)
{
    completer = autoCompleter;
    eSearch->setCompleter(completer);
}

void Search::setAction(QAction *action)
{
    tbMenu->addAction(action);
}

void Search::resizeEvent(QResizeEvent *)
{
    layout();
}

void Search::textChanged(QString text)
{
    if(text != textStandard)
    {
        eSearch->setStyleSheet("padding: 1px 12px 1px 30px;"
                               "padding-left: 30px;"
                               "color: rgba(0,0,0,255);");
        emit textSearch(text);
    }
    else
    {
        eSearch->setStyleSheet("padding: 1px 12px 1px 30px;"
                               "padding-left: 30px;"
                               "color: rgba(0,0,0,150);");
    }
}
