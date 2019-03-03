/*************************************************************

FILE:		nameStim.c

DESCRIPTION:	
This program helps stimulate the nameServer.

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
$Log: nameStim.c,v $
Revision 1.4  2006/07/08 11:42:46  bobfcsoft
chasing 52 problem

Revision 1.3  2006/07/07 19:52:46  bobfcsoft
bobs changes

Revision 1.2  2006/07/06 20:26:40  jemartins
added outMsg

Revision 1.1  2006/07/06 14:31:12  bobfcsoft
seed code

=======================================================

*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "nameServerMsgs.h"

#define _ALLOC
#include "nameStim.h"
#undef _ALLOC

#include "nameStimProto.h"
#include "simplProto.h"
#include "loggerProto.h"

/*--------------------------------------
	nameStim - entry point
--------------------------------------*/
int main(int argc, char **argv)
{
static char *fn="nameStim";
int x_it=0;
char line[80];
char *p;

initialize(argc, argv);

fcLogx(__FILE__, fn,
	globalMask,
	TRACE_MARK,
	"starting"
	);

printf("-> ");
fflush(stdout);
while(!x_it)
	{
	inset = watchset;
	select(maxfd+1, &inset, NULL, NULL, NULL);

// Is this from keyboard
	if(FD_ISSET(my_fds[0], &inset))  //  keyboard is ready
		{
		fgets(line,80,stdin);
		p=skipOverWhiteSpace(line);

fcLogx(__FILE__, fn,
	globalMask,
	TRACE_MARK,
	"line=%s len=%d",
	line, strlen(line)
	);
		switch(line[0])
			{
			case '?':
				printf("nameStim commands:\n");
				printf("r - request a name\n");
				printf("f <ID> - free by ID\n");
				printf("q - quit\n");
				break;

			case 'f':
				{
				NAME_SERVER_MSG *outMsg;
		
				outMsg=(NAME_SERVER_MSG *)outArea;
				outMsg->token=FREE_NAME;
				outMsg->ID=atoi(p);

				Send(nameServerID, 
					outArea, 
					inArea, 
					sizeof(NAME_SERVER_MSG), 
					MAX_BUFFER_SIZE);

				}
				break;

			case 'r':
				{
				NAME_SERVER_MSG *outMsg;
				NAME_SERVER_MSG *inMsg;
				int rbytes;
		
				outMsg=(NAME_SERVER_MSG *)outArea;
				outMsg->token=REQUEST_NAME;

				rbytes=Send(nameServerID, 
					outArea, 
					inArea, 
					sizeof(NAME_SERVER_MSG), 
					MAX_BUFFER_SIZE);

fcLogx(__FILE__, fn,
	globalMask,
	TRACE_MARK,
	"rbytes=%d",
	rbytes
	);

				inMsg=(NAME_SERVER_MSG *)inArea;

fcLogx(__FILE__, fn,
	globalMask,
	TRACE_MARK,
	"inMsg->guiName=<%s> inMsg->readerName=<%s> inMsg->ID=%d",
	inMsg->guiName, inMsg->readerName, inMsg->ID
	);

printf("%s, %s, %d\n", inMsg->guiName, inMsg->readerName,  inMsg->ID);
				}
				break;

			case 'l':
				{
				NAME_SERVER_MSG *outMsg;
				NAME_SERVER_MSG *inMsg;
				int rbytes;
				int i;
		
				for(i=0; i<51; i++)
					{
				outMsg=(NAME_SERVER_MSG *)outArea;
				outMsg->token=REQUEST_NAME;

				rbytes=Send(nameServerID, 
					outArea, 
					inArea, 
					sizeof(NAME_SERVER_MSG), 
					MAX_BUFFER_SIZE);

fcLogx(__FILE__, fn,
	globalMask,
	TRACE_MARK,
	"rbytes=%d",
	rbytes
	);

				inMsg=(NAME_SERVER_MSG *)inArea;

fcLogx(__FILE__, fn,
	globalMask,
	TRACE_MARK,
	"inMsg->guiName=<%s> inMsg->readerName=<%s> inMsg->ID=%d",
	inMsg->guiName, inMsg->readerName, inMsg->ID
	);

printf("%s, %s, %d\n", inMsg->guiName, inMsg->readerName,  inMsg->ID);

fflush(stdout);
					}
				}
				break;

			case 'q':
				x_it=1;
				break;

			default:
				printf("%s: unknown keypress <%c>\n",
					fn,
					line[0]);
				break;
			} // end switch

		printf("-> ");
		fflush(stdout);
		} // end if keyboard

	} // end while

fcLogx(__FILE__, fn,
	globalMask,
	TRACE_MISC,
	"done");

name_detach();

exit(1);
}// end nameStim
