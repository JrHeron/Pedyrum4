#ifndef LABELBUTTON_H
#define LABELBUTTON_H

#include <QLabel>
#include <QMouseEvent>
#include <QObject>
#include <QWidget>
#include <QTimer>
#include <QRgb>

class Label : public QLabel
{
    Q_OBJECT
public:    
    explicit Label(QWidget *parent = 0, bool allFunction = false, short int time = 250);
    void setColor(short int r = 0, short int g = 0, short int b = 0, short int a = 255);
    void setColor(QColor rgba);
    QColor Color();
    void setImage(QString url);
    void setHover(QString url);
    void setAlternateImage(QString url);
    void setAlternate(bool b);

    void setHoverStyle(QString style);
    void setStandartStyle(QString style);

signals:
    void onClick();
    void onDoubleClick();
    void mouseOnImage(bool);


protected:
    void mousePressEvent(QMouseEvent *e);

    void mouseDoubleClickEvent(QMouseEvent *e);

public slots:
    void mouseOn();

public:

    QTimer *openFileTimer;
    QPoint point;

    QString imageHover;
    QString imagePressed;
    QString imageStandart;
    QString imageAlternate;

    QString styleHover;
    QString styleStandart;

    bool isOn;
    bool isAlternate;

    QColor color;
    int alpha;

};

#endif // LABELBUTTON_H
