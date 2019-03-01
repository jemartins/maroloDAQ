/*============================================

	This software was developed for
	iCanProgram Inc., Toronto, Canada

FILE:		picoStim.h

DESCRIPTION:	
This header contains all globals for picoStim app.

AUTHOR:			R.D. Findlay

Revision history:
=======================================================
$Log: picoStim.h,v $
Revision 1.2  2006/06/23 23:48:37  jemartins
*** empty log message ***

Revision 1.1.1.1  2006/03/07 21:29:38  bobfcsoft
startup

=======================================================
============================================*/
#ifndef _PICO_STIM_DEFS
#define _PICO_STIM_DEFS

#include "simpl.h"
#include "loggerVars.h"

_ALLOC unsigned int globalMask;
#define PICO_STIM_MARK		0x00000001
#define PICO_STIM_FUNC_IO	0x00000002
#define PICO_STIM_MISC		0x00000010

_ALLOC int picoMgrID;
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
