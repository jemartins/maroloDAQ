/*************************************************************

FILE:		requestName.c

DESCRIPTION:	
This program requests a SIMPL name from the nameServer.

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
$Log: requestName.c,v $
Revision 1.5  2006/07/09 21:13:09  jemartins
added name_detach() call

Revision 1.4  2006/07/08 11:42:46  bobfcsoft
chasing 52 problem

Revision 1.3  2006/07/07 22:00:24  jemartins
removed space in sprint

Revision 1.2  2006/07/07 21:38:15  jemartins
adapted code from nameStim

Revision 1.1  2006/07/06 14:32:26  bobfcsoft
seed code

=======================================================

*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "nameServerMsgs.h"

#define _ALLOC
#include "requestName.h"
#undef _ALLOC

#include "requestNameProto.h"
#include "simplProto.h"
#include "loggerProto.h"

/*--------------------------------------
	requestName - entry point
--------------------------------------*/
int main(int argc, char **argv)
{
static char *fn="requestName";
NAME_SERVER_MSG *outMsg;
NAME_SERVER_MSG *inMsg;
		
initialize(argc, argv);

fcLogx(__FILE__, fn,
	globalMask,
	TRACE_MARK,
	"starting myID=%d",
        myID
	);

outMsg=(NAME_SERVER_MSG *)outArea;
outMsg->token=REQUEST_NAME;

Send(nameServerID, 
        outArea, 
        inArea, 
        sizeof(NAME_SERVER_MSG), 
        MAX_BUFFER_SIZE);

inMsg=(NAME_SERVER_MSG *)inArea;

printf("%s,%s,%d\n", inMsg->guiName, inMsg->readerName,  inMsg->ID);

fcLogx(__FILE__, fn,
	globalMask,
	TRACE_MISC,
	"done");

name_detach();

exit(1);

}// end requestName
