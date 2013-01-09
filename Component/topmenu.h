#ifndef TOPMENU_H
#define TOPMENU_H

#include <QWidget>
#include <Component/label.h>
#include <QResizeEvent>
#include <QPropertyAnimation>

const char url_MenuSuperior[50] = ":/topMenu/background";
const int const_Height = 28;

class topMenu : public QWidget
{
    Q_OBJECT
public:
    explicit topMenu(QWidget *parent = 0);

    void createComponent();  // Cria os componentes.

    void setComponent();     // Configura os componentes.

    void resizeEvent(QResizeEvent *); // evento ativado quando a mudanças
                                      // no tamanho do Widget.

    QString firstName(QString name); // ajusta o apelido para ficar apresentável
                                     // no menu superior.

    int sizeNickName(QString name); // retorna o tamanho do nickname

    void setNickName(QString text);

    void ajustLayout(); // ajusta a interface

signals:
   void sideVisible(bool b);
   void FullScreen(bool b);
   void userClick();


public slots:

    // Ajusta a largura da barra superior
    void goResize(int width_, int height_);    
    void onFocus_menuButton(bool b);    
    void onClick_fullScreen();

    void onClick_nickName();


public:

    QLabel *background;
    Label *fullScreen;
    Label *menuButton;
    Label *trayIco;
    Label *nickName;

    bool isOnMenu;

    bool visible;
    bool activateFocus;
    QString nickNameText;

};

#endif // TOPMENU_H
