#ifndef USERMENU_H
#define USERMENU_H

#include <QWidget>
#include <Component/label.h>
#include <QUrl>
#include <QDesktopServices>
#include <QKeyEvent>

class UserMenu : public QWidget
{
    Q_OBJECT
public:
    explicit UserMenu(QWidget *parent = 0);

    void createComponent();

    void resizeEvent(QResizeEvent *);

    void connections();

    void adjustLayout();

    void input();

signals:    
    void configure();

    void logout();

    void fullScreen();

public slots:

    void keyPressEvent(QKeyEvent *event);

    void showMenu();

    void onClick_lHelp();

    void onClick_lLogout();

    void onClick_lConfigure();

private:
    Label *lBackground;

    Label *lConfigure;
    Label *lLogoConfigure;

    Label *lLogout;
    Label *lLogoLogou;

    Label *lHelp;
    Label *lLogoHelp;
};

#endif // USERMENU_H
