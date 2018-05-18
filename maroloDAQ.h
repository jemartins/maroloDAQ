#ifndef PROJMAROLO_H
#define PROJMAROLO_H

#include <QMainWindow>
#include <QApplication>
#include <QActionGroup>
#include "comserial.h"
#include <QMessageBox>
#include <QTimer>
#include <QTime>
#include <sleeper.h>

namespace Ui {
class maroloDAQ;
}

class maroloDAQ : public QMainWindow
{
    Q_OBJECT

public:
    explicit maroloDAQ(QWidget *parent = 0);
    ~maroloDAQ();
    bool teste;

private slots:

    void WriteData(const QByteArray data);

    void scanPortas();

    void setDesconectado();

    void setConectado();

    void maroloDevClose();

    void on_btnDevOpen_clicked();

    void on_btnDevClose_clicked();

    void on_btnBWTerminal_clicked();

    void on_btnIniciar_clicked();

    void on_btnParar_clicked();

    void on_btnAppClose_clicked();

    void on_actionSalvar_como_triggered();

    void on_actionSalvar_triggered();

    void on_actionSair_triggered();

    void on_actionConectar_triggered();

    void on_actionDesconectar_triggered();

    void on_actionRecarregar_triggered();

    void setPortasSeriais(QString myAction);

    void on_cbSensorList_activated(const QString &arg1);

    bool validarEntradas();

    QString ReadData();

    //void doReadings();

    //int scale_temp(int adcCount);

    //double readTEMPERATURE(QByteArray AdcReadString);


private:
    Ui::maroloDAQ *ui;
    bool PaletaLogBW;
    QSerialPort *devserial;
    comserial *procSerial;
    void CarregarInfoDispSerial(void);
    QAction *viewst;
    QAction *actionACM0;
    QAction *actionACM1;
    QAction *actionACM2;
    QAction *actionACM3;
    QAction *actionS0;
    QAction *actionS1;
    QAction *actionS2;
    QAction *actionS3;
    void enumerateMenu(QMenu *menu);
    QActionGroup *PortasGroup;
    QMessageBox msgBox;
    QByteArray myCALL;
    //novo objeto que faz a amostra das medidas
    Sleeper *amostra = new Sleeper();
};
#endif // PROJMAROLO_H
