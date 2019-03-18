#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "drdaqMsgs.h"

#define _ALLOC
#include "picoStim.h"
#undef _ALLOC

#include "picoStimProto.h"
#include "simplProto.h"
#include "loggerProto.h"

int myID;

/*--------------------------------------
	picoStim - entry point
--------------------------------------*/
int main(int argc, char **argv)
{
	static char *fn="picoStim";
	int i;
        int x_it=0;
 
        initialize(argc, argv);
	
	fcLogx(__FILE__, fn,
		globalMask,
		PICO_STIM_MARK,
		"starting myID=%d",
                myID);
while(!x_it)
{
    
    PICO_WHAT_YA_GOT_MSG *outMsg;
    PICO_START_MSG *inMsg;
    
    outMsg=(PICO_WHAT_YA_GOT_MSG *)outArea;
    outMsg->token=PICO_WHAT_YA_GOT;
    outMsg->ID=myID;
    
    Send(picoMgrID, 
            outArea, 
            inArea,
            sizeof(PICO_WHAT_YA_GOT_MSG),
            sizeof(PICO_START_MSG));
    
    inMsg=(PICO_START_MSG *)inArea;
    
    if(inMsg->token == PICO_READING_START)
    {
        fcLogx(__FILE__, fn,
               globalMask,
               PICO_STIM_MISC,
               "got READING_START period=%d msec maxReadings=%d",
               inMsg->period,
               inMsg->maxReadings
              );
        
        for (i=0; i<10; i++) {
/*        
            PICO_TEMPERATURE_MSG *outMsg;
            PICO_TEMPERATURE_MSG *inMsg;
            
            outMsg=(PICO_TEMPERATURE_MSG *)outArea;
            outMsg->token=PICO_TEMPERATURE;
            outMsg->ID=myID;
            
            inMsg=(PICO_TEMPERATURE_MSG *)inArea;
            
            Send(picoMgrID, 
                 outArea, 
                 inArea, 
                 sizeof(PICO_TEMPERATURE_MSG), 
                 sizeof(PICO_TEMPERATURE_MSG));
            
            fcLogx(__FILE__, fn,
                   globalMask,
                   PICO_STIM_MISC,
                   "temperature=%d.%d C",
                   inMsg->temperature/10,
                   inMsg->temperature%10);

            printf("temperature %d.%d C\n",
                   inMsg->temperature/10,
                   inMsg->temperature%10);
*/
            PICO_DO_READING_MSG *outMsg1;
            outMsg1=(PICO_DO_READING_MSG *)outArea;
            outMsg->token=PICO_TEMPERATURE;
            outMsg1->ID=myID; 
            outMsg1->set_value=11;
            
            Send(picoMgrID, 
                 outArea, 
                 NULL, 
                 sizeof(PICO_TEMPERATURE_MSG), 
                 0);

            PICO_STOP_MSG *inMsg1;
            
            inMsg1=(PICO_STOP_MSG *)inArea;
            
            if (inMsg1->token == PICO_READING_STOP)
            { 
                x_it = 1;
                break;
            }
            
            sleep (1);	
        }

    } // end if READING_START
        
    PICO_STOP_MSG *outMsg3;
    
    outMsg3=(PICO_STOP_MSG *)outArea;
    outMsg3->token=PICO_READING_STOP;
    outMsg3->ID=myID;
    
    Send(picoMgrID, 
            outArea, 
            NULL,
            sizeof(PICO_STOP_MSG),
            0);
    
    fcLogx(__FILE__, fn,
           globalMask,
           PICO_STIM_MISC,
           "STOP Measurements");


}// end while

printf("end game\n");

fcLogx(__FILE__, fn,
       globalMask,
       PICO_STIM_MISC,
       "done");

name_detach();

exit(1);

}// end picoStim


