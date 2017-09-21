#include "guistim.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    guiStim w;
    w.show();

    return a.exec();
}
