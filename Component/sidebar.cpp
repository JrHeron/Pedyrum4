#include "sidebar.h"
#include <QDebug>
#include <QPropertyAnimation>

sideBar::sideBar(QWidget *parent) :
    QWidget(parent)
{
    createComponent();    
    input();
    connections();
}

void sideBar::createComponent()
{
    background = new QLabel(this);

    wScrool = new QWidget(this);

    pbUp = new QPushButton(this);
    pbDown = new QPushButton(this);

    lTreatment = new Label(wScrool,true,100);
    lClient = new Label(wScrool,true,100);
    lStock = new Label(wScrool,true,100);
    lOrdered = new Label(wScrool,true,100);
    lFunctionary = new Label(wScrool,true,100);    
    lAlerts = new Label(wScrool,true,100);    
    lFinance = new Label(wScrool,true,100);
    lConfigure = new Label(wScrool,true,100);
    lJaguati = new Label(wScrool,true,100);

    textAlert = new Label(wScrool);

    effects = new GraphicEffects(this);
}

void sideBar::adjustLayout()
{
    if(this->height() > 0)
        this->setGeometry(0,this->y(),this->width(),this->height());
    else
        this->setGeometry(0,this->y(),this->width(),0);

    background->setGeometry(0,0,this->width(),this->height());

    pbUp->setGeometry(0,0,this->width(),25);

    pbDown->setGeometry(0,this->height() - pbUp->height(),this->width(),25);

    if(countItens == 0)
        countItens = 9;
    else
        wScroolHeight = (SIZE_BUTTON + SPACING) * countItens;

    wScrool->setGeometry(0,wScroolY,this->width(),wScroolHeight);

    // adjustLayout dos botões //

    short int positionX = width() / 2 - SIZE_BUTTON/2;
    short int count = 0;

    if(lTreatment->isVisible())
        count ++;
    lTreatment->setGeometry(positionX, (SPACING * count), SIZE_BUTTON, SIZE_BUTTON);

    if(lClient->isVisible())
        count ++;

    lClient->setGeometry(positionX, (SPACING * count) + SIZE_BUTTON , SIZE_BUTTON, SIZE_BUTTON);

    if(lStock->isVisible())
        count ++;

    lStock->setGeometry(positionX,(SPACING * count) + (SIZE_BUTTON * (count - 1)) , SIZE_BUTTON, SIZE_BUTTON);

    if(lOrdered->isVisible())
        count ++;

    lOrdered->setGeometry(positionX, (SPACING * count) + (SIZE_BUTTON * (count - 1)) , SIZE_BUTTON, SIZE_BUTTON);

    if(lFunctionary->isVisible())
        count ++;

    lFunctionary->setGeometry(positionX, (SPACING * count) + (SIZE_BUTTON * (count - 1)), SIZE_BUTTON, SIZE_BUTTON);

    if(lAlerts->isVisible())
        count ++;

    lAlerts->setGeometry(positionX, (SPACING * count) + (SIZE_BUTTON * (count - 1)), SIZE_BUTTON, SIZE_BUTTON);

    if(lFinance->isVisible())
        count ++;

    lFinance->setGeometry(positionX, (SPACING * count) + (SIZE_BUTTON * (count - 1)), SIZE_BUTTON, SIZE_BUTTON);

    if(lConfigure->isVisible())
        count ++;

    lConfigure->setGeometry(positionX, (SPACING * count) + (SIZE_BUTTON * (count - 1)), SIZE_BUTTON, SIZE_BUTTON);

    if(lJaguati->isVisible())
        count ++;

    lJaguati->setGeometry(positionX, (SPACING * count) + (SIZE_BUTTON * (count - 1)), SIZE_BUTTON, SIZE_BUTTON);

    checkEnableButtons();

    textAlert->setGeometry(lAlerts->x(),lAlerts->y() + 10,lAlerts->width(),20);

    countItens = count;
}

