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

#include "relayMsgs.h"
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
    char *sender;
    UINT16 *token;
    
    initialize(argc, argv);
    
    fcLogx(__FILE__, fn,
           globalMask,
           RELAY_MARK,
           "starting"
    );
    
    while(!x_it)
    {
        MAROLO_WHAT_YA_GOT_MSG *outMsg;
        outMsg=(MAROLO_WHAT_YA_GOT_MSG *)outArea;
        outMsg->token=MAROLO_WHAT_YA_GOT;
        
        Send(maroloMgrID, outArea, NULL, sizeof(MAROLO_WHAT_YA_GOT_MSG), MAX_NUM_MAROLO_TOKENS);
        
        nbytes = Receive(&sender, inArea, MAX_MSG_SIZE);
        
        switch(*token)
        {
            case MAROLO_DO_READING:
            {
                
                MAROLO_DO_READING_MSG *inMsg;
                inMsg=(MAROLO_DO_READING_MSG *)inArea;
                
                //MAROLO_DO_READING_MSG *outMsg;
                //outMsg=(MAROLO_DO_READING_MSG *)outArea;
                
                //outMsg->ID=inMsg->ID;
                //outMsg->call=inMsg->call;
                
                fcLogx(__FILE__, fn,
                       globalMask,
                       RELAY_MISC,
                       "ID=<%d> CALL<%s>", inMsg->ID,0
                       outMsg->call
                );
                
                if(maroloMgrID != -1)
                {
                    int rbytes;
                    
                    fcLogx(__FILE__, fn,
                           globalMask,
                           RELAY_MISC,
                           "message being relayed to maroloMgr at slot=%d",
                           maroloMgrID
                    );
                    
                    rbytes=Send(maroloMgrID, inArea, inArea, nbytes,rbytes);
                    
                    Reply(sender,inArea,rbytes);
                }
                
            }
            break;
            
            default:
            {
                RELAY_ERROR_MSG *outMsg;
                
                outMsg=(RELAY_ERROR_MSG *)outArea;
                outMsg->token = RELAY_ERROR;
                
                Reply(sender,outArea,sizeof(RELAY_ERROR_MSG));
                
                fcLogx(__FILE__, fn,
                       globalMask,
                       RELAY_MARK,
                       "unknown token=%d",
                       *token
                );
                printf("%s:unknown token=%d\n",fn,*token);
            }
            break;
        } // end switch
    } // end while
    
    fcLogx(__FILE__, fn,
           globalMask,
           RELAY_FUNC_IO,
           "done");
    
    name_detach();
    
    exit(0);
    
}// end relay
