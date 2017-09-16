#ifndef PROJMAROLO_H
#define PROJMAROLO_H

#include <QMainWindow>
#include <QApplication>
#include <QActionGroup>
#include "comserial.h"

namespace Ui {
class maroloDAQ;
}

class maroloDAQ : public QMainWindow
{
    Q_OBJECT

public:
    explicit maroloDAQ(QWidget *parent = 0);
    ~maroloDAQ();

private slots:

    void WriteData(const QByteArray data);

    void findMaroloDAQ();
    
    void scanPortas();

    void maroloDevClose();

    QString ReadData();

    void on_btnDevOpen_clicked();

    void on_btnDevClose_clicked();

    void on_btnCalibrarSensor_clicked();

    void on_btnBWTerminal_clicked();

    void on_btnIniciar_clicked();

    void on_btnParar_clicked();

    void on_btnAppClose_clicked();

    void on_actionSalvar_como_triggered();

    void on_actionSalvar_triggered();

    void on_actionSair_triggered();

    void on_actionConectar_triggered();

    void on_actionDesconectar_triggered();

    void on_actionFerramentas_triggered();

    void on_actionRecarregar_triggered();

    void setPortasSeriais(QString myAction);

    void toggleStatusbar(QAction *viewst);

    void on_actionDevices_triggered(QAction*);

    //void on_actionACM0_triggered();

    //void on_actionS0_triggered();

private:
    Ui::maroloDAQ *ui;

    bool PaletaLogBW;
    QSerialPort *devserial;
    comserial *procSerial;
    void CarregarInfoDispSerial(void);
    QAction *viewst;
    QAction *actionACM0;
    QAction *actionS0;
    void enumerateMenu(QMenu *menu);
    //QActionGroup *PortasGroup(QMenu *menu);
    QActionGroup *PortasGroup;

};

typedef enum
        {
        devttyACM0=1,
        devttyACM1,
        devttyACM2,
        devttyACM3,
        devttyS0,
        devttyS1,
        devttyS2,
        devttyS3,
        MAX_NUM_marolo_SERIAL
        }marolo_SERIAL;

#endif // PROJMAROLO_H
