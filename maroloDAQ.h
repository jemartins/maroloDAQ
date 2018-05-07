#ifndef PROJMAROLO_H
#define PROJMAROLO_H

#include <QMainWindow>
#include <QApplication>
#include <QActionGroup>
#include "comserial.h"
#include <QMessageBox>
#include <QTimer>

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

    void update();

    int scale_temp(int adcCount);

    QString inttoQString(int sensorValue);

    void tratarLeitura(QString AdcReadString);


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
    QTimer *timer=new QTimer(this);
    int amostra=0;
    int AdcReadInt,Temperatura;
    QString AdcReadString;
    const int temp[101][2] = {
    {14,1500},
    {24,1333},
    {34,1196},
    {44,1085},
    {54,998},
    {64,932},
    {75,882},
    {95,814},
    {105,787},
    {115,762},
    {125,736},
    {135,712},
    {145,689},
    {155,667},
    {166,645},
    {176,625},
    {186,606},
    {196,587},
    {206,570},
    {216,554},
    {226,538},
    {236,524},
    {246,510},
    {257,497},
    {267,484},
    {277,472},
    {287,461},
    {297,450},
    {307,439},
    {317,429},
    {327,418},
    {337,408},
    {348,399},
    {358,389},
    {368,379},
    {378,369},
    {388,360},
    {398,350},
    {408,341},
    {418,331},
    {428,322},
    {449,304},
    {459,295},
    {469,286},
    {479,278},
    {489,269},
    {499,261},
    {509,252},
    {520,244},
    {530,235},
    {540,227},
    {550,219},
    {560,210},
    {570,202},
    {580,194},
    {590,185},
    {600,177},
    {611,168},
    {621,160},
    {631,152},
    {641,143},
    {651,135},
    {661,126},
    {671,117},
    {681,109},
    {691,100},
    {702,91},
    {712,82},
    {722,73},
    {732,64},
    {742,54},
    {752,45},
    {762,35},
    {772,25},
    {782,15},
    {793,5},
    {803,-6},
    {813,-17},
    {823,-28},
    {833,-40},
    {843,-52},
    {853,-64},
    {863,-77},
    {873,-91},
    {884,-105},
    {894,-120},
    {904,-136},
    {914,-153},
    {924,-171},
    {934,-190},
    {944,-210},
    {954,-232},
    {964,-258},
    {975,-291},
    {985,-333},
    {995,-385},
    {1005,-450},
    {1015,-528},
    {1024,-611},
    };
};
#endif // PROJMAROLO_H
