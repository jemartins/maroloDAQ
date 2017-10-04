#include "include/guireceiver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    guiReceiver w;
    w.show();

    return a.exec();
}
