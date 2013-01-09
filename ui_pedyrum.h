/********************************************************************************
** Form generated from reading UI file 'pedyrum.ui'
**
** Created: Wed Jul 4 19:00:41 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PEDYRUM_H
#define UI_PEDYRUM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pedyrum
{
public:
    QWidget *wCenter;

    void setupUi(QMainWindow *Pedyrum)
    {
        if (Pedyrum->objectName().isEmpty())
            Pedyrum->setObjectName(QString::fromUtf8("Pedyrum"));
        Pedyrum->resize(819, 587);
        wCenter = new QWidget(Pedyrum);
        wCenter->setObjectName(QString::fromUtf8("wCenter"));
        Pedyrum->setCentralWidget(wCenter);

        retranslateUi(Pedyrum);

        QMetaObject::connectSlotsByName(Pedyrum);
    } // setupUi

    void retranslateUi(QMainWindow *Pedyrum)
    {
        Pedyrum->setWindowTitle(QApplication::translate("Pedyrum", "Pedyrum", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Pedyrum: public Ui_Pedyrum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PEDYRUM_H
