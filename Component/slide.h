#ifndef SLIDE_H
#define SLIDE_H

#include <QWidget>
#include <Component/label.h>
#include <Abstract/graphiceffects.h>
#include <QTimer>
#include <QStackedWidget>
#include <QPropertyAnimation>
#include <QDesktopServices>
#include <QUrl>
#include <QPoint>

const char RIGHT_ARROW[30] = ":/Extras/Slide-arrow-right";
const char LEFT_ARROW[30] = ":/Extras/Slide-arrow-left";

const char ITEM[30] = ":/Extras/point";
const char ITEM_HOVER[30] = ":/Extras/point-hover";
const char CURRENT_ITEM[30] = ":/Extras/point-alternate";

const char URL_SLIDE0[30] = "";
const char URL_SLIDE1[30] = "";
const char URL_SLIDE2[30] = "";
const char URL_SLIDE3[30] = "";
const char URL_SLIDE4[30] = "";

class Slide : public QWidget
{
    Q_OBJECT

public:

    explicit Slide(QWidget *parent = 0);

    void createComponent();

    void connections();

    void setDelay(short int time);

    void setSlide(short int index, QString url);

    void resizeEvent(QResizeEvent *);

    int currentIndex();

    void startTransicao();

    void selectButton(short int index);

    int countPage();

signals:

    void onNow(bool b);

public slots:

    void input();

    void adjustLayout();

    void mouseOn();

    void setCurrentIndex(short int index);

    void nextSlide();

    void NextSlide(short int index);

    void setCurrentPage(short int current);

    void onClick_lRightArrow();

    void onClick_lLefttArrow();

    void onClick_lB0();
    void onClick_lB1();
    void onClick_lB2();
    void onClick_lB3();
    void onClick_lB4();

    void onClick_slide0();
    void onClick_slide1();
    void onClick_slide2();
    void onClick_slide3();
    void onClick_slide4();

    void mouseOn_slide(bool b);

public:

    QTimer *Delay;
    QTimer *timerPoint;

    Label *lRightArrow;
    Label *lLefttArrow;

    Label *lB0;
    Label *lB1;
    Label *lB2;
    Label *lB3;
    Label *lB4;

    Label *Slide0;
    Label *Slide1;
    Label *Slide2;
    Label *Slide3;
    Label *Slide4;

    QPropertyAnimation *next;
    QPropertyAnimation *back;

    GraphicEffects *effetcs;

private:

    short int currentIndex_;
    short int countPage_;
    short int countDelay_;
    short int interval_;

    bool isStarted;

    QPoint point;
    bool isOn;




};

#endif // SLIDE_H

