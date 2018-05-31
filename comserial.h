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
 ****************************************************************************/

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
