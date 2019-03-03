/*============================================

FILE:		nameStim.h

DESCRIPTION:	
This header contains all globals for nameStim app.

Revision history:
=======================================================
$Log: nameStim.h,v $
Revision 1.3  2006/08/20 12:18:34  jemartins
changed name MAX_BUF_SIZE var back to MAX_BUFFER_SIZE

Revision 1.2  2006/07/11 16:57:14  jemartins
changed name MAX_BUF_SIZE var

Revision 1.1  2006/07/06 14:31:52  bobfcsoft
seed code

=======================================================
============================================*/
#ifndef _NAME_STIM_DEFS
#define _NAME_STIM_DEFS

#include "simpl.h"
#include "loggerVars.h"

#define MAX_BUFFER_SIZE 	8192

_ALLOC unsigned int globalMask;
#define TRACE_MARK		0x00000001
#define TRACE_FUNC_IO		0x00000002
#define TRACE_MISC		0x00000010

_ALLOC int nameServerID;

_ALLOC int fd;
_ALLOC int maxfd;
_ALLOC int my_fds[2];
_ALLOC fd_set watchset;
_ALLOC fd_set inset;

_ALLOC char inArea[MAX_BUFFER_SIZE];
_ALLOC char outArea[MAX_BUFFER_SIZE];

#endif
