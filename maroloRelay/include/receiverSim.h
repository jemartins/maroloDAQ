/*************************************************************
FILE:	receiverSim.h	

DESCRIPTION:	
This file contains globals for receiverSim app.

AUTHOR:			R.D. Findlay

-----------------------------------------------------------------------
    Copyright (C) 2000, 2002 FCSoftware Inc. 

    This software is in the public domain.
    Permission to use, copy, modify, and distribute this software and its
    documentation for any purpose and without fee is hereby granted, 
    without any conditions or restrictions.
    This software is provided "as is" without express or implied warranty.

    If you discover a bug or add an enhancement here's how to reach us: 

	fcsoft@attcanada.ca
-----------------------------------------------------------------------
Revision history:
=======================================================
$Log: receiverSim.h,v $
Revision 1.2  2002/12/03 21:18:09  root
v2.0 compatible

Revision 1.1  2002/12/03 19:52:05  root
Initial revision

=======================================================

*************************************************************/

#ifndef _RECV_SIM_DEFS
#define _RECV_SIM_DEFS

#include "simpl.h"
#include "loggerVars.h"

#define MAX_MSG_SIZE	8192

// some parameters for trace logger (fclogger)
_ALLOC unsigned int globalMask;
#define RECV_SIM_MARK		0x00000001
#define RECV_SIM_FUNC_IO	0x00000002
#define RECV_SIM_MISC		0x00000010

// general globals
_ALLOC char myName[20];

_ALLOC int relayID;

// to enable keyboard access
_ALLOC int backgroundMode;
_ALLOC int fd;
_ALLOC int maxfd;
_ALLOC int my_fds[2];
_ALLOC fd_set watchset;
_ALLOC fd_set inset;

_ALLOC char inArea[MAX_MSG_SIZE];
_ALLOC char outArea[MAX_MSG_SIZE];

#endif
