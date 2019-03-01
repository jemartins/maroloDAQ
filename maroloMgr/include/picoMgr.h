/*======================================================

	This software was developed for
	iCanProgram Inc., Toronto, Canada

FILE:	picoMgr.h

DESCRIPTION:	
This file contains globals for picoMgr.

AUTHOR:		R.D. Findlay

##############################################################################
#
#    Copyright (C) 2006 DrDAQ Application Project.
#
#    This software is in the public domain.
#    Permission to use, copy, modify, and distribute this software and its
#    documentation for any purpose and without fee is hereby granted,
#    without any conditions or restrictions.
#    This software is provided "as is" without express or implied warranty.
#
#    If you discover a bug or add an enhancement here's how to reach us:
#
#        https://sourceforge.net/projects/drdaq
#
###############################################################################

Revision history:
=======================================================
$Log: picoMgr.h,v $
Revision 1.11  2007/06/12 18:09:35  jemartins
bugs fixed

Revision 1.10  2007/06/06 20:52:12  jemartins
adjusted ANGLE option

Revision 1.9  2007/06/01 21:47:32  jemartins
added _ALLOC in array CALIBRATE

Revision 1.8  2007/06/01 21:43:23  jemartins
added struct CALIBRATE

Revision 1.7  2006/07/09 21:01:25  jemartins
*** empty log message ***

Revision 1.6  2006/06/22 18:01:55  jemartins
added myID

Revision 1.5  2006/06/22 16:13:41  jemartins
removed routingTable

Revision 1.4  2006/06/22 11:53:55  jemartins
added routingTable

Revision 1.3  2006/05/17 21:26:49  jemartins
added Copyright

Revision 1.2  2006/04/23 17:20:50  jemartins
add stopFlag var

Revision 1.1.1.1  2006/03/07 21:29:38  bobfcsoft
startup

======================================================*/

#ifndef _PICO_MGR_DEFS
#define _PICO_MGR_DEFS

#include "simpl.h"
#include "loggerVars.h"

_ALLOC unsigned int globalMask;
#define PICOMGR_MARK		0x00000001
#define PICOMGR_FUNC_IO		0x00000002
#define PICOMGR_MISC		0x00000010

_ALLOC char loggerName[20];

_ALLOC int toPid;
_ALLOC char toName[20];
_ALLOC char myMsg[80];

_ALLOC int picofd;
_ALLOC int ledState;
_ALLOC int digital_output;

_ALLOC char inArea[8192];
_ALLOC char outArea[8192];

typedef struct {
		char *picoReaderPending;
		int stopFlag;
		}ROUTING_REC;

ROUTING_REC routingTable[128];    // to allow up to 128 connections

typedef struct
        {
        float angle;
        int voltage;
        }CALIBRATION;

_ALLOC CALIBRATION calibrationArray[2][2];

#endif
