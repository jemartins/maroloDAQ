#include <QApplication>
#include "forever.h"

int main( int argc, char **argv )
{
    QApplication a( argc, argv );               // create application object
    Forever always;                             // create widget
    a.setMainWidget( &always );                 // set as main widget
    always.show();

    return a.exec();                            // run event loop
}
