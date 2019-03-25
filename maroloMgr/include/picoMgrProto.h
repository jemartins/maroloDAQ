
/*************************************************************
FILE:		picoMgrProto.h

DESCRIPTION:	
This file contains prototypes for picoMgr.

    Copyright (C) 2006 DrDAQ Application Project.

    This software is in the public domain.
    Permission to use, copy, modify, and distribute this software and its
    documentation for any purpose and without fee is hereby granted,
    without any conditions or restrictions.
    This software is provided "as is" without express or implied warranty.

    If you discover a bug or add an enhancement here's how to reach us:

        https://sourceforge.net/projects/drdaq
        
        
Revision history:
=======================================================
$Log: picoMgrProto.h,v $
Revision 1.8  2007/06/05 20:12:25  juniocruz
Angle adjusted as float

Revision 1.7  2007/06/04 14:13:08  jemartins
added readAngle

Revision 1.6  2006/06/01 01:22:37  jemartins
*** empty log message ***

Revision 1.5  2006/06/01 00:15:51  jemartins
added new functions

Revision 1.4  2006/06/01 00:14:03  jemartins
added new functions

Revision 1.3  2006/05/15 18:09:05  jemartins
added Copyright

Revision 1.2  2006/04/21 01:28:46  jemartins
add readTemperature() and scale_temp()

Revision 1.1.1.1  2006/03/07 21:29:38  bobfcsoft
startup

=======================================================

*************************************************************/

#ifndef _PICOMGR_PROTO_DEF
#define _PICOMGR_PROTO_DEF

#include "standardTypes.h"

void initialize(int, char **);
void myUsage();

int turnLedOff();
int turnLedOn();

int drdaq_open(int);
int marolo_open();

int readWaveForm();
int readSoundLevel();
int readVoltage();
int readResistance();
int readPH();
int readTemperature();
int readLight();
float readAngle();
int readMarolo(int CALL);
int scale_light();
int scale_temp();
int scale_sound();

#endif
