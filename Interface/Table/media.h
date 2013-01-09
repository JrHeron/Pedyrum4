#ifndef MEDIA_H
#define MEDIA_H

#include <QWidget>
#include <QTextBrowser>
#include <Component/yesno.h>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QComboBox>
#include <Abstract/tools.h>
#include <Interface/Table/dataitem.h>

class Media : public QWidget
{
    Q_OBJECT

public:
    explicit Media(QWidget *parent = 0);

    void createComponent();

    void input();

    void resizeEvent(QResizeEvent *);

    void connections();

signals:
    void back();
    void updateData(int index, bool expor);

public slots:

    void setCountClient(int index);
    void load(int index);

private slots:
    void onClick_pbSave();
    void onClick_pbCancel();

private:
    short int _countClient;
    double _media;

    Tools t;

public:

    DataItem *_data[100];
    short int _selected;

    QTextBrowser *textBody;    
    QLabel *lTextSaveInOrdered;
    YesNo *YNSaveInOrdered;
    QSpinBox *DSBNumberPeople;
    QComboBox *cbTable;
    QPushButton *pbSave;
    QPushButton *pbCancel;

};

#endif // MEDIA_H
