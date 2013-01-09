#ifndef EDIT_H
#define EDIT_H

#include <QLineEdit>
#include <Component/label.h>
#include <QVariant>
const char url_clear[25] = ":/Extras/clear";

class Edit : public QLineEdit
{
    Q_OBJECT
public:

    explicit Edit(QWidget *parent = 0, bool usesClear = true,
                  QString standard = "", int maximumLetters = 255);

    void resizeEvent(QResizeEvent *);
    void focusInEvent(QFocusEvent *e);
    void focusOutEvent(QFocusEvent *e);    
    void setClear();    
    void checkClears();
    bool isEmpty();
    QString value();
    QString upper();
    void setInputMask(QString Mask);
    void clearMask();

    bool eventFilter(QObject *target, QEvent *event);

    void setNextComponent(QWidget *next);

    void connections();

    bool isUpperCase();

    void setUpperCase(bool upperCase);

    void setAutomaticallyNextComponent(bool set);

signals:
    void inFocus(bool);
    void positionChanged(int arg1, int arg2);

public slots:
    void cursorPositionChanged(int arg1, int arg2);
    void textChanged(const QString &);

    void checkEditText(QString text);
    void checkClear(bool check);
    void Clear();

    void toUpperCase(QString text);

public:
    bool useClear;    
    Label *button;
    QString valueStandart;
    bool isMask;

    bool upperCase;

    bool automaticallyNextComponent;

    QWidget *nextComponent;

    bool hasNext;

private:
    QString mask;

};

#endif // EDIT_H