void sideBar::input()
{
    countItens = 9;

    wScroolHeight = (SIZE_BUTTON + SPACING) * countItens;

    wScroolY = 25;

    background->setStyleSheet("background-color: rgba(0,0,0,180);");

    pbUp->setToolTip(tr("Subir"));
    pbUp->setObjectName("pbUp");
    pbUp->setIcon(QIcon(":/sideBar/up"));
    pbUp->setIconSize(QSize(this->width(),25));

    pbDown->setToolTip(tr("Descer"));
    pbDown->setObjectName("pbDown");
    pbDown->setIcon(QIcon(":/sideBar/down"));
    pbDown->setIconSize(QSize(this->width(),25));

    lTreatment->setImage(":/sideBar/treatment");
    lTreatment->setHover("");
    lTreatment->setAlternateImage("");
    lTreatment->setToolTip(tr("Atendimento"));

    lClient->setImage(":/sideBar/client");
    lClient->setHover("");
    lClient->setAlternateImage("");
    lClient->setToolTip(tr("Cliente"));

    lStock->setImage(":/sideBar/product");
    lStock->setHover("");
    lStock->setAlternateImage("");
    lStock->setToolTip(tr("Produto"));

    lOrdered->setImage(":/sideBar/ordered");
    lOrdered->setHover("");
    lOrdered->setAlternateImage("");
    lOrdered->setToolTip(tr("Pedidos"));

    lFunctionary->setImage(":/sideBar/functionary");
    lFunctionary->setHover("");
    lFunctionary->setAlternateImage("");
    lFunctionary->setToolTip(tr("Funcionário"));

    lAlerts->setImage(":/sideBar/alert");
    lAlerts->setHover("");
    lAlerts->setAlternateImage("");
    lAlerts->setToolTip(tr("Avisos"));

    lFinance->setImage(":/sideBar/finance");
    lFinance->setHover("");
    lFinance->setAlternateImage("");
    lFinance->setToolTip(tr("Financeiro"));

    lConfigure->setImage(":/sideBar/config");
    lConfigure->setHover("");
    lConfigure->setAlternateImage("");
    lConfigure->setToolTip(tr("Configuração"));

    lJaguati->setImage(":/sideBar/jaguati");
    lJaguati->setHover("");
    lJaguati->setAlternateImage("");
    lJaguati->setToolTip(tr("Jaguati"));

    QFont f;

#if defined(Q_WS_X11)
    {
        f.setFamily("Sans Serif");
        f.setPointSize(12);
    }
#endif

#if defined(Q_WS_WIN)
    {
        f.setFamily("MS Shell Dlq 2");
        f.setPointSize(14);
    }
#endif

    textAlert->setFont(f);

    textAlert->setAlignment(Qt::AlignCenter);

    textAlert->setStyleSheet("color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                             "stop:1 rgba(165, 47, 31, 255), stop:0 rgba(180, 60, 40, 255));");

}

void sideBar::resizeEvent(QResizeEvent *)
{
    adjustLayout();
}

void sideBar::onClick_Treatment()
{
    emit goToPanel(3);
}

void sideBar::onClick_Client()
{
    emit goToPanel(4);
}

void sideBar::onClick_Stock()
{
    emit goToPanel(5);
}

void sideBar::onClick_Ordered()
{
    emit goToPanel(6);
}

void sideBar::onClick_Functionary()
{
    emit goToPanel(7);
}

void sideBar::onClick_Alerts()
{
    emit goToPanel(8);
}

void sideBar::onClick_Finance()
{
    emit goToPanel(9);
}

void sideBar::onClick_Configure()
{
    emit goToPanel(10);
}

void sideBar::onClick_Jaguati()
{
    emit goToPanel(11);
}

void sideBar::onClick_pbDown()
{
    wScroolY = (this->height() - pbUp->height() *2) -  wScrool->height();
    moveScrool(false);
}

void sideBar::onClick_pbUp()
{
    wScroolY = pbUp->height();
    moveScrool(true);
}

