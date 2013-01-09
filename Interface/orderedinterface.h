#ifndef ORDEREDINTERFACE_H
#define ORDEREDINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <Component/label.h>
#include <QTextBrowser>
#include <Component/search.h>
#include <Component/tableview.h>
#include <Component/combobox.h>
#include <QPushButton>
#include <Object/ordered.h>
#include <Abstract/tools.h>
#include <Interface/selectdeliverer.h>
#include <QAction>
#include <Object/makehtml.h>
#include <QKeyEvent>

class OrderedInterface : public QWidget
{
    Q_OBJECT
public:
    explicit OrderedInterface(QWidget *parent = 0);

    void createComponent();

    void statics();

    void connections();

    void resizeEvent(QResizeEvent *);

    void setProfileVisible(bool b);

    void insertItemsInTable();

    int textCountOrderedSize();

    void updateCountOrdered(QString qnt);

    void showSelectDeliveres();

signals:    
    void gotoPanel(int index, int index2, int idOrder = 0); // 0 é no caso do novo pedido, que não tem edição

    void goToPanel(int);

private slots:
    void keyPressEvent(QKeyEvent *event);

    void onClick_lAdd();
    void onClick_lRemove();
    void onClick_lProfile();

signals:
    void fullScreen();

public slots:

    void input();

    void adjustLayout();

    void onClick_pbAll();

    void onClick_pbToday();

    void onClick_pbFree();

    void onClick_pbOccupied();

    void clicked_tableOrdered(QModelIndex index);

    void clicked_tableFunctionary(QModelIndex index);

    void currentIndexChanged_cbChangeStatusDelegate(QString text);

    void currentIndexChanged_cbStatus(QString text);

    void doubleClicked_tableOrdered(QModelIndex index);

    void setFilterModel();

    void updateDataFuncionary(QString id);

    void getSearchEmployee(QString text);

    void onTriggered_actionPhone();

    void onTriggered_actionDate();

    void onTriggered_actionHour();

    void onClick_pbPrint();

    void onClick_pbPDF();

    void rowChanged_tableOrdered(int row);

public:
    MakeHTML *makeHTML;

    Ordered *ordered;

    ComboBox *cbChangeStatusDelegate;

    bool isProfileShow;

    bool isShowDeliverer;

    QLabel *lTop;

    Label *lAdd;
    Label *lRemove;
    Label *lProfile;
    QTextBrowser *textCountOrdered;

    ComboBox *cbShowType;
    ComboBox *cbShowStatus;

    QPushButton *pbToday;
    QPushButton *pbAll;

    Search *searchOrdered;
    QAction *actionPhone;
    QAction *actionDate;
    QAction *actionHour;

    TableView *tableOrdered;

    QWidget *wViewOrdered;
    QLabel *lViewOrdered;
    QPushButton *pbPDF;
    QPushButton *pbPrint;
    QLabel *lStatusStatic;
    QLabel *lStatus;
    QTextBrowser *teView;

    QWidget *wFunctionary;
    QLabel *lFunctionary;
    Search *searchFunctionary;
    ComboBox *cbStatus;
    QPushButton *pbFree;
    QPushButton *pbOccupied;
    TableView *tableFunctionary;

    Tools tools;

    bool isToday;

    SelectDeliverer *selectDeliverer;

    QString currentIdOrder;
};

#endif // ORDEREDINTERFACE_H

