
/*************************************************************
	This software was developed by
	iCanProgram Inc., Toronto, Canada

FILE:		picoStimProto.h

DESCRIPTION:	
This file contains prototypes used by picoStim.

AUTHOR:		R.D. Findlay

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
$Log: freeNameProto.h,v $
Revision 1.1  2006/07/06 14:31:52  bobfcsoft
seed code

Revision 1.2  2006/05/17 21:26:49  jemartins
added Copyright

Revision 1.1  2006/03/20 22:37:59  bobfcsoft
added START logic

Revision 1.1  2006/03/20 22:19:46  bobfcsoft
added START functionality

Revision 1.1  2006/03/13 20:45:38  bobfcsoft
separate Linux 2.4 version

Revision 1.1.1.1  2006/03/07 21:29:38  bobfcsoft
startup

=======================================================

*************************************************************/

#ifndef _PICO_STIM_PROTO_DEF
#define _PICO_STIM_PROTO_DEF

void initialize(int, char **);
void myUsage();

char *skipOverWhiteSpace(char *start);

#endif
