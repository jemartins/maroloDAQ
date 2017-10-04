#ifndef GUIRECEIVER_H
#define GUIRECEIVER_H
#include <QMainWindow>

#define _ALLOC
#include "simplProto.h"
#include "loggerVars.h"

_ALLOC unsigned int globalMask;
_ALLOC char inArea[MAX_MSG_SIZE];
_ALLOC char outArea[MAX_MSG_SIZE];
#undef _ALLOC

namespace Ui {
class guiReceiver;    
}

class guiReceiver : public QMainWindow
{
    Q_OBJECT

public:
    explicit guiReceiver(QWidget *parent = 0);
    ~guiReceiver();
    
private slots:
    void on_pbSair_clicked();

private:
    Ui::guiReceiver *ui;
};

#endif // GUIRECEIVER_H
