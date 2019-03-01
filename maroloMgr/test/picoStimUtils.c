/*************************************************************

	This software was developed for
	iCanProgram Inc., Toronto, Canada

FILE:		picoStimUtils.c

DESCRIPTION:	
This file contains utility code for picoStim. 

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
$Log: picoStimUtils.c,v $
Revision 1.4  2006/05/27 12:25:03  jemartins
added include drdaqMsgs.h

Revision 1.3  2006/05/17 21:24:07  jemartins
added Copyright

Revision 1.2  2006/03/21 21:04:58  bobfcsoft
changes from -2.4 codebase

Revision 1.1.1.1  2006/03/07 21:29:47  bobfcsoft
startup

=======================================================

*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "drdaqMsgs.h"

#define _ALLOC extern
#include "picoStim.h"
#undef _ALLOC

#include "picoStimProto.h"
#include "simplProto.h"
#include "loggerProto.h"
#include "simplmiscProto.h"


/*=========================================
	skipOverWhiteSpace - entry point
=========================================*/
char *skipOverWhiteSpace(char *start)
{
char *p;

for(p=start; *p != 0 && *p != ' ' && *p != 0x09; p++);  // skip to whitespace
if(*p != 0)
	{
	*p=0;	// null terminate
	p++;
	for(; *p == ' ' || *p == 0x09; p++); // skip whitespace
	}

return(p);
}// end skipOverWhiteSpace
