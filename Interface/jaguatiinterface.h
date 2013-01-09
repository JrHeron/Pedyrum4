#ifndef JAGUATIINTERFACE_H
#define JAGUATIINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <Component/label.h>
#include <QKeyEvent>
#include <QMessageBox>

class JaguatiInterface : public QWidget
{
    Q_OBJECT
public:
    explicit JaguatiInterface(QWidget *parent = 0);

    void createComponent();

    void connections();

    void resizeEvent(QResizeEvent *);

signals:
    void goToPanel(int);

    void fullScreen();

public slots:
    void keyPressEvent(QKeyEvent *event);

    void input();

    void adjustLayout();

    void onClick_lTwitterHeron();

    void onClick_lTwitterVegan();

    void onClick_lLinkLicense();

    void onClick_lLinkJaguati();

    void onClick_lLinkSource();

    void onClick_lLinkQt();

public:

    QWidget *wCenter;
    QLabel *lCenter;
    QLabel *lFooter;

    QLabel *lThank;

    QLabel *lNokia;
    QLabel *lContactNokia;
    QLabel *lContributionNokia;

    QLabel *lDavid;
    QLabel *lContactlDavid;
    QLabel *lContributionlDavid;

    QLabel *lCreators;

    QLabel *lHeron;
    QLabel *lEmailHeron;
    Label *lTwitterHeron;

    QLabel *lVegan;
    QLabel *lEmailVegan;
    Label *lTwitterVegan;

    QLabel *lImage;

    Label *lLinkLicense;
    Label *lLinkJaguati;
    Label *lLinkSource;
    Label *lLinkQt;

private:
    QString _linkHeron;
    QString _linkVegan;

    QString _linkLicense;
    QString _linkJaguati;
    QString _linkSource;
};

#endif // JAGUATIINTERFACE_H

