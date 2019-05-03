/*************************************************************
 * 
 * FILE:		relay.c
 * 
 * DESCRIPTION:	
 * This program is an example of a relay softwareIC. 
 * 
 * AUTHOR:			R.D. Findlay
 * 
 * -----------------------------------------------------------------------
 *    Copyright (C) 2000, 2002 FCSoftware Inc. 
 * 
 *    This software is in the public domain.
 *    Permission to use, copy, modify, and distribute this software and its
 *    documentation for any purpose and without fee is hereby granted, 
 *    without any conditions or restrictions.
 *    This software is provided "as is" without express or implied warranty.
 * 
 *    If you discover a bug or add an enhancement here's how to reach us: 
 * 
 *	fcsoft@attcanada.ca
 * -----------------------------------------------------------------------
 * Revision history:
 * =======================================================
 * $Log: relay.c,v $
 * Revision 1.3  2003/04/03 16:44:57  root
 * fixed RedHat 7.x warnings
 * 
 * Revision 1.2  2002/12/03 21:21:25  root
 * v2.0 compatible
 * 
 * Revision 1.1  2002/12/03 19:51:51  root
 * Initial revision
 * 
 * =======================================================
 * 
 *************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#if 0
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/timeb.h>
#include <sys/time.h>
#endif

#include "maroloMsgs.h"

#define _ALLOC
#include "relay.h"
#undef _ALLOC

#include "relayProto.h"
#include "simplProto.h"
#include "loggerProto.h"

/*===============================================
 *	relay - entry point
 * ===============================================*/
int main(int argc, char **argv, char **envp)
{
    static char *fn="relay";
    int x_it=0;
    int nbytes;
    
    initialize(argc, argv);
    
    fcLogx(__FILE__, fn,
           globalMask,
           RELAY_MARK,
           "starting"
    );
    
    while(!x_it)
    {
        if(RecvHomeID != -1)
        {
            MAROLO_WHAT_YA_GOT_MSG *outMsg;
            outMsg=(MAROLO_WHAT_YA_GOT_MSG *)outArea;
            outMsg->token=MAROLO_WHAT_YA_GOT;
            
            nbytes=Send(RecvHomeID, outArea, inArea, sizeof(MAROLO_WHAT_YA_GOT_MSG), 8192);
        }
        
        if(RecvDestID != -1)
        {
            Send(RecvDestID, inArea, NULL, nbytes, 0);
        }
        
    } // end while
    
    fcLogx(__FILE__, fn,
           globalMask,
           RELAY_FUNC_IO,
           "done");
    
    name_detach();
    
    exit(0);
    
}// end relay
