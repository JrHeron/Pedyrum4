#ifndef PRODUCTINTERFACE_H
#define PRODUCTINTERFACE_H

#include <QWidget>
#include <Component/label.h>
#include <Component/edit.h>
#include <Component/tableview.h>
#include <QTextBrowser>
#include <QStackedWidget>
#include <Component/doublespinbox.h>
#include <QTextEdit>
#include <QPushButton>
#include <QSplitter>
#include <Abstract/graphiceffects.h>
#include <Abstract/datamodel.h>
#include <Component/search.h>
#include <Component/combobox.h>
#include <QPropertyAnimation>
#include <Object/product.h>
#include <QAction>
#include <QKeyEvent>

class ProductInterface : public QWidget
{
    Q_OBJECT
public:
    explicit ProductInterface(QWidget *parent = 0);

    void createComponent(); // Cria os componentes na tela.

    void connections();     // cria as coneções.
    void hidePanel(bool b);
    void statics();         // alinha o layout estático.

    QString createPreview();

    void updateCbCategory();

    int textCountProductSize();

private:
    void resizeEvent(QResizeEvent *);
    bool isSelectEmpty();
    bool isAvailable();

    // add os novos preços a tabela de valores
    void addDataValue();

signals:
    void goToPanel(int);

    void fullScreen();

private slots:
    void onClick_lAdd();
    void onClick_lRemove();
    void onClick_lProfile();
    void onClick_pbConfirm();
    void onClick_pbLeave();
    void onClick_addValue();
    void onClick_removeValue();
    void getSearchProduct(QString text);
    void textChanged_eCategory(QString text);
    void textChanged_eSize(QString text);

    void onDoubleClick_tbProduct(QModelIndex index);
    void onClick_tbProduct(QModelIndex index);
    void rowChanged_tbProduct(int row);

    void adjustSplitter();

    void updateCountProducts(QString qnt);
    void updateCbSubCategory(QString nameCategory);
    void filterSubCategory(QString nameSection);

public slots:
    void logout();

    void onClick_tbValue(QModelIndex);
    void adjustLayout();
    void gotoPanel(int index);
    void nextPanel();
    void input();

    void keyPressEvent(QKeyEvent *event);

    void onTriggered_actionName();

    void onTriggered_actionNickName();


public:
    enum typeSearch{
        NAME = 0,
        NICKNAME = 1
    };

    typeSearch typeS;

    int idProductUpdate;

    short int nextPanelIndex;

    QLabel *lTop;

    Label *lAdd;
    Label *lRemove;
    Label *lProfile;
    QTextBrowser *textCountProduct;
    ComboBox * cbCategory;
    ComboBox * cbSection;
    Search *searchProduct;

    QWidget *wSpace;
    QLabel *lBackgroundSpace;

    QStackedWidget *swPanels;

    TableView *tableProduct;
    QSplitter *splitter;

    QWidget *wGroupPlus;
    QLabel *lBackgroundPlus;

    Edit *eName;
    Edit *eNickname;
    Edit *eCategory;
    Edit *eSection;
    Edit *eSize;

    DoubleSpinBox *DSBValue;
    QPushButton *pbAddValue;
    QPushButton *pbRemoveValue;
    TableView *tableValues;

    QLabel *lTextNotes;
    QTextEdit  *teNotes;

    QPushButton *pbConfirm;
    QPushButton *pbLeave;

    QWidget *wGroupProfile;
    QLabel *lBackgroundProfile;
    QTextBrowser *textPreview;
    
    GraphicEffects *panelEffects;

    QPropertyAnimation  *  animaUp;
    QPropertyAnimation  *  animaDown;

    Product *product;

    QLabel *lEmpty;

    DataModel *dataModel;

    QAction *actionName;
    QAction *actionNickName;

private:
    bool isAdd;
    bool isSelect;

    QList<QString> listSizes;
    QList<QString> listValues;
};

#endif // PRODUCTINTERFACE_H
