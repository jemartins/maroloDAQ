#include "comserial.h"


/**
 * @brief CommSerial::CommSerial
 *
 * Função do metodo construtor, inicia variaveis e objetos privados para uso da classe
 *
 * @param
 * @return
 */
comserial::comserial(QSerialPort *myDev)
{
    devSerial = myDev;
}


/**
 * @brief CommSerial::CarregarDispositivos
 *
 * Função que verifica todas as portas disponiveis /dev/tty*
 * e na sequencia seta a porta com serial.setport e testar se é uma
 * porta serial
 *
 * @param void
 * @return QStringList com os devices do /dev que são portas seriais
 */
QStringList comserial::CarregarDispositivos()
{
    QStringList devs;

    foreach (const QSerialPortInfo info, QSerialPortInfo::availablePorts()) {

        devSerial->setPort(info);

        if (devSerial->open(QIODevice::ReadWrite)) {
            devSerial->close();
            devs << info.portName();
        }

    }
    return devs;
}



/**
 * @brief CommSerial::Conectar
 *
 * Função que recebe os parametros Porta, BaudRate e FlowControl e realiza conexão
 *
 * @param QString Port(Porta Serial), uint32_t bd(BaudRate), uint8_t fc(FlowControl)
 * @return
 */
bool comserial::Conectar(QString Port, u_int32_t bd)
{
    /* Device Serial Port */
    devSerial->setPortName(Port);
    qDebug() << "Dispositivo Porta Serial: " << Port;


    /* Conectar SerialPort */
    qDebug() << "Baudrate: " << bd;

        /* BaudRate */
        switch (bd) {
        case 2400:
            //qDebug() << "Baudrate: 2400";
            devSerial->setBaudRate(QSerialPort::Baud2400);
            break;
        case 4800:
            //qDebug() << "Baudrate: 4800";
            devSerial->setBaudRate(QSerialPort::Baud4800);
            break;
        case 9600:
            //qDebug() << "Baudrate: 9600";
            devSerial->setBaudRate(QSerialPort::Baud9600);
            break;
        case 19200:
            //qDebug() << "Baudrate: 19200";
            devSerial->setBaudRate(QSerialPort::Baud19200);
            break;
        case 115200:
            //qDebug() << "Baudrate: 115200";
            devSerial->setBaudRate(QSerialPort::Baud115200);
            break;
        }

        /* FlowControl */
        devSerial->setFlowControl(QSerialPort::NoFlowControl);


        /* Configurações adicionais */
        devSerial->setDataBits(QSerialPort::Data8);
        devSerial->setParity(QSerialPort::NoParity);
        devSerial->setStopBits(QSerialPort::OneStop);


        if(devSerial->open(QIODevice::ReadWrite)) {
            //qDebug() << "Porta serial aberta com sucesso!";
            return true;
        }
        else {
            //qDebug() << "Falha ao abrir porta serial!";
            //qDebug() << "Erro: " << devSerial->error();
            return false;
        }


}


/**
 * @brief CommSerial::Desconectar
 *
 * Função Desconectar, realiza a limpeza do componente e fecha
 *
 * @param
 * @return
 */
bool comserial::Desconectar()
{
    devSerial->clear();
    devSerial->close();


    if(devSerial->error() == 0 || !devSerial->isOpen()) {
        //qDebug() << "Porta serial fechada com sucesso!";
        return true;
    }
    else {
        //qDebug() << "Falha ao fechar a porta serial! ERRO: " << devSerial->error();
        return false;
    }

}


/**
 * @brief CommSerial::Write
 *
 * Função para escrever na serial, recebe um ponteiro de caracteres já no formato do const char* do write
 *
 * @param const char *cmd
 * @return void
 */
qint64 comserial::Write(const char *cmd)
{
    qint64 tamanhoEscrito;
    tamanhoEscrito = devSerial->write(cmd,qstrlen(cmd));

    return tamanhoEscrito;
}


/**
 * @brief CommSerial::Read
 *
 * Função Realiza a leitura do que chegar pela serial apos escrever na mesma, e devolve um QString
 *
 * @param
 * @return QString
 */
QString comserial::Read()
{
     QString bufRxSerial;
     /* Awaits read all the data before continuing */

     while (devSerial->waitForReadyRead(20)) {
         bufRxSerial += devSerial->readAll();
     }

     return bufRxSerial;
}


/**
 * @brief CommSerial::Read
 *
 * Função Realiza a leitura do que chegar pela serial apos escrever na mesma, e devolve uma QString
 * neste caso é enviado um inteiro com o numero de caracteres do buffer de recepção
 *
 * @param int
 * @return QString
 */
QString comserial::Read(int TamanhoBuffer)
{
    char buf[TamanhoBuffer];

    if (devSerial->canReadLine()) {
        devSerial->read(buf, sizeof(buf));
    }

    return buf;

}