void sideBar::connections()
{
    connect(pbUp,SIGNAL(clicked()),SLOT(onClick_pbUp()));

    connect(pbDown,SIGNAL(clicked()),SLOT(onClick_pbDown()));

    connect(lClient,SIGNAL(onClick()),this,SLOT(onClick_Client()));

    connect(lTreatment,SIGNAL(onClick()),this,SLOT(onClick_Treatment()));

    connect(lStock,SIGNAL(onClick()),this,SLOT(onClick_Stock()));

    connect(lOrdered,SIGNAL(onClick()),this,SLOT(onClick_Ordered()));

    connect(lFunctionary,SIGNAL(onClick()),this,SLOT(onClick_Functionary()));

    connect(lAlerts,SIGNAL(onClick()),this,SLOT(onClick_Alerts()));

    connect(lFinance,SIGNAL(onClick()),this,SLOT(onClick_Finance()));

    connect(lConfigure,SIGNAL(onClick()),this,SLOT(onClick_Configure()));

    connect(lJaguati,SIGNAL(onClick()),this,SLOT(onClick_Jaguati()));

    connect(textAlert,SIGNAL(onClick()),this,SLOT(onClick_Alerts()));
}

void sideBar::checkEnableButtons()
{
    if((this->height() - pbUp->height() *2) >= wScrool->height() && wScroolY > 0)
    {
        pbUp->setEnabled(false);
        pbUp->setIcon(QIcon(":/sideBar/up-alternate"));

        pbDown->setEnabled(false);
        pbDown->setIcon(QIcon(":/sideBar/down-alternate"));
    }
    else
    {
        if(wScrool->height() + wScroolY <= pbDown->y())
        {
            pbDown->setEnabled(false);
            pbDown->setIcon(QIcon(":/sideBar/down-alternate"));
        }
        else
        {
            pbDown->setEnabled(true);
            pbDown->setIcon(QIcon(":/sideBar/down"));
        }

        if(wScroolY == (pbUp->y() + pbUp->height()))
        {
            pbUp->setEnabled(false);
            pbUp->setIcon(QIcon(":/sideBar/up-alternate"));
        }
        else
        {
            pbUp->setEnabled(true);
            pbUp->setIcon(QIcon(":/sideBar/up"));
        }
    }
}


void sideBar::moveScrool(bool up)
{
    QPropertyAnimation *animacao;

    if(up)
    {
        animacao = effects->createAnimation(wScrool,QRect(wScrool->x(),wScroolY,
                                                          wScrool->width(),wScrool->height()),300,QEasingCurve::Linear);
    }
    else
    {
        animacao = effects->createAnimation(wScrool,QRect(wScrool->x(),wScroolY,
                                                          wScrool->width(),wScrool->height()),300,QEasingCurve::Linear);
    }

    animacao->start();

    connect(animacao,SIGNAL(finished()),SLOT(checkEnableButtons()));
}

void sideBar::setAlert(int count, bool newAlert)
{
    countAlert = count;

    QString temp;

    temp.setNum(countAlert);

    textAlert->setText(temp);

    if (newAlert)
        emit showNewAlert();
}

int sideBar::countAlerts()
{
    return countAlert;
}

void sideBar::setVisibleItens(short index, bool visible)
{
    switch(index)
    {

    case 0:lTreatment->setVisible(visible);
        break;

    case 1:lClient->setVisible(visible);
        break;

    case 2:lStock->setVisible(visible);
        break;

    case 3:lOrdered->setVisible(visible);
        break;

    case 4:lFunctionary->setVisible(visible);
        break;

    case 5:
    {
        lAlerts->setVisible(visible);
        textAlert->setVisible(visible);
        break;
    }

    case 6:lFinance->setVisible(visible);
        break;

    case 7:lConfigure->setVisible(visible);
        break;

    case 8:lJaguati->setVisible(visible);
        break;
    }

    if(visible == false)
        countItens --;
    else
        countItens ++;
}

void sideBar::subAlert()
{
    countAlert --;

    setAlert(countAlert, false);
}

void sideBar::plusAlert()
{
    countAlert ++;

    setAlert(countAlert, false);
}

