#include "usermenu.h"

const QString URL_HELP = "www.youtube.com/user/CanalJaguati?feature=CAQQwRs%3D";

UserMenu::UserMenu(QWidget *parent) :
    QWidget(parent)
{
    createComponent();
    input();
    connections();
}

void UserMenu::createComponent()
{
    lBackground = new Label(this);

    lConfigure = new Label(this,true,100);

    lLogoConfigure = new Label(this,true,100);

    lLogout = new Label(this,true,100);

    lLogoLogou = new Label(this,true,100);

    lHelp = new Label(this,true,100);

    lLogoHelp = new Label(this,true,100);
}

void UserMenu::resizeEvent(QResizeEvent *)
{
    adjustLayout();
}

void UserMenu::adjustLayout()
{
    lBackground->setGeometry(0,0,this->width(),this->height());

    lConfigure->setGeometry(35,5,this->width() - 35,20);
    lLogoConfigure->setGeometry(10,lConfigure->y(),20,20);

    lHelp->setGeometry(35,lConfigure->y() + lConfigure->height() + 2,this->width() - 35,20);
    lLogoHelp->setGeometry(10,lHelp->y(),20,20);

    lLogout->setGeometry(35,lHelp->y() + lHelp->height() + 2,this->width() - 35,20);
    lLogoLogou->setGeometry(10,lLogout->y(),20,20);
}

void UserMenu::input()
{
    lBackground->setStyleSheet("background-color: rgba(0,0,0,180);"
                               "border-radius: 3px;border: 1px solid rgba(0,0,0,100);");
    QFont f;
    f.setPointSize(8);

    lConfigure->setText(tr("Configuração"));
    lConfigure->setStandartStyle("color: rgba(255,255,255,100);");
    lConfigure->setHoverStyle("color: rgba(255,255,255,220);");
    lConfigure->setFont(f);

    lLogoConfigure->setScaledContents(true);
    lLogoConfigure->setImage(":/Extras/menu-user-config");

    lHelp->setText(tr("Ajuda"));
    lHelp->setStandartStyle("color: rgba(255,255,255,100);");
    lHelp->setHoverStyle("color: rgba(255,255,255,220);");
    lHelp->setFont(f);

    lLogoHelp->setScaledContents(true);
    lLogoHelp->setImage(":/Extras/menu-user-help");

    lLogout->setText(tr("Sair"));
    lLogout->setStandartStyle("color: rgba(255,255,255,100);");
    lLogout->setHoverStyle("color: rgba(255,255,255,220);");
    lLogout->setFont(f);

    lLogoLogou->setScaledContents(true);
    lLogoLogou->setImage(":/Extras/menu-user-exit");

    setVisible(false);
}

void UserMenu::showMenu()
{
    if(this->isVisible())
        setVisible(false);
    else
        setVisible(true);
}

void UserMenu::onClick_lHelp()
{
    QDesktopServices::openUrl(QUrl(URL_HELP));

    setVisible(false);
}

void UserMenu::connections()
{
    connect(lHelp,SIGNAL(onClick()),SLOT(onClick_lHelp()));

    connect(lConfigure,SIGNAL(onClick()),SLOT(onClick_lConfigure()));

    connect(lLogout,SIGNAL(onClick()),SLOT(onClick_lLogout()));
}

void UserMenu::onClick_lLogout()
{
    emit logout();

    setVisible(false);
}

void UserMenu::onClick_lConfigure()
{
    emit configure();

    setVisible(false);
}

void UserMenu::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_F11)
        emit fullScreen();
}
