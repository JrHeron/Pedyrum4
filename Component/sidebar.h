#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QWidget>
#include <QResizeEvent>
#include <QLabel>
#include <Component/label.h>
#include <QPushButton>
#include <Abstract/graphiceffects.h>

const short int const_Width = 60;
const short int SPACING = 12;
const short int SIZE_BUTTON = 48;

class sideBar : public QWidget
{
    Q_OBJECT

public:

    explicit sideBar(QWidget *parent = 0);

    // Cria os componentes.
    void createComponent();

    // Configura os componentes.
    void input();

    // Evento ativado quando a mudanças no tamanho do Widget.
    void resizeEvent(QResizeEvent *);

    void connections();

    void moveScrool(bool up);

    int countAlerts();


signals:

    void goToPanel(int index);

    void showNewAlert();

public slots:    

    // ajusta a interface
    void adjustLayout();


    void onClick_pbUp();
    void onClick_pbDown();

    void onClick_Client();
    void onClick_Treatment();
    void onClick_Stock();
    void onClick_Ordered();    
    void onClick_Functionary();    
    void onClick_Alerts();    
    void onClick_Finance();    
    void onClick_Configure();
    void onClick_Jaguati();

    void setAlert(int count, bool newAlert);

    void subAlert();

    void plusAlert();

    void setVisibleItens(short int index, bool visible);

    void checkEnableButtons();

private:
    QLabel *background;    

public:
    short int wScroolY;
    short int wScroolHeight;

    short int countItens;

    QWidget *wScrool;
    QPushButton *pbUp;
    QPushButton *pbDown;

    // Começando - botões do menu lateral

    Label *lTreatment;
    Label *lClient;
    Label *lStock;
    Label *lOrdered;
    Label *lFunctionary;    
    Label *lAlerts;    
    Label *lFinance;    
    Label *lConfigure;
    Label *lJaguati;

    // Finalizando - botões do menu lateral

    GraphicEffects *effects;

    Label *textAlert;

private:

    int countAlert;




};

#endif // SIDEBAR_H
