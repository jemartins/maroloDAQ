#ifndef QUISTIM_H
#define QUISTIM_H

#include <QMainWindow>

namespace Ui {
class quiStim;
}

class quiStim : public QMainWindow
{
    Q_OBJECT

public:
    explicit quiStim(QWidget *parent = 0);
    ~quiStim();

private slots:
    void on_pushButton_clicked();

private:
    Ui::quiStim *ui;
};

#endif // QUISTIM_H
