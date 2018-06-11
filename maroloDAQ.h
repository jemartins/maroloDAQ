/****************************************************************************
 *
 * Project:      maroloDAQ data logger
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 *
 *
 *   autor: José Eduardo martins
 *   email: jemartins@fis.unb.br
 *          Instituto de Física
 *          Universidade de Brasília
 *   
 * programers: José Eduardo Martins
 *             Rafael Ramos [rafaelframos@gmail.com]
 *             
 ****************************************************************************/

#ifndef PROJMAROLO_H
#define PROJMAROLO_H

#include <QMainWindow>
#include <QActionGroup>
#include <QPlainTextEdit>
#include "comserial.h"
#include <grace_np.h>

namespace Ui {
class maroloDAQ;
}

class maroloDAQ : public QMainWindow
{
    Q_OBJECT

public:
    explicit maroloDAQ(QWidget *parent = 0);
    ~maroloDAQ();

protected:
    void closeEvent(QCloseEvent *event) override;
    void mousePressEvent(QMouseEvent *e);
    //void mouseDoubleClickEvent(QMouseEvent *e) override;

private slots:
    void formatarEntradas();
    void WriteData(const QByteArray data);
    void scanPortas();
    void setDesconectado();
    void setConectado();
    void maroloDevClose();
    void on_btnDevOpen_clicked();
    void on_btnDevClose_clicked();
    //void on_btnBWTerminal_clicked();
    void on_btnCalibrar1_clicked();
    void on_btnCalibrar2_clicked();
    void on_btnIniciar_clicked();
    void on_btnParar_clicked();
    void on_btnAppClose_clicked();
    bool on_actionSalvar_triggered();
    bool on_actionSalvar_como_triggered();
    void on_actionSair_triggered();
    void on_actionConectar_triggered();
    void on_actionDesconectar_triggered();
    void on_actionRecarregar_triggered();
    void on_actionSobre_triggered();
    void setPortasSeriais(QString myAction);
    void on_cbSensorList_activated(const QString &arg1);
    bool validarEntradas();
    QString ReadData();
    void doReadings();
    QByteArray infoCALL();
    double scale_temp(double adcCount);
    double readTemperature(QByteArray myCALL);
    void angleCalibrate(double myangle, int index);
    double readAngle(QByteArray myCALL);
    double readVoltage(QByteArray myCALL);
    double scale_light(double adcCount);
    double readLight(QByteArray myCALL);
    double scale_sound(double adcCount);
    double readSound(QByteArray myCALL);
    double readResistence(QByteArray myCALL);
    double round_to_decimal(float f);
    void setupGrace();
    void plotaGrace(double x, double y, double dx, double dy);
    int decimalSensor(double value);
    void formatDisplay(double value, double time, double erroY);
    double roundValue(double value, double error);

    bool maybeSave();
    void documentWasModified();
    void createActions();
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);

private:
    Ui::maroloDAQ *ui;
    bool PaletaLogBW;
    QSerialPort *devserial;
    comserial *procSerial;
    void CarregarInfoDispSerial(void);
    QAction *actionACM0;
    QAction *actionACM1;
    QAction *actionACM2;
    QAction *actionACM3;
    QAction *actionUSB0;
    QAction *actionUSB1;
    QAction *actionUSB2;
    QAction *actionUSB3;
    QAction *actionS0;
    QAction *actionS1;
    QAction *actionS2;
    QAction *actionS3;
    void enumerateMenu(QMenu *menu);
    QActionGroup *PortasGroup;
    QActionGroup *BaudRateGroup;
    //variáveis adicionas por Rafael
    QString AdcReadString;
    bool stopFlag;
    int baudrate;

    QPlainTextEdit *teLog;
    QString curFile;
};
#endif // PROJMAROLO_H
