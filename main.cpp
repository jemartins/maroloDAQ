#include "maroloDAQ.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    maroloDAQ w;
    w.show();

    return a.exec();
}
