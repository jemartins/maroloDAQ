/*======================================================

FILE:	nameServer.h

DESCRIPTION:	
This file contains globals for nameServer.

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
$Log: nameServer.h,v $
Revision 1.7  2006/08/20 12:12:54  jemartins
changed name MAX_BUF_SIZE var back to MAX_BUFFER_SIZE

Revision 1.6  2006/07/11 16:57:14  jemartins
changed name MAX_BUF_SIZE var

Revision 1.5  2006/07/06 19:35:24  jemartins
pasted from bob files

Revision 1.4  2006/07/06 18:29:27  bobfcsoft
annotated changes

Revision 1.3  2006/07/06 14:48:25  jemartins
developed case FREE_NAME

Revision 1.2  2006/07/06 14:19:52  jemartins
arrange seed code

Revision 1.1  2006/07/06 13:06:11  jemartins
startup


======================================================*/

#ifndef _NAME_SERVER_DEFS
#define _NAME_SERVER_DEFS

#include "simpl.h"
#include "loggerVars.h"

_ALLOC unsigned int globalMask;
#define MAX_BUFFER_SIZE 	8192
#define TRACE_MARK		0x00000001
#define TRACE_FUNC_IO		0x00000002
#define TRACE_MISC		0x00000010

_ALLOC char loggerName[20];

_ALLOC int namesTable[127];
_ALLOC char guiName[20];
_ALLOC char readerName[20];

_ALLOC int toPid;
_ALLOC char toName[20];
_ALLOC char myMsg[80];

_ALLOC char inArea[8192];
_ALLOC char outArea[8192];

#endif
