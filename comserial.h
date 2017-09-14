#ifndef COMSERIAL_H
#define COMSERIAL_H


/**
 * Incluindo QDebug para enviar debug em background no terminal
 * QSerialPort e QSerialPortInfo para manipular o dispositivo serial
 */
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class comserial
{
public:
    comserial(QSerialPort *myDev);
    ~comserial();

    QStringList CarregarDispositivos();

    bool Conectar(QString Port, u_int32_t bd);
    bool Desconectar(void);

    qint64 Write(const char *cmd);
    QString Read();
    QString Read(int TamanhoBuffer);

protected:
    QSerialPort *devSerial;
};

#endif // COMSERIAL_H
