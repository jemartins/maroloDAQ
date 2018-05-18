#ifndef SLEEPER_H
#define SLEEPER_H

#include <QThread>
#include <QTime>
#include "comserial.h"
#include <QDebug>
//#include <maroloDAQ.h>

class Sleeper : public QThread
{
public:
    Sleeper();
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
    void doReadings(int sensor, int deltaT_ms, int tmax_ms, QByteArray myCALL);
    comserial *procSerial;

private:
    int readTEMPERATURE(QByteArray myCALL);
    void WriteData(const QByteArray data);
    QString ReadData();
    int scale_temp(int adcCount);
    QTime Relogio;
    double mywave, mysound,myvoltage,myresistence,myph,mytemperature, mylight,myangle;
    QString AdcReadString;
    int AdcReadInt;
    const int temp[101][2] = {
    {55,1500},
    {95,1333},
    {136,1196},
    {176,1085},
    {217,998},
    {257,932},
    {298,882},
    {379,814},
    {419,787},
    {460,762},
    {500,736},
    {540,712},
    {581,689},
    {621,667},
    {662,645},
    {702,625},
    {743,606},
    {783,587},
    {824,570},
    {864,554},
    {904,538},
    {945,524},
    {985,510},
    {1026,497},
    {1066,484},
    {1107,472},
    {1147,461},
    {1188,450},
    {1228,439},
    {1269,429},
    {1309,418},
    {1349,408},
    {1390,399},
    {1430,389},
    {1471,379},
    {1511,369},
    {1552,360},
    {1592,350},
    {1633,341},
    {1673,331},
    {1713,322},
    {1794,304},
    {1835,295},
    {1875,286},
    {1916,278},
    {1956,269},
    {1997,261},
    {2037,252},
    {2078,244},
    {2118,235},
    {2158,227},
    {2199,219},
    {2239,210},
    {2280,202},
    {2320,194},
    {2361,185},
    {2401,177},
    {2442,168},
    {2482,160},
    {2522,152},
    {2563,143},
    {2603,135},
    {2644,126},
    {2684,117},
    {2725,109},
    {2765,100},
    {2806,91},
    {2846,82},
    {2887,73},
    {2927,64},
    {2967,54},
    {3008,45},
    {3048,35},
    {3089,25},
    {3129,15},
    {3170,5},
    {3210,-6},
    {3251,-17},
    {3291,-28},
    {3331,-40},
    {3372,-52},
    {3412,-64},
    {3453,-77},
    {3493,-91},
    {3534,-105},
    {3574,-120},
    {3615,-136},
    {3655,-153},
    {3696,-171},
    {3736,-190},
    {3776,-210},
    {3817,-232},
    {3857,-258},
    {3898,-291},
    {3938,-333},
    {3979,-385},
    {4019,-450},
    {4060,-528},
    {4096,-611},
    };
};
#endif // SLEEPER_H
