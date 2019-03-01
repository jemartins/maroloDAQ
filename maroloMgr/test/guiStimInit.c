/*************************************************************

	This software was developed for
	iCanProgram Inc., Toronto, Canada

FILE:		guiStimInit.c

DESCRIPTION:	
This file contains initialization code for guiStim.

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
$Log: guiStimInit.c,v $
Revision 1.6  2007/06/04 14:13:09  jemartins
added readAngle

Revision 1.5  2006/06/24 15:38:24  jemartins
added myID

Revision 1.4  2006/05/27 12:25:03  jemartins
added include drdaqMsgs.h

Revision 1.3  2006/05/17 21:24:07  jemartins
added Copyright

Revision 1.2  2006/03/20 22:38:00  bobfcsoft
added START logic

Revision 1.1  2006/03/15 20:27:27  bobfcsoft
added guiStim

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
#include "guiStim.h"
#undef _ALLOC

#include "guiStimProto.h"
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
char picoMgr_name[20];
int myslot;
extern int myID;

globalMask=0xff;
myName[0]=0;
picoMgr_name[0]=0;

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
#if 0
				else
					printf("attached as <%s> myslot=%d\n",myName,myslot);
#endif
                                break;

			case 'p':
				{
				int j;

				if(*++p == 0) p++;
				sprintf(picoMgr_name,"%.19s",p);

				for(j=0; j<2; j++)  // try 3 times
					{
					picoMgrID=name_locate(picoMgr_name);
					if(picoMgrID != -1) break;
					printf("retrying nameLocate after 1sec sleep\n");
					sleep(1);
					}

				if(picoMgrID == -1)
					{
					printf("%s: can't locate %s\n",
						fn,picoMgr_name);
					exit(0);
					}
				}
				break;

			case 'l':
                                for(;*p != 0; p++);
				sprintf(loggerName,"%.19s",++p);
				break;

			case 'I':
				for(;*p != 0; p++);
				myID=atoi(++p);
                                printf("myID=%d\n",myID);
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

if(picoMgr_name[0] == 0)
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
	GUI_STIM_MARK,
	"myName=<%s> myslot=%d myID=%d",
	myName,
	myslot,
	myID
	);

fcLogx(__FILE__, fn,
	0xff,
	GUI_STIM_MARK,
	"picoMgr name=<%s> slot=%d",
	picoMgr_name,
	picoMgrID
	);

fcLogx(__FILE__, fn,
	0xff,
	GUI_STIM_MARK,
	"trace logger mask = 0x%04X",
	globalMask);

} /* end initialize */

/*===================================================
	myUsage - entry point
===================================================*/
void myUsage()
{
printf("====================== usage =============================\n");
printf(" usage for guiStim:\n");
printf("      guiStim -n <myName> -p <picoMgr name>\n");
printf("            -o <outfile> <optionals>\n");
printf("      where optionals are:\n");
printf("        -m 0x<mask> - set trace log mask\n");
printf("        -l <loggerName> - connect to trace logger\n");
printf("==========================================================\n");
}// end myUsage
