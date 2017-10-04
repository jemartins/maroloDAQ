#include <qtimer.h>
#include <qpainter.h>
#include <qapplication.h>
#include <stdlib.h>                             // defines rand() function

#include "forever.h"

//
// Forever - a widget that draws rectangles forever.
//

//
// Constructs a Forever widget.
//

Forever::Forever( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
    for (int a=0; a<numColors; a++) {
        colors[a] = QColor( rand()&255,
                            rand()&255,
                            rand()&255 );
    }
    rectangles = 0;
    startTimer( 0 );                            // run continuous timer
    QTimer * counter = new QTimer( this );
    connect( counter, SIGNAL(timeout()),
             this, SLOT(updateCaption()) );
    counter->start( 1000 );
}

void Forever::updateCaption()
{
    QString s;
    s.sprintf( "forever - %d rectangles/second", rectangles );
    rectangles = 0;
    setCaption( s );
}

//
// Handles timer events for the Forever widget.
//

void Forever::timerEvent( QTimerEvent * )
{
    QPainter paint( this );                     // painter object
    paint.setPen( NoPen );                      // do not draw outline
    int w = width();
    int h = height();
    for ( int i=0; i<100; i++ ) {
        paint.setBrush( colors[i % numColors]); // set random brush color
        QPoint p1( rand()%w, rand()%h );        // p1 = top left
        QPoint p2( rand()%w, rand()%h );        // p2 = bottom right
        QRect r( p1, p2 );
        paint.drawRect( r );                    // draw filled rectangle
        rectangles++;
    }
}
