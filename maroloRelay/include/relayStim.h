/*************************************************************
FILE:	relayStim.h	

DESCRIPTION:	
This file contains globals for relayStim app.

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
$Log: relayStim.h,v $
Revision 1.2  2002/12/03 21:19:05  root
v2.0 compatible

Revision 1.1  2002/12/03 19:52:33  root
Initial revision

=======================================================

*************************************************************/
#ifndef _RELAY_STIM_DEFS
#define _RELAY_STIM_DEFS

#include "simpl.h"
#include "loggerVars.h"

#define MAX_MSG_SIZE 	8192

// stuff to enable trace logger
_ALLOC unsigned int globalMask;
#define RELAY_STIM_MARK		0x00000001
#define RELAY_STIM_FUNC_IO	0x00000002
#define RELAY_STIM_MISC		0x00000010

_ALLOC int relayID;

// for keyboard access
_ALLOC int fd;
_ALLOC int maxfd;
_ALLOC int my_fds[2];
_ALLOC fd_set watchset;
_ALLOC fd_set inset;

_ALLOC char inArea[MAX_MSG_SIZE];
_ALLOC char outArea[MAX_MSG_SIZE];

#endif
