/*============================================

	This software was developed for
	iCanProgram Inc., Toronto, Canada

FILE:		guiStim.h

DESCRIPTION:	
This header contains all globals for picoStim app.

AUTHOR:			R.D. Findlay

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
$Log: guiStim.h,v $
Revision 1.3  2006/06/24 15:38:24  jemartins
added myID

Revision 1.2  2006/05/17 21:26:49  jemartins
added Copyright

Revision 1.1  2006/03/20 22:37:59  bobfcsoft
added START logic

Revision 1.1  2006/03/20 22:19:46  bobfcsoft
added START functionality


=======================================================
============================================*/
#ifndef _GUI_STIM_DEFS
#define _GUI_STIM_DEFS

#include "simpl.h"
#include "loggerVars.h"

_ALLOC unsigned int globalMask;
#define GUI_STIM_MARK		0x00000001
#define GUI_STIM_FUNC_IO	0x00000002
#define GUI_STIM_MISC		0x00000010

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
