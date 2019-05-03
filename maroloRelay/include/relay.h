/*************************************************************
FILE:	relay.h	

DESCRIPTION:	
This file contains globals for relay app.

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
$Log: relay.h,v $
Revision 1.2  2002/12/03 21:18:31  root
v2.0 compatible

Revision 1.1  2002/12/03 19:52:17  root
Initial revision

=======================================================

*************************************************************/

#ifndef _RELAY_DEFS
#define _RELAY_DEFS

#define MAX_MSG_SIZE	8192

#include "simpl.h"
#include "loggerVars.h"

// some parameters to enable the trace logger
// fclogger
_ALLOC unsigned int globalMask;
#define RELAY_MARK		0x00000001
#define RELAY_FUNC_IO		0x00000002
#define RELAY_MISC		0x00000010

_ALLOC char recv_name[20];
_ALLOC int RecvHomeID;
_ALLOC int RecvDestID;

_ALLOC char inArea[MAX_MSG_SIZE];
_ALLOC char outArea[MAX_MSG_SIZE];

#endif
