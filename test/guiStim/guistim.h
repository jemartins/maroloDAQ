#ifndef GUISTIM_H
#define GUISTIM_H

#include <QWidget>

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

    void on_pbSend_clicked();

    void on_editSendCmd_returnPressed();

private:
    Ui::guiStim *ui;
};

#endif // GUISTIM_H
