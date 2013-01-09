#include <QtGui/QApplication>
#include "pedyrum.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Pedyrum w;
    w.show();
    
    return a.exec();
}
