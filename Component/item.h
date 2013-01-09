#ifndef ITEM_H
#define ITEM_H

#include <QWidget>
#include <QLabel>
#include <QFont>
#include <Component/label.h>

class Item : public QWidget
{
    Q_OBJECT
public:
    explicit Item(QWidget *parent = 0, QString urlImage = "null",QString text = "text" );

    void createComponent();

    void setImage(QString urlImage);

    void setText(QString text);

    void setFont(QFont f);

    void setStyle(QString style);

    void setHover(QString style);

    void resizeEvent(QResizeEvent *);

    void setFontColor(QString styleCor);

    void setStandard(QString style);

signals:

    void onClick();

public slots:

    void showHover(bool b);

    void onClick_space();

    void adjustLayout();


private:

    QLabel *image;

    QLabel *lBody;

    Label *space;

    QString Style;

    QString StyleStandard;

};

#endif // ITEM_H
