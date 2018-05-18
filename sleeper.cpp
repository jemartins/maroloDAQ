#include "sleeper.h"

Sleeper::Sleeper()
{

}

void Sleeper::doReadings(int sensor, int deltaT_ms, int tmax_ms, QByteArray a)
{
    //qDebug() << "DeltaT_ms:" << deltaT_ms << endl;

    // Tempo decorrido nas leituras ms
    int time_elapsed = 0;

    //Inicia Relogio do tempo total
    Relogio.start();

    //Inicia leitura
    while(time_elapsed <= tmax_ms + deltaT_ms/100)
    {
        //Qual Sensor foi Selecionado
        switch(sensor)
        {
        case 0:
            //mywave = readSOUNDWAVE(myCALL);
            mywave = 0;
            break;
        case 1:
            //mysound = readSOUNLEVEL(myCALL);
            mysound = 0;
            break;
        case 2:
            //myvoltage = readVOLTAGE(myCALL);
            myvoltage = 0;
            break;
        case 3:
            //myresistence = readRESISTENCE(myCALL);
            myresistence = 0;
            break;
        case 4:
            //myph = readPH(myCALL);
            myph = 0;
            break;
        case 5:
            mytemperature = readTEMPERATURE(a);
            //mytemperatura = 0;
            break;
        case 6:
            //mylight = readLIGHT(myCALL);
            mylight = 0;
            break;
        case 7:
            // myangle = readPENDULO(myCALL);
            myangle = 0;
            break;
        } // end switch sensor

        //Debug
        qDebug() << "Tempo decorrido" << time_elapsed << endl;
        qDebug() << "Temperatura" << mytemperature << endl;

        //comando de sleep
        usleep(deltaT_ms*1000);

        //atualiza tempo total decorrido
        time_elapsed = Relogio.elapsed();
    }//end while
}

//envia comando para arduino ler a tensão no pino "myCALL"
int Sleeper::readTEMPERATURE(QByteArray myCALL)
{
    //Envia comando para Arduino ler pino
    WriteData(myCALL);

    //recebe valor lido pelo ADC no pino do sensor
    AdcReadString = ReadData();

    //converte String em Inteiro
    AdcReadInt = AdcReadString.toInt();
    //qDebug() << "Medida em int" << AdcReadInt << endl;

    //Converte Inteiro em Temperatura
     return scale_temp(AdcReadInt*(4096/1024));
    //return 333.81 + 0.04867 * AdcReadInt - 4.8123e-5 * (AdcReadInt^2);
}

//Converte valor de leitura do ADC em valor de temperatura
int Sleeper::scale_temp(int adcCount)
{
    int i, diffScaled, diffRaw, diffAdc, scaledValue=0;
        double scaleFactor;
        for (i=0; i<100; i++)
        {
            if (adcCount >= temp[i][0] && adcCount < temp[i+1][0])
            {
                    diffScaled = temp[i][1] - temp[i+1][1];
                    diffRaw = temp[i+1][0] - temp[i][0];
                    scaleFactor = (double)diffScaled / (double)diffRaw;
                    diffAdc = adcCount - temp[i][0];
                    scaledValue = temp[i][1] - (diffAdc * scaleFactor);
                    return scaledValue;
            }
    }
    return -1;
}

void Sleeper::WriteData(const QByteArray data)
{
    procSerial->Write(data);
     //qDebug() << "WriteData - RX UART: " << data << endl;
}

QString Sleeper::ReadData()
{
    QString data = procSerial->Read();
    //qDebug() << "ReadData - RX UART: " << data << endl;
    return data;
}
