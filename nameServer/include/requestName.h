/*============================================
FILE:		requestName.h

DESCRIPTION:	
This header contains all globals for requestName.

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
$Log: requestName.h,v $
Revision 1.2  2006/08/20 12:55:40  jemartins
changed name MAX_BUF_SIZE var back to MAX_BUFFER_SIZE

Revision 1.1  2006/07/06 14:31:52  bobfcsoft
seed code

=======================================================
============================================*/
#ifndef _REQUEST_NAME_DEFS
#define _REQUEST_NAME_DEFS

#include "simpl.h"
#include "loggerVars.h"

_ALLOC unsigned int globalMask;
#define TRACE_MARK		0x00000001
#define TRACE_FUNC_IO		0x00000002
#define TRACE_MISC		0x00000010
#define MAX_BUFFER_SIZE         8192

_ALLOC int nameServerID;
_ALLOC int myID;

_ALLOC char infile[80];
_ALLOC FILE *in_fp;
_ALLOC char fullinfile[100];
_ALLOC char outfile[80];
_ALLOC FILE *out_fp;
_ALLOC char fulloutfile[100];

_ALLOC int fd;
_ALLOC int maxfd;
_ALLOC int my_fds[2];
_ALLOC fd_set watchset;
_ALLOC fd_set inset;

_ALLOC char msgArea[8192];
_ALLOC char inArea[8192];
_ALLOC char outArea[8192];

#endif
