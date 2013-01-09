#include "Interface/tableinterface.h"
#include <QDebug>
#include <QMessageBox>

TableInterface::TableInterface(QWidget *parent) :
    QWidget(parent)
{
    createComponent();    
    connections();
}

void TableInterface::createComponent()
{
    wPaymentView = new PaymentView(this);

    wGroupDesk = new GroupDesk(this);

    wItens = new QWidget(this);
    lItens = new QLabel(wItens);

    pbSaveOrdered = new QPushButton(wItens);
    pbRemoveItem = new QPushButton(wItens);
    pbClearOrdered = new QPushButton(wItens);
    pbCancelOrdered = new QPushButton(wItens);

    tableItem = new TableView(wItens);

    order = new Order("connectionTable");
}

void TableInterface::input()
{
    wGroupDesk->wTreatmentTable->setTableItem(tableItem);

    wPaymentView->canAddPaymentForm = false;

    lItens->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0.498,"
                          "y1:0, x2:0.494636, y2:1, stop:0 rgba(255, 255, 255, 210),"
                          "stop:0.982955 rgba(255, 255, 255, 170));"
                          "border-radius: 5px;border: 1px solid rgba(255,255,255,255);");

    pbSaveOrdered->setObjectName("pbSaveOrdered");
    pbSaveOrdered->setStyleSheet(this->styleSheet());
    pbSaveOrdered->setText(tr("Salvar"));
    pbSaveOrdered->setFont(this->font());
    pbSaveOrdered->setCursor(Qt::PointingHandCursor);

    pbRemoveItem->setObjectName("pbRemoveItem");
    pbRemoveItem->setStyleSheet(this->styleSheet());
    pbRemoveItem->setText(tr("Remover"));
    pbRemoveItem->setFont(this->font());
    pbRemoveItem->setCursor(Qt::PointingHandCursor);

    pbClearOrdered->setObjectName("pbClearOrdered");
    pbClearOrdered->setStyleSheet(this->styleSheet());
    pbClearOrdered->setText(tr("Limpar"));
    pbClearOrdered->setFont(this->font());
    pbClearOrdered->setCursor(Qt::PointingHandCursor);

    pbCancelOrdered->setObjectName("pbCancelOrdered");
    pbCancelOrdered->setStyleSheet(this->styleSheet());
    pbCancelOrdered->setText(tr("Cancelar"));
    pbCancelOrdered->setFont(this->font());
    pbCancelOrdered->setCursor(Qt::PointingHandCursor);

    wGroupDesk->setPaymentView(wPaymentView);

    wGroupDesk->setTableItem(tableItem);

    wGroupDesk->wTreatmentTable->setPaymentView(wPaymentView);

    emit setInput();
}

void TableInterface::adjustLayout()
{
    wPaymentView->setGeometry(this->width() - 280,0,280,this->height());

    wItens->setGeometry(0,this->height() * 0.55,this->width() - wPaymentView->width(),this->height() * 0.45);
    lItens->setGeometry(5,0,wItens->width() - 10,wItens->height() - 5);

    wGroupDesk->setGeometry((this->width() - wPaymentView->width())/2 - 300, (this->height() - wItens->height())/2 - 180, 600, 340);

    pbSaveOrdered->setGeometry(wItens->width()/2 - 195,5,90,28);
    pbRemoveItem->setGeometry(pbSaveOrdered->x() + pbSaveOrdered->width() + 10,5,90,28);
    pbClearOrdered->setGeometry(pbRemoveItem->x() + pbRemoveItem->width() + 10,5,90,28);
    pbCancelOrdered->setGeometry(pbClearOrdered->x() + pbClearOrdered->width() + 10,5,90,28);

    tableItem->setGeometry(lItens->x() + 5,38,lItens->width() - 10,wItens->height() - 50);

    tableItem->setColumnWidth(0,tableItem->width() * 0.2-1);
    tableItem->setColumnWidth(1,tableItem->width() * 0.1);
    tableItem->setColumnWidth(2,tableItem->width() * 0.1);
    tableItem->setColumnWidth(3,tableItem->width() * 0.1);
    tableItem->setColumnWidth(4,tableItem->width() * 0.5-1);
}

void TableInterface::connections()
{
    connect(this, SIGNAL(removeProduct(usint)), wGroupDesk->wTreatmentTable, SLOT(removeProduct(usint)));

    connect(this, SIGNAL(removeAllProducts()), wGroupDesk->wTreatmentTable, SLOT(removeAllProducts()));

    connect(this, SIGNAL(saveOrder()), wGroupDesk->wTreatmentTable, SLOT(saveOrder()));

    connect(tableItem, SIGNAL(doubleClicked(QModelIndex)), SLOT(doubleClicked_tableItem(QModelIndex)));

    connect(pbClearOrdered, SIGNAL(clicked()), SLOT(onClick_pbClearOrdered()));

    connect(pbRemoveItem, SIGNAL(clicked()), SLOT(onClick_pbRemoveItem()));

    connect(this,SIGNAL(setInput()),wPaymentView,SLOT(input()));

    connect(this,SIGNAL(setInput()),wGroupDesk->wTreatmentTable,SLOT(input()));
    connect(this,SIGNAL(setInput()),wGroupDesk->wTreatmentTable->wPizzaMixed,SLOT(input()));

    connect(pbCancelOrdered, SIGNAL(clicked()), SLOT(onClick_pbCancelOrdered()));

    connect(pbSaveOrdered, SIGNAL(clicked()), SLOT(onClick_pbSaveOrdered()));

    connect(this,SIGNAL(clearOrder()),wGroupDesk->wTreatmentTable,SLOT(clearOrder()));
}

void TableInterface::onClick_pbCancelOrdered()
{
    int op = QMessageBox::question(this, tr("Confirmar operação."), tr("Tem certaza que deseja cancelar esse pedido?"), tr("Sim"), tr("Não"));

    if (op == 1)
        return;
    else
    {
        if(wGroupDesk->swPages->currentIndex() == 0)
             QMessageBox::warning(this, tr("Erro"), tr("Selecione a mesa, que deseja cancelar"), QMessageBox::Ok);
        else
        {
            emit clearOrder();
        }
    }
}

void TableInterface::resizeEvent(QResizeEvent *)
{
    adjustLayout();
}


void TableInterface::onClick_pbRemoveItem(){
    int op = QMessageBox::question(this, tr("Confirmar operação."), tr("Tem certaza que deseja remover este item do pedido?"), tr("Sim"), tr("Não"));

    if (op == 0)
        if (tableItem->model()->rowCount() > 0)
            if (tableItem->currentIndex().row() >= 0)
                emit removeProduct(tableItem->currentIndex().row());
}


void TableInterface::doubleClicked_tableItem(QModelIndex index){
    wGroupDesk->wTreatmentTable->doubleClicked_tableItem(index);
}


void TableInterface::onClick_pbSaveOrdered()
{
    emit saveOrder();
}

void TableInterface::onClick_pbClearOrdered()
{
    emit removeAllProducts();
}
