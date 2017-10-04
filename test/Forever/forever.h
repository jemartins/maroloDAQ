#ifndef FOREVER_H
#define FOREVER_H

#include <qwidget.h>

const int numColors = 120;

class Forever : public QWidget
{
    Q_OBJECT
public:
    Forever( QWidget *parent=0, const char *name=0 );
protected:
    void        timerEvent( QTimerEvent * );
private slots:
    void        updateCaption();
private:
    int         rectangles;
    QColor      colors[numColors];
};

#endif
