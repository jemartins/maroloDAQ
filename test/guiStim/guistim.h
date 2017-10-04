#ifndef GUISTIM_H
#define GUISTIM_H
#include <QWidget>

#include "simplProto.h"

namespace Ui {
class guiStim;
}

class guiStim : public QWidget
{
    Q_OBJECT

public:
    explicit guiStim(QWidget *parent = 0);
    ~guiStim();
    
private slots:
    void on_pbExit_clicked();
    void on_editSendCmd_returnPressed();
    
private:
    Ui::guiStim *ui;
    void initialize (int argc, char **argv);
};

#endif // GUISTIM_H
