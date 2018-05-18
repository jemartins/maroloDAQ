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
    double mywave, mysound,myvoltage,myresistence,myph,mytemperature, mylight,myangle;
    QString AdcReadString;
    int AdcReadInt,amostras=0;
    //essa tabela foi deslocada para o objeto sleeper
//    const int temp[101][2] = {
//        {55,1500},
//        {95,1333},
//        {136,1196},
//        {176,1085},
//        {217,998},
//        {257,932},
//        {298,882},
//        {379,814},
//        {419,787},
//        {460,762},
//        {500,736},
//        {540,712},
//        {581,689},
//        {621,667},
//        {662,645},
//        {702,625},
//        {743,606},
//        {783,587},
//        {824,570},
//        {864,554},
//        {904,538},
//        {945,524},
//        {985,510},
//        {1026,497},
//        {1066,484},
//        {1107,472},
//        {1147,461},
//        {1188,450},
//        {1228,439},
//        {1269,429},
//        {1309,418},
//        {1349,408},
//        {1390,399},
//        {1430,389},
//        {1471,379},
//        {1511,369},
//        {1552,360},
//        {1592,350},
//        {1633,341},
//        {1673,331},
//        {1713,322},
//        {1794,304},
//        {1835,295},
//        {1875,286},
//        {1916,278},
//        {1956,269},
//        {1997,261},
//        {2037,252},
//        {2078,244},
//        {2118,235},
//        {2158,227},
//        {2199,219},
//        {2239,210},
//        {2280,202},
//        {2320,194},
//        {2361,185},
//        {2401,177},
//        {2442,168},
//        {2482,160},
//        {2522,152},
//        {2563,143},
//        {2603,135},
//        {2644,126},
//        {2684,117},
//        {2725,109},
//        {2765,100},
//        {2806,91},
//        {2846,82},
//        {2887,73},
//        {2927,64},
//        {2967,54},
//        {3008,45},
//        {3048,35},
//        {3089,25},
//        {3129,15},
//        {3170,5},
//        {3210,-6},
//        {3251,-17},
//        {3291,-28},
//        {3331,-40},
//        {3372,-52},
//        {3412,-64},
//        {3453,-77},
//        {3493,-91},
//        {3534,-105},
//        {3574,-120},
//        {3615,-136},
//        {3655,-153},
//        {3696,-171},
//        {3736,-190},
//        {3776,-210},
//        {3817,-232},
//        {3857,-258},
//        {3898,-291},
//        {3938,-333},
//        {3979,-385},
//        {4019,-450},
//        {4060,-528},
//        {4096,-611},
//        };
};
#endif // PROJMAROLO_H
