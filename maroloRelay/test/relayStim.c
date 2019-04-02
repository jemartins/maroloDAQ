/*************************************************************

FILE:		relayStim.c

DESCRIPTION:	
It will be used to stimulate the relay 
SIMPL softwareIC. 

AUTHOR:			R.D. Findlay

-----------------------------------------------------------------------
    Copyright (C) 2000, 2002 FCSoftware Inc. 

    This software is in the public domain.
    Permission to use, copy, modify, and distribute this software and its
    documentation for any purpose and without fee is hereby granted, 
    without any conditions or restrictions.
    This software is provided "as is" without express or implied warranty.

    If you discover a bug or add an enhancement here's how to reach us: 

	fcsoft@attcanada.ca
-----------------------------------------------------------------------
Revision history:
=======================================================
$Log: relayStim.c,v $
Revision 1.3  2003/04/03 16:47:30  root
fixed RedHat 7.x warnings

Revision 1.2  2002/12/03 21:20:38  root
v2.0 compatible

Revision 1.1  2002/12/03 19:54:23  root
Initial revision

=======================================================

*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#if 0
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/timeb.h>
#include <sys/time.h>
#endif

#include "relayMsgs.h"

#define _ALLOC
#include "relayStim.h"
#undef _ALLOC

#include "relayStimProto.h"
#include "simplProto.h"
#include "loggerProto.h"

/*--------------------------------------
	relayStim - entry point
--------------------------------------*/
int main(int argc, char **argv, char **envp)
{
static char *fn="relayStim";
int x_it=0;
char line[80];

initialize(argc, argv);

fcLogx(__FILE__, fn,
	globalMask,
	RELAY_STIM_MARK,
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
		fgets(line, 79, stdin);

		switch(line[0])
			{
			case '?':	// help
				printf("relay stimulator commands:\n");
				printf("t <str> - test string\n");
				printf("q       - quit\n");

				printf("-> ");
				fflush(stdout);
				break;

			case 't':	//string
				{
				RELAY_TEST_MSG *outMsg;
				char str[80];

				sprintf(str,"%s",&line[2]);

				fcLogx(__FILE__, fn,
					globalMask,
					RELAY_STIM_MISC,
					"TEST str=<%s>",
					str
					);

				outMsg=(RELAY_TEST_MSG *)outArea;

				outMsg->token=RELAY_TEST;
				sprintf(outMsg->str,"%s",str);

				fcLogx(__FILE__, fn,
					globalMask,
					RELAY_STIM_MISC,
					"msg=<%s> -> relay at slot=%d",
					outMsg->str,
					relayID
					);

				Send(relayID, outArea, inArea, sizeof(RELAY_TEST_MSG), MAX_MSG_SIZE);

				hndlReply(inArea);
				printf("-> ");
				fflush(stdout);
				}
				break;

			case 'q':
				x_it=1;
				break;

			default:
				printf("%s: unknown keypress <%c>\n",
					fn,
					line[0]);
				printf("-> ");
				fflush(stdout);
				break;
			} // end switch

		} // end if keyboard

	} // end while

fcLogx(__FILE__, fn,
	globalMask,
	RELAY_STIM_MISC,
	"done");

name_detach();

exit(0);

}// end relayStim
