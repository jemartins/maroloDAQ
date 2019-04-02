/*************************************************************

FILE:		recvSimInit.c

DESCRIPTION:	
This file contains initialization routines for receiverSim. 

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
$Log: recvSimInit.c,v $
Revision 1.2  2002/12/03 21:20:16  root
v2.0 compatible

Revision 1.1  2002/12/03 19:54:11  root
Initial revision

=======================================================

*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "relayMsgs.h"

#define _ALLOC extern
#include "receiverSim.h"
#undef _ALLOC

#include "recvSimProto.h"
#include "simplProto.h"
#include "loggerProto.h"
#include "simplmiscProto.h"  // atoh

/*============================================
	initialize - entry point
============================================*/
void initialize(int argc, char **argv)
{
static char *fn="initialize";
int i;                          /* loop variable */
char loggerName[20];
char relay_name[20];
int myslot;
RELAY_REGISTER_MSG *outMsg;

globalMask=0xff;
myName[0]=0;
relay_name[0]=0;
backgroundMode=0;

/*===============================================
  process command args
===============================================*/
for(i=1; i<=argc; ++i)
        {
        char *p = argv[i];

        if(p == NULL) continue;

        if(*p == '-')
                {
                switch(*++p)
                        {
			case 'b':
				backgroundMode=1;
				break;

                        case 'n':
                                for(;*p != 0; p++);
				sprintf(myName,"%s",++p);
				myslot=name_attach(myName, NULL);
				if(myslot == -1)
					{
					printf("%s: unable to attach as <%s>\n",
						fn,
						myName);

					exit(0);
					}
#if 0
				else
					printf("attached as <%s> myslot=%d\n",
						myName,myslot);
#endif
                                break;

			case 'r':  // relay name
				if(*++p == 0) p++;
				sprintf(relay_name,"%.19s",p);

				relayID=name_locate(relay_name);
				if(relayID == -1)
					{
					printf("%s: can't locate %s\n",
						fn,relay_name);
					exit(0);
					}
				break;

			case 'l':
                                for(;*p != 0; p++);
				sprintf(loggerName,"%.19s",++p);
				break;

			case 'm':
				if(*++p == 0) p++;
				globalMask=atoh(&p[2]);  // skip 0x
				break;

                        default:
				printf("%s:unknown arg %s\n",fn, p);
                                break;
                        }/*end switch*/
                } /* end if *p */
        }/*end for i*/

// check for compulsory args
if(myName[0] == 0)
	{
	myUsage();
	exit(0);
	}

if(relay_name[0] == 0)
	{
	myUsage();
	name_detach();
	exit(0);
	}

// try to connect to trace logger
logger_ID = is_logger_upx(loggerName);

// arm the select routine
my_fds[0] = whatsMyRecvfd(); // receive fifo

FD_ZERO(&watchset);
FD_SET(my_fds[0], &watchset);

maxfd=0;
if(backgroundMode)
	{
	maxfd=my_fds[0];
	}
else
	{
	my_fds[1] = STDIN_FILENO;   // keyboard
	FD_SET(my_fds[1], &watchset);

	for(i=0; i<2; i++)
		if(maxfd < my_fds[i]) maxfd=my_fds[i];
	}

fcLogx(__FILE__, fn,
	0xff,
	RECV_SIM_MARK,
	"myName=<%s> myslot=%d",
	myName,
	myslot
	);

fcLogx(__FILE__, fn,
	0xff,
	RECV_SIM_MARK,
	"trace logger mask = 0x%04X",
	globalMask);

// register with relay
outMsg=(RELAY_REGISTER_MSG *)outArea;
outMsg->token = RELAY_REGISTER;
sprintf(outMsg->myName,"%s",myName);

fcLogx(__FILE__, fn,
	globalMask,
	RECV_SIM_MARK,
	"REGISTERing <%s> with relay at slot=%d",
	myName,
	relayID
	);

Send(relayID, outArea, NULL, sizeof(RELAY_REGISTER_MSG), MAX_MSG_SIZE);

} /* end initialize */

/*===================================================
	myUsage - entry point
===================================================*/
void myUsage()
{
printf("====================== usage =============================\n");
printf(" usage for receiverSim:\n");
printf("      receiverSim -n <myName> <optionals>\n");
printf("      where optionals are:\n");
printf("        -m 0x<mask> - trace logger mask override\n");
printf("        -l <loggerName> - connect to trace logger\n");
printf("==========================================================\n");
}// end myUsage
