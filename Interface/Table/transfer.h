#ifndef TRANSFER_H
#define TRANSFER_H

#include <QWidget>
#include <QLabel>
#include <Component/combobox.h>
#include <QPushButton>
#include <Interface/Table/dataitem.h>

class Transfer : public QWidget
{
    Q_OBJECT
public:
    explicit Transfer(QWidget *parent = 0);

    void createComponent();

    void input();

    void resizeEvent(QResizeEvent *);

    void adjustLayout();

    void connections();

signals:

    void back();

    void updateData(int index, bool expor);

public slots:

    void onClick_pbBack();

    void onClick_pbSave();

    void onClick_pbSeparate();

    void load(int index);

public:
    DataItem *_data[100];

    QLabel *textSubsidized;
    QLabel *textBuyer;
    ComboBox *cbSubsidized;
    ComboBox *cbBuyer;
    QPushButton *pbSave;
    QPushButton *pbBack;
    QPushButton *pbSeparate;

};

#endif // TRANSFER_H
