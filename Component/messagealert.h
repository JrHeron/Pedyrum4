#ifndef MESSAGEALERT_H
#define MESSAGEALERT_H

#include <QWidget>
#include <QLabel>
#include <Component/label.h>
#include <QTextBrowser>
#include <QTimer>
#include <Object/messageobject.h>

const char URL_CLOSE[30] = ":/Extras/close-message";

class MessageAlert : public QWidget
{
    Q_OBJECT
public:
    explicit MessageAlert(QWidget *parent = 0);

    explicit MessageAlert(QWidget *parent, MessageObject *msg);

    void createComponent();

    void resizeEvent(QResizeEvent *);

    void connections();

signals:
    void hideMessage();

public slots:

    void adjustLayout();

    void input();

    void setMessage(MessageObject *msg);

    MessageObject* message();

    void onClick_lClose();

    void startDelay();

private:        
    MessageObject *messageObject;

    QLabel *lBackground;
    QLabel *lImage;
    QLabel *lTitle;
    QTextBrowser *tbText;
    Label * lClose;

    QTimer *timerShow;

};

#endif // MESSAGEALERT_H
