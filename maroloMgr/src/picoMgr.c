#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//#include "drdaqMsgs.h"
#include "maroloMsgs.h"

#define _ALLOC
#include "picoMgr.h"
#undef _ALLOC

#include "picoMgrProto.h"
#include "loggerProto.h"

/*----------------------------------------
 *	picoMgr - entry point
 * ----------------------------------------*/
int main(int argc, char **argv)
{
    static char *fn="picoMgr";
    MAROLO_TOKEN *token;
    char *fromWhom;
    int nbytes;
    int myID;
    
    initialize(argc, argv);
    
    token=(MAROLO_TOKEN *)inArea;
    while(1)
    {
        nbytes = Receive(&fromWhom, inArea, 8192);
        
        switch(*token)
        {
            case MAROLO_WHAT_YA_GOT:
            {
                
                MAROLO_WHAT_YA_GOT_MSG *inMsg;
                
                inMsg=(MAROLO_WHAT_YA_GOT_MSG *)inArea;
                myID=inMsg->ID;
                
                fcLogx(__FILE__, fn,
                       globalMask,
                       PICOMGR_MISC,
                       "WHAT_YA_GOT myID=%d",
                       myID);
                
                routingTable[myID].picoReaderPending=fromWhom;
                
                routingTable[myID].stopFlag = 0;
                
            }
            break;
            
            case MAROLO_READING_START:
            {
                MAROLO_START_MSG *inMsg;
                
                inMsg=(MAROLO_START_MSG *)inArea;				
                myID=inMsg->ID;
                
                fcLogx(__FILE__, fn,
                       globalMask,
                       PICOMGR_MISC,
                       "START myID=%d ",
                       myID
                );
                
                if(routingTable[myID].picoReaderPending != NULL) // picoReader is ready
                {
                    Reply(routingTable[myID].picoReaderPending, inArea, nbytes);
                    routingTable[myID].picoReaderPending=NULL;
                }
                
                Reply(fromWhom, NULL, 0);
                
            }
            break;
            
            case MAROLO_LED:
            {
                fcLogx(__FILE__, fn,
                       globalMask,
                       PICOMGR_MISC,
                       "LED is currently %s",
                       (ledState == 1) ? "on" : "off");
                
                if(ledState == 1) // its on
                {
                    turnLedOff();
                    ledState =0;
                }
                else
                {
                    turnLedOn();
                    ledState =1;
                }
                
                fcLogx(__FILE__, fn,
                       globalMask,
                       PICOMGR_MISC,
                       "LED is now %s",
                       (ledState == 1) ? "on" : "off");
                
                Reply(fromWhom, NULL, 0);
            }
            break;
	    case MAROLO_INFO:
	    case MAROLO_VERSION:
            case MAROLO_WHAT_READINGS:
            {
                int myvalue;
                
                MAROLO_DO_READING_MSG *inMsg;
                
                inMsg=(MAROLO_DO_READING_MSG *)inArea;                    
                myID=inMsg->ID;
                myvalue=inMsg->call; 
                
                if (routingTable[myID].stopFlag == 0)
                {
                    
                    MAROLO_MEASURE_MSG *outMsg;
                    
                    int myreading;
                    
                    struct timeval	tv_now;
                    struct timezone tz_now;   // only needed to complete gettimeofday()
                    struct tm *now;   // only needed for trace log message
                    
                    
                    myreading=readMarolo(myvalue);
                    
                    gettimeofday(&tv_now,  &tz_now);
                    now = localtime((time_t *)&tv_now.tv_sec);  // only needed for log below
                    
                    fcLogx(__FILE__, fn,
                           globalMask,
                           PICOMGR_MISC,
                           "ADC reading=%d at %02d%02d%02d.%03d",
                           myreading,
                           now->tm_hour,
                           now->tm_min,
                           now->tm_sec,
                           (int)tv_now.tv_usec /1000  // covert to msec
                    );
                    
                    fcLogx(__FILE__, fn,
                           globalMask,
                           PICOMGR_MISC,
                           "myID=%d call=%d",
                           myID, myvalue);
                    
                    outMsg=(MAROLO_MEASURE_MSG *)outArea;
                    outMsg->token=MAROLO_WHAT_READINGS;
                    outMsg->adcReading=myreading;
                    outMsg->mystamp.tv_sec=tv_now.tv_sec;
                    outMsg->mystamp.tv_usec=tv_now.tv_usec;;
                    
                    Reply(fromWhom, outArea, sizeof(MAROLO_MEASURE_MSG));
                    
                } else
                {
                    MAROLO_STOP_MSG *outMsg;
                    
                    outMsg=(MAROLO_STOP_MSG *)outArea;
                    outMsg->token=MAROLO_READING_STOP;
                    
                    fcLogx(__FILE__, fn,
                           globalMask,
                           PICOMGR_MISC,
                           "STOP Measurements token=%d", outMsg->token);
                    
                    Reply(fromWhom,  outArea,   sizeof (MAROLO_STOP_MSG));
                }
            }
            break;
            
            
            case MAROLO_READING_STOP:
            {
                
                MAROLO_STOP_MSG *inMsg;
                
                inMsg=(MAROLO_STOP_MSG *)inArea;
                myID=inMsg->ID;
                
                fcLogx(__FILE__, fn,
                       globalMask,
                       PICOMGR_MISC,
                       "STOP Measurements myID=%d",
                       myID);
                
                Reply(fromWhom, NULL, 0);
                
                routingTable[myID].stopFlag=1;
            }
            break;
                            default:
                        fcLogx(__FILE__, fn,
                                globalMask,
                                PICOMGR_MISC,
                                "unknown token=%d",
                                *token);

                        Reply(fromWhom,NULL,0);
                break;

        }
    } // end while
    
    name_detach();
    
    return(1);
}// end picoMgr
