#include "QTReceptionSerial.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTReceptionSerial w;
    w.show();
    return a.exec();
}
