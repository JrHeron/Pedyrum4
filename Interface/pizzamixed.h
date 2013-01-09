#ifndef PIZZAMIXED_H
#define PIZZAMIXED_H

#include <QWidget>
#include <QLabel>
#include <Component/tableview.h>
#include <Component/search.h>
#include <Component/combobox.h>
#include <QPushButton>
#include <Abstract/graphicsreport.h>
#include <Object/pizza.h>
#include <Abstract/datamodel.h>
#include <Component/spinbox.h>
#include <Component/doublespinbox.h>
#include <QKeyEvent>
#include <QStackedWidget>
#include <QTextEdit>
#include <QAction>

class PizzaMixed : public QWidget
{
    Q_OBJECT
public:
    explicit PizzaMixed(QWidget *parent = 0);

    void createComponent();
    void statics();
    void connections();

signals:
    void emitPizzaMista(QList<int> listOrderPartProduct, QList<QString> listOrderIdProduct, QList<QString> listOrderNameProduct, QString note, int quantity, double value, QString size, bool insert, int row);
    
public slots:
    void input();

    void editPizzaMixed(QList<int> listOrderPartProduct, QList<QString> listOrderIdProduct, QList<QString> listOrderNameProduct, QString note, int quantity, double value, QString size, int row);

private slots:
    void getSearchProduct(QString text);

    void valueChanged_SBPart(int value);

    void suggestValues(QString size);

    void onClick_pbRemoveItem();

    void onClick_pbAddItem();

    void onClick_pbLeave();

    void onClick_pbConfirm();

    void onClick_lNote();

    void returnPressed_sbPart();

    void keyPressEvent(QKeyEvent *event);

    void onTriggered_actionName();

    void onTriggered_actionNickName();

private:
    void updateCbSizes();

    void clearAll();

public:

    Pizza *pizza;

    QLabel *lBackground;

    QStackedWidget *swPanel;

    QWidget * wGraphicView;

    Search *search;

    QPushButton *pbAddItem;

    QPushButton *pbRemoveItem;

    TableView *tablePizza;

    ComboBox * cbSize;

    DoubleSpinBox * DSBValue;

    SpinBox * SBAmount;

    Label *lNote;


    QWidget *wNotes;

    QLabel *lTextNote;

    QTextEdit *teNotePizza;

    //    SpinBox * SBPart;
    SpinBox * SBPart;

    QPushButton *pbConfirm;

    QPushButton *pbLeave;

    GraphicsReport *graphics;

    DataModel *model;

    QList<QString> listSizes;

    QString size;
    QString qnt;

    // dados do produto atualmente selecionado
    int dataOrderPartProduct;
    QString dataOrderIdProduct;
    QString dataOrderNameProduct;
    QList<QString> dataOrderSizesProduct;
    QList<QString> dataOrderValuesProduct;

    double totalValueOrder;
    double totalValueOrderProducts;

    QString note;

    // lista de todos os produtos adicionados na lista
    QList<int> listOrderPartProduct;
    QList<QString> listOrderIdProduct;
    QList<QString> listOrderNameProduct;
    QList<QList< QString> > listOrderValuesProduct;
    QList<QList< QString> > listOrderSizesProduct;

    QAction *actionName;
    QAction *actionNickName;

    int indexSelectedItem;

    int indexUpdate;

};

#endif // PIZZAMIXED_H
