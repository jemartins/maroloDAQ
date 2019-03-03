/*============================================

FILE:		freeName.h

DESCRIPTION:	
This header contains all globals for picoStim app.

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
$Log: freeName.h,v $
Revision 1.4  2006/08/20 12:12:54  jemartins
changed name MAX_BUF_SIZE var back to MAX_BUFFER_SIZE

Revision 1.3  2006/07/11 16:57:14  jemartins
changed name MAX_BUF_SIZE var

Revision 1.2  2006/07/07 21:38:15  jemartins
adapted code from nameStim

Revision 1.1  2006/07/06 14:31:52  bobfcsoft
seed code

=======================================================
============================================*/

#ifndef _FREE_NAME_DEFS
#define _FREE_NAME_DEFS

#include "simpl.h"
#include "loggerVars.h"

#define MAX_BUFFER_SIZE 	8192

_ALLOC unsigned int globalMask;
#define TRACE_MARK		0x00000001
#define TRACE_FUNC_IO		0x00000002
#define TRACE_MISC		0x00000010

_ALLOC int picoMgrID;
_ALLOC int myID;

_ALLOC int nameServerID;

_ALLOC int fd;
_ALLOC int maxfd;
_ALLOC int my_fds[2];
_ALLOC fd_set watchset;
_ALLOC fd_set inset;

_ALLOC char inArea[MAX_BUFFER_SIZE];
_ALLOC char outArea[MAX_BUFFER_SIZE];

#endif
