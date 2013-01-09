#ifndef PHONEEDIT_H
#define PHONEEDIT_H

#include <Component/edit.h>

class phoneEdit : public Edit
{
    Q_OBJECT
public:
    explicit phoneEdit(QWidget *parent = 0, bool usesClear = true,
                        QString standard = "", int maximumLetters = 255);

    bool eventFilter(QObject *target, QEvent *event);

    int posO;
    int posN;

    bool del;
signals:

public slots:
    void textChanged(QString text);

    void cursorPositionChanged(int posO, int posN);

};

#endif // PHONEEDIT_H
