/*************************************************************

	This software was developed for
	iCanProgram Inc., Toronto, Canada

FILE:		guiStim.c

DESCRIPTION:	
This program helps stimulate the picoMgr.

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

Revision history:extern int myID;

=======================================================
$Log: autoguiStim.c,v $
Revision 1.2  2006/07/11 12:23:00  jemartins
removed x_it var

Revision 1.1  2006/06/25 14:05:44  jemartins
added autoguiStim

=======================================================

*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "drdaqMsgs.h"

#define _ALLOC
#include "guiStim.h"
#undef _ALLOC

#include "guiStimProto.h"
#include "simplProto.h"
#include "loggerProto.h"

int myID;

/*--------------------------------------
	guiStim - entry point
--------------------------------------*/
int main(int argc, char **argv)
{
static char *fn="guiStim";

char line[80];
char *p;

initialize(argc, argv);

fcLogx(__FILE__, fn,
	globalMask,
	GUI_STIM_MARK,
	"starting myID=%d",
        myID
	);

printf("-> ");
fflush(stdout);

PICO_START_MSG *outMsg;

outMsg=(PICO_START_MSG *)outArea;
outMsg->token=PICO_READING_START;
outMsg->ID=myID;
outMsg->sensor[0].set_value=11;

p=skipOverWhiteSpace(line); // start of period
outMsg->period=atoi(p);

p=skipOverWhiteSpace(p); // start of maxReadings
outMsg->maxReadings=atoi(p);

Send(picoMgrID, 
        outArea, 
        NULL, 
        sizeof(PICO_START_MSG), 
        0);
        
printf("end game\n");

fcLogx(__FILE__, fn,
	globalMask,
	GUI_STIM_MISC,
	"done");

name_detach();

exit(1);
}// end guiStim
