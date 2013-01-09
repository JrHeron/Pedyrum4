#include "selectdeliverer.h"

SelectDeliverer::SelectDeliverer(QWidget *parent) :
    QWidget(parent)
{
    createComponent();

    statics();

    input();

    connections();
}

void SelectDeliverer::createComponent()
{
    lBackground = new QLabel(this);

    lTitle = new QLabel(this);

    cbWaiters = new ComboBox(this);

    textAlert = new QTextBrowser(this);

    pbConfirm = new QPushButton(this);
}

void SelectDeliverer::statics()
{
    lTitle->setGeometry(20, 10, 200, 20);

    cbWaiters->setGeometry(20, 40, 200, 28);

    textAlert->setGeometry(10, 70, 220, 60);

    pbConfirm->setGeometry(75, textAlert->y() + textAlert->height(), 90, 28);
}

void SelectDeliverer::connections()
{
    connect(pbConfirm, SIGNAL(clicked()), SLOT(onClick_pbConfirm()));
}

void SelectDeliverer::resizeEvent(QResizeEvent *)
{
    lBackground->setGeometry(0,0,this->width(),this->height());
}

void SelectDeliverer::input()
{
    lBackground->setStyleSheet("background-color: rgba(0,0,0,140);"
                               "border: 10px solid rgba(0,0,0,50);");
    QFont f;

    f.setPointSize(10);

    lTitle->setText(tr("Selecione o entregador:"));
    lTitle->setStyleSheet("color: rgba(255,255,255,240);");
    lTitle->setFont(f);

    f.setPointSize(9);

    textAlert->setText(tr("Não se esqueça de marcar o entregador como"
                       " livre após o retorno ao estabelecimento."));

    textAlert->setStyleSheet("background-color: rgba(0,0,0,0);"
                             "color: rgba(255,255,255,240);");

    textAlert->setAlignment(Qt::AlignCenter);

    textAlert->setFont(f);

    pbConfirm->setText(tr("Confirmar"));
}

void SelectDeliverer::setWaiters(QList<QString> namesWaiters, QList<QString> idsWaiters)
{
    cbWaiters->clear();

    cbWaiters->addItems(namesWaiters);

    this->idsWaiters = idsWaiters;
}

void SelectDeliverer::onClick_pbConfirm()
{
    emit sendDeliverer(idsWaiters[cbWaiters->currentIndex()]);

    this->close();
}
