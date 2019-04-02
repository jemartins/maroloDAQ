/*************************************************************

FILE:		relayInit.c

DESCRIPTION:	
This file contains initialization code for 
relay softwareIC. 

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
$Log: relayInit.c,v $
Revision 1.2  2002/12/03 21:21:34  root
v2.0 compatible

Revision 1.1  2002/12/03 19:51:56  root
Initial revision

=======================================================

*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "relayMsgs.h"
#include "maroloMsgs.h"

#define _ALLOC extern
#include "relay.h"
#undef _ALLOC

#include "relayProto.h"
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
char picoMgrName[20];
int myslot;

globalMask=0xff;
myName[0]=0;
recvID=-1;
picoMgrID=-1;

/*
sprintf(picoMgrName,"%s","164.41.10.186:PICOMGR");
picoMgrID=name_locate(picoMgrName);
if(picoMgrID == -1)
{
	printf("%s: can't locate %s\n",
			fn,picoMgrName);
	exit(0);
}

MAROLO_WHAT_YA_GOT_MSG *outMsg;
//MAROLO_WHAT_YA_GOT_MSG *inMsg;

//inMsg=(MAROLO_WHAT_YA_GOT_MSG *)inArea;
outMsg=(MAROLO_WHAT_YA_GOT_MSG *)outArea;

outMsg->token=MAROLO_WHAT_YA_GOT;
Send(picoMgrID, outArea, NULL, sizeof(MAROLO_WHAT_YA_GOT_MSG), MAX_NUM_MAROLO_TOKENS);
*/

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
				sprintf(myName,"%s_01", myName);
				myslot=name_attach(myName, NULL);
				if(myslot == -1)
					{
					printf("%s: unable to attach as <%s>\n",
						fn,
						myName);
					exit(0);
					}
				else
					printf("attached as <%s> myslot=%d\n",myName,myslot);
                                break;

				case 'p':
                                for(;*p != 0; p++);
                                sprintf(picoMgrName,"%s",++p);
                                picoMgrID=name_locate(picoMgrName);
                                if(picoMgrID == -1)
                                        {
                                        printf("%s: unable to attach as <%s>\n",
                                                fn,
                                                picoMgrName);
                                        exit(0);
                                        }
                                else
                                        printf("attached as <%s> myslot=%d\n",myName,myslot);
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


//picoMgrName[0]=0;
sprintf(picoMgrName, "%s", "164.41.10.186:PICOMGR");
picoMgrID=name_locate(picoMgrName);
/*
MAROLO_WHAT_YA_GOT_MSG *outMsg;
//MAROLO_WHAT_YA_GOT_MSG *inMsg;

//inMsg=(MAROLO_WHAT_YA_GOT_MSG *)inArea;
outMsg=(MAROLO_WHAT_YA_GOT_MSG *)outArea;

outMsg->token=MAROLO_WHAT_YA_GOT;
//outMsg->token=1;
Send(picoMgrID, outArea, NULL, sizeof(MAROLO_WHAT_YA_GOT_MSG), MAX_NUM_MAROLO_TOKENS);
*/
// check for compulsory args
if(myName[0] == 0)
	{
	myUsage();
	exit(0);
	}

// try to connect to trace logger
logger_ID = is_logger_upx(loggerName);

fcLogx(__FILE__, fn,
	0xff,
	RELAY_MARK,
	"myName=<%s> myslot=%d",
	myName,
	myslot
	);

fcLogx(__FILE__, fn,
	0xff,
	RELAY_MARK,
	"trace logger mask = 0x%04X",
	globalMask);

} /* end initialize */

/*===================================================
	myUsage - entry point
===================================================*/
void myUsage()
{
printf("====================== usage =============================\n");
printf(" usage for relay:\n");
printf("      relay -n <myName> <optionals>\n");
printf("      where optionals are:\n");
printf("        -m 0x<mask> - trace logger mask override\n");
printf("        -l <loggerName> - connect to trace logger\n");
printf("==========================================================\n");
}// end myUsage
