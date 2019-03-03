/*=======================================================

FILE:		nameSever.c

DESCRIPTION:	
This file contains main source for picoMgr.

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
$Log: nameServer.c,v $
Revision 1.11  2006/07/09 21:12:36  jemartins
clean code

Revision 1.10  2006/07/08 11:42:46  bobfcsoft
chasing 52 problem

Revision 1.9  2006/07/07 19:52:46  bobfcsoft
bobs changes

Revision 1.8  2006/07/07 17:26:04  jemartins
*** empty log message ***

Revision 1.7  2006/07/06 20:26:40  jemartins
added outMsg

Revision 1.6  2006/07/06 19:35:24  jemartins
pasted from bob files

Revision 1.5  2006/07/06 18:29:27  bobfcsoft
annotated changes

Revision 1.4  2006/07/06 14:48:25  jemartins
developed case FREE_NAME

Revision 1.3  2006/07/06 14:19:52  jemartins
arrange seed code

Revision 1.2  2006/07/06 13:39:34  jemartins
desenvolved case REQUEST_NAME

Revision 1.1  2006/07/06 13:06:11  jemartins
startup


=====================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nameServerMsgs.h"

#define _ALLOC
#include "nameServer.h"
#undef _ALLOC

#include "nameServerProto.h"
#include "loggerProto.h"

/*----------------------------------------
	nameServer - entry point
----------------------------------------*/
int main(int argc, char **argv)
{
static char *fn="nameServer";
NAME_TOKEN *token;
char *fromWhom;
int nbytes;
int myID;

char nameInUse[64];
int i;

initialize(argc, argv);

token=(NAME_TOKEN *)inArea;
while(1)
{
	nbytes = Receive(&fromWhom, inArea, 8192);

	switch(*token)
	{
		case REQUEST_NAME:
		{
                    NAME_SERVER_MSG *inMsg;                                    
                    NAME_SERVER_MSG *outMsg;
		    
                    inMsg=(NAME_SERVER_MSG *)inArea;
                    
		    for(i=1; i<127; ++i)
                    {
                            if (namesTable[i] == 0)
                            {
                                sprintf(nameInUse,
						"%s_%02d,%s_%02d",
						guiName, 
						i,
						readerName,
						i
						);

				namesTable[i] = 1;
                                break;
                            } // end if
                    } // end for
                    
                    fcLogx(__FILE__, fn,
                           globalMask,
                           TRACE_MISC,
                           "REQUEST ID=%d ",
                           i);
                    
                    outMsg=(NAME_SERVER_MSG *)outArea;
                    outMsg->ID=i;
		    
		    sprintf(outMsg->guiName,
				    "%.16s_%02d",
				    guiName,
				    outMsg->ID);
		    
		    sprintf(outMsg->readerName,
				    "%.16s_%02d",
				    readerName,
				    outMsg->ID);

                    fcLogx(__FILE__, fn,
                           globalMask,
                           TRACE_MISC,
                           "guiName[%d]=<%s> readerName[%d]=<%s> ",
                           i,
			   outMsg->guiName,
			   i,
			   outMsg->readerName);
                    
		    Reply(fromWhom, outArea, sizeof(NAME_SERVER_MSG));
		    
		}
		break;

		case FREE_NAME:
		{

                    NAME_SERVER_MSG *inMsg;
                    
                    inMsg=(NAME_SERVER_MSG *)inArea;
                    myID=inMsg->ID;

                    fcLogx(__FILE__, fn,
                            globalMask,
                            TRACE_MISC,
                            "FREE ID=%d",
                            inMsg->ID
                            );
                    
                    Reply(fromWhom,NULL,0);
            
                    namesTable[myID] = 0;

		}
		break;
			
		default:
			fcLogx(__FILE__, fn,
				globalMask,
                                TRACE_MISC,
				"unknown token=%d",
				*token);

			Reply(fromWhom,NULL,0);
		break;
	}

} // end while

name_detach();

exit(1);
}// end nameServer
