/*************************************************************

FILE:		nameStimInit.c

DESCRIPTION:	
This file contains initialization code for nameStim.

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
$Log: nameStimInit.c,v $
Revision 1.2  2006/07/09 21:01:25  jemartins
*** empty log message ***

Revision 1.1  2006/07/06 14:31:12  bobfcsoft
seed code

=======================================================

*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "nameServerMsgs.h"

#define _ALLOC extern
#include "nameStim.h"
#undef _ALLOC

#include "nameStimProto.h"
#include "simplProto.h"
#include "loggerProto.h"
#include "simplmiscProto.h"

/*============================================
	initialize - entry point
============================================*/
void initialize(int argc, char **argv)
{
static char *fn="initialize";
int i;                          /* loop variable */
char myName[20];
char loggerName[20];
char nameServer_name[128];
int myslot;

globalMask=0xff;
myName[0]=0;
nameServer_name[0]=0;

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
                                break;

			case 's':
				{
				int j;

				if(*++p == 0) p++;
				sprintf(nameServer_name,"%.127s",p);

				for(j=0; j<2; j++)  // try 3 times
					{
					nameServerID=name_locate(nameServer_name);
					if(nameServerID != -1) break;
					printf("retrying nameLocate after 1sec sleep\n");
					sleep(1);
					}

				if(nameServerID == -1)
					{
					printf("%s: can't locate %s\n",
						fn,nameServer_name);
					exit(0);
					}
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

if(nameServer_name[0] == 0)
	{
	myUsage();
	name_detach();
	exit(0);
	}

// try to connect to trace logger
logger_ID = is_logger_upx(loggerName);

// arm the select routine
my_fds[0] = STDIN_FILENO;   // keyboard
my_fds[1] = whatsMyRecvfd(); // receive fifo

FD_ZERO(&watchset);
FD_SET(my_fds[0], &watchset);
FD_SET(my_fds[1], &watchset);

maxfd=0;
for(i=0; i<2; i++)
	if(maxfd < my_fds[i]) maxfd=my_fds[i];

fcLogx(__FILE__, fn,
	0xff,
	TRACE_MARK,
	"myName=<%s> myslot=%d",
	myName,
	myslot
	);

fcLogx(__FILE__, fn,
	0xff,
	TRACE_MARK,
	"nameServer name=<%s> slot=%d",
	nameServer_name,
	nameServerID
	);

fcLogx(__FILE__, fn,
	0xff,
	TRACE_MARK,
	"trace logger mask = 0x%04X",
	globalMask);

} /* end initialize */

/*===================================================
	myUsage - entry point
===================================================*/
void myUsage()
{
printf("====================== usage =============================\n");
printf(" usage for nameStim:\n");
printf("      nameStim -n <myName> -s <nameServer name>\n");
printf("      where optionals are:\n");
printf("        -m 0x<mask> - set trace log mask\n");
printf("        -l <loggerName> - connect to trace logger\n");
printf("==========================================================\n");
}// end myUsage
