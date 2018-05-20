#ifndef PROJMAROLO_H
#define PROJMAROLO_H

#include <QMainWindow>
#include <QApplication>
#include <QActionGroup>
#include <QMessageBox>
#include <QElapsedTimer>
#include "comserial.h"
//#include "graceutils.h"

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
    void doReadings();
    double scale_temp(double adcCount);
    double readTemperature(QByteArray myCALL);
    double readAngle(QByteArray myCALL);
    double readVoltage(QByteArray myCALL);
    double scale_light(double adcCount);
    double readLight(QByteArray myCALL);
    double scale_sound(double adcCount);
    double readSound(QByteArray myCALL);

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
    //variáveis adicionas por Rafael
    QMessageBox msgBox;
    QString AdcReadString;
    // definindo o relogio
    QElapsedTimer timer;
    
};
#endif // PROJMAROLO_H
