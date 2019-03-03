/*=====================================================

	This software was developed for
	iCanProgram Inc., Toronto, Canada

FILE:		picoMgrInit.c

DESCRIPTION:	
This file contains initialization code for picoMgr.

    Copyright (C) 2006 DrDAQ Application Project.

    This software is in the public domain.
    Permission to use, copy, modify, and distribute this software and its
    documentation for any purpose and without fee is hereby granted,
    without any conditions or restrictions.
    This software is provided "as is" without express or implied warranty.

    If you discover a bug or add an enhancement here's how to reach us:

        https://sourceforge.net/projects/drdaq

Revision history:
=======================================================
$Log: nameServerInit.c,v $
Revision 1.5  2006/07/07 17:26:04  jemartins
*** empty log message ***

Revision 1.4  2006/07/06 19:35:24  jemartins
pasted from bob files

Revision 1.3  2006/07/06 18:29:27  bobfcsoft
annotated changes

Revision 1.2  2006/07/06 14:19:52  jemartins
arrange seed code

Revision 1.1  2006/07/06 13:06:11  jemartins
startup

=======================================================

=====================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define _ALLOC extern
#include "nameServer.h"
#undef _ALLOC

#include "nameServerProto.h"
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

int myslot;

globalMask=0xff;
myName[0]=0;
guiName[0]=0;
readerName[0]=0;

#if 0
sprintf(myMsg,"hello there");
#endif

for(i=1; i<127; ++i)
{
    namesTable[i]=0;
}

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
    
                case 'g':
                        for(;*p != 0; p++);
                        sprintf(guiName,"%.19s",++p);
                        break;
                case 'r':
                        for(;*p != 0; p++);
                        sprintf(readerName,"%.19s",++p);
                        break;
			
                case 'l':
                    for(;*p != 0; p++);
                    sprintf(loggerName,"%.19s",++p);
                    break;
 
                default:
                        printf("%s:unknown arg %s\n",fn, p);
                        break;
                        
            }/*end switch*/
            
        } /* end if *p */
}/*end for i*/

// if manditory name is not supplied show usage
if(myName[0] == 0)
	{
	myUsage();
	exit(0);
	}

logger_ID = is_logger_upx(loggerName);


// initialize the nameTable
for(i=1; i<127; ++i)
{
	namesTable[i]=0;
}

fcLogx(__FILE__, fn,
	TRACE_MARK,	// force it to log
	TRACE_MARK,
	"executable: <%s> cksum=%lu",
	argv[0],
	cksum(argv[0])
	);

fcLogx(__FILE__, fn,
	TRACE_MARK,	// force it to log
	TRACE_MARK,
	"SIMPL name: <%s> slot=%d",
	myName,
	myslot
	);

fcLogx(__FILE__, fn,
	TRACE_MARK,	// force it to log
	TRACE_MARK,
	"trace logger mask = 0x%04X",
	globalMask);



} /* end initialize */


/*===================================================
	myUsage - entry point
===================================================*/
void myUsage()
{
printf("======================= usage =====================================\n");
printf("     nameServer -n <myName> <optionals>\n");
printf("     where optionals are:\n");
printf("        -m 0xXX         - set global mask\n");
printf("        -l <loggerName> - connect to trace logger\n");
printf("        -r <readerName> - connect to trace logger\n");
printf("        -g <guiName>    - connect to trace logger\n");
printf("===================================================================\n");
}// end myUsage
