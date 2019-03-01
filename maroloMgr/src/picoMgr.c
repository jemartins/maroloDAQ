/*=======================================================

FILE:		picoMgr.c

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
$Log: picoMgr.c,v $
Revision 1.40  2010/02/11 17:28:59  jemartins
added XY feature

Revision 1.39  2007/06/09 16:31:56  jemartins
changed fcLogx in case ANGLE

Revision 1.38  2007/06/09 15:23:58  jemartins
fixed bugs in fclog

Revision 1.37  2007/06/07 15:01:29  jemartins
clean code

Revision 1.36  2007/06/07 00:01:18  jemartins
fix bugs

Revision 1.35  2007/06/06 22:46:27  jemartins
adjusted in PICO_ANGLE

Revision 1.34  2007/06/06 20:52:12  jemartins
adjusted ANGLE option

Revision 1.33  2007/06/05 20:12:26  juniocruz
Angle adjusted as float

Revision 1.32  2007/06/05 19:47:29  jemartins
define angle in float

Revision 1.31  2007/06/05 13:26:20  juniocruz
*** empty log message ***

Revision 1.30  2007/06/04 22:51:33  jemartins
more cleanup

Revision 1.29  2007/06/04 22:50:34  jemartins
cleanup

Revision 1.28  2007/06/04 20:48:13  juniocruz
Added angle conversion still with bugs

Revision 1.27  2007/06/04 14:59:09  jemartins
removed %f

Revision 1.26  2007/06/04 14:28:22  jemartins
clean code

Revision 1.25  2007/06/04 14:13:08  jemartins
added readAngle

Revision 1.24  2007/06/02 15:59:01  jemartins
clean timestamp in CALIBRATE

Revision 1.23  2007/06/02 15:41:07  jemartins
added case ANGLE_CALIBRATE

Revision 1.22  2006/09/26 13:01:03  jemartins
added ymin var

Revision 1.21  2006/07/23 23:12:44  jemartins
cleanup

Revision 1.20  2006/06/25 14:01:39  jemartins
*** empty log message ***

Revision 1.19  2006/06/24 15:37:13  jemartins
*** empty log message ***

Revision 1.18  2006/06/24 15:34:38  jemartins
*** empty log message ***

Revision 1.17  2006/06/22 18:01:56  jemartins
added myID

Revision 1.16  2006/06/22 14:03:38  jemartins
added myID

Revision 1.15  2006/05/27 12:22:52  jemartins
added include drdaqMsgs.h

Revision 1.14  2006/05/24 18:07:56  jemartins
added new cases

Revision 1.13  2006/05/24 16:04:38  jemartins
changed fcLogx

Revision 1.12  2006/05/24 14:01:25  jemartins
added set_value var

Revision 1.11  2006/05/24 13:33:25  jemartins
added timestamp

Revision 1.10  2006/05/15 18:12:00  jemartins
added Copyright

Revision 1.9  2006/04/27 19:00:38  jemartins
*** empty log message ***

Revision 1.8  2006/04/24 16:18:50  jemartins
changes in case PICO_TEMPERATURE

Revision 1.7  2006/04/23 17:23:18  jemartins
add stopFlag var

Revision 1.6  2006/04/21 22:05:50  jemartins
add case PICO_READING_STOP

Revision 1.5  2006/04/21 01:37:13  jemartins
add readTemperature() call

Revision 1.4  2006/04/21 01:35:15  jemartins
changes in readTemperature

Revision 1.3  2006/03/20 22:38:00  bobfcsoft
added START logic

Revision 1.2  2006/03/13 20:50:35  bobfcsoft
some cleanup

Revision 1.1.1.1  2006/03/07 21:29:47  bobfcsoft
startup

=====================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "drdaqMsgs.h"

#define _ALLOC
#include "picoMgr.h"
#undef _ALLOC

#include "picoMgrProto.h"
#include "loggerProto.h"

/*----------------------------------------
	picoMgr - entry point
----------------------------------------*/
int main(int argc, char **argv)
{
static char *fn="picoMgr";
PICO_TOKEN *token;
char *fromWhom;
int nbytes;
int myID;

initialize(argc, argv);

token=(PICO_TOKEN *)inArea;
while(1)
	{
	nbytes = Receive(&fromWhom, inArea, 8192);

	switch(*token)
		{
		case PICO_WHAT_YA_GOT:
			{
                        
                        PICO_WHAT_YA_GOT_MSG *inMsg;
                    
                        inMsg=(PICO_WHAT_YA_GOT_MSG *)inArea;
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

		case PICO_READING_START:
			{
			PICO_START_MSG *inMsg;

			inMsg=(PICO_START_MSG *)inArea;				
			myID=inMsg->ID;
			
			fcLogx(__FILE__, fn,
				globalMask,
				PICOMGR_MISC,
				"START myID=%d TMax=%5.2f sec period=%d msec maxReadings=%d nsensors=%d sensor(n_modo,0)=%d sensor(set_value,0)=%d sensor(n_modo,1)=%d sensor(set_value,1)=%d",
				myID,
				inMsg->TMax,
				inMsg->period,
				inMsg->maxReadings,
				inMsg->nsensors,
				inMsg->sensor[0].n_modo,
				inMsg->sensor[0].set_value,
				inMsg->sensor[1].n_modo,
				inMsg->sensor[1].set_value
				);

			fcLogx(__FILE__, fn,
				globalMask,
				PICOMGR_MISC,
				"n_passo=%d AutoEscala=%d xmax=%5.1f ymax=%5.1f ymin=%5.1f maior_divx=%5.1f menor_divx=%5.1f maior_divy=%5.1f menor_divy=%5.1f, XY=%d",
				inMsg->n_passo,
				inMsg->AutoEscala,
				inMsg->xmax,
				inMsg->ymax,
				inMsg->ymin,
				inMsg->maior_divx,
				inMsg->menor_divx,
				inMsg->maior_divy,
				inMsg->menor_divy,
				inMsg->XY
				);

			if(routingTable[myID].picoReaderPending != NULL) // picoReader is ready
				{
				Reply(routingTable[myID].picoReaderPending, inArea, nbytes);
				routingTable[myID].picoReaderPending=NULL;
				}
			
			Reply(fromWhom, NULL, 0);

			}
			break;
	
		case PICO_LED:
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

		case PICO_SOUND_WAVEFORM:
                {
                    int myvalue;
                    
                    PICO_DO_READING_MSG *inMsg;
                    
                    inMsg=(PICO_DO_READING_MSG *)inArea;                    
                    myID=inMsg->ID;
                    myvalue=inMsg->set_value; 
                    
                    if (routingTable[myID].stopFlag == 0)
                    {

                        PICO_SOUND_WAVEFORM_MSG *outMsg;
        
                        int mywave;
        
                        struct timeval	tv_now;
                        struct timezone tz_now;   // only needed to complete gettimeofday()
                        struct tm *now;   // only needed for trace log message


                        mywave=readWaveForm(myvalue);
        
                        gettimeofday(&tv_now,  &tz_now);
                        now = localtime((time_t *)&tv_now.tv_sec);  // only needed for log below
        
                        fcLogx(__FILE__, fn,
                                globalMask,
                                PICOMGR_MISC,
                                "waveform=%d at %02d%02d%02d.%03d",
                                mywave,
                                now->tm_hour,
                                now->tm_min,
                                now->tm_sec,
                                (int)tv_now.tv_usec /1000  // covert to msec
                                );
        
                        fcLogx(__FILE__, fn,
                                globalMask,
                                PICOMGR_MISC,
                                "myID=%d set_value=%d",
                                myID, myvalue);
        
                        outMsg=(PICO_SOUND_WAVEFORM_MSG *)outArea;
                        outMsg->token=PICO_SOUND_WAVEFORM;
                        outMsg->sound_waveform=mywave;
                        outMsg->mystamp.tv_sec=tv_now.tv_sec;
                        outMsg->mystamp.tv_usec=tv_now.tv_usec;;
        
                        Reply(fromWhom, outArea, sizeof(PICO_SOUND_WAVEFORM_MSG));
    
                    } else
                    {
                        PICO_STOP_MSG *outMsg;

                        outMsg=(PICO_STOP_MSG *)outArea;
                        outMsg->token=PICO_READING_STOP;
                                
                        fcLogx(__FILE__, fn,
                                        globalMask,
                                        PICOMGR_MISC,
                                        "STOP Measurements token=%d", outMsg->token);
                                
                        Reply(fromWhom,  outArea,   sizeof (PICO_STOP_MSG));
                    }
		}
		break;

		case PICO_SOUND_LEVEL:
                {
                    int myvalue;
	
                    PICO_DO_READING_MSG *inMsg;
                    
                    inMsg=(PICO_DO_READING_MSG *)inArea;                    
                    myID=inMsg->ID;
                    myvalue=inMsg->set_value;
                    
		    if (routingTable[myID].stopFlag == 0) 
                    {

			PICO_SOUND_LEVEL_MSG *outMsg;
	
			int mysound;
			
                        struct timeval	tv_now;
			struct timezone tz_now;   // only needed to complete gettimeofday()
			struct tm *now;   // only needed for trace log message

			mysound=readSoundLevel(myvalue);
	
			gettimeofday(&tv_now,  &tz_now);
			now = localtime((time_t *)&tv_now.tv_sec);  // only needed for log below
	
			fcLogx(__FILE__, fn,
			       globalMask,
			       PICOMGR_MISC,
			       "soundlevel=%d.%d at %02d%02d%02d.%03d",
			       mysound/10,
			       mysound%10,
			       now->tm_hour,
			       now->tm_min,
			       now->tm_sec,
			       (int)tv_now.tv_usec /1000  // covert to msec
			       );
	
			fcLogx(__FILE__, fn,
			       globalMask,
			       PICOMGR_MISC,
			       "myID=%d set_value=%d",
			       myID, myvalue);
	
                        outMsg=(PICO_SOUND_LEVEL_MSG *)outArea;
			outMsg->token=PICO_SOUND_LEVEL;
			outMsg->sound_level=mysound;
			outMsg->mystamp.tv_sec=tv_now.tv_sec;
			outMsg->mystamp.tv_usec=tv_now.tv_usec;;
	
			Reply(fromWhom, outArea, sizeof(PICO_SOUND_LEVEL_MSG));
	
                    } else
                    {
                        PICO_STOP_MSG *outMsg;
    
                        outMsg=(PICO_STOP_MSG *)outArea;
                        outMsg->token=PICO_READING_STOP;
                            
                        fcLogx(__FILE__, fn,
                                globalMask,
                                PICOMGR_MISC,
                                "STOP Measurements token=%d", outMsg->token);
                            
                        Reply(fromWhom,  outArea,   sizeof (PICO_STOP_MSG));
                    }
                }
		break;

		case PICO_VOLTAGE:
                {
                    int myvalue;
                    
                    PICO_DO_READING_MSG *inMsg;
                    
                    inMsg=(PICO_DO_READING_MSG *)inArea;                    
                    myID=inMsg->ID;
                    myvalue=inMsg->set_value; 
                    
		    if (routingTable[myID].stopFlag == 0) 
                    {

			PICO_VOLTAGE_MSG *outMsg;
	
			int myvoltage;
	
			struct timeval	tv_now;
			struct timezone tz_now;   // only needed to complete gettimeofday()
			struct tm *now;   // only needed for trace log message

			myvoltage=readVoltage(myvalue);
	
			gettimeofday(&tv_now,  &tz_now);
			now = localtime((time_t *)&tv_now.tv_sec);  // only needed for log below
	
			fcLogx(__FILE__, fn,
			       globalMask,
			       PICOMGR_MISC,
			       "voltage=%d at %02d%02d%02d.%03d",
			       myvoltage,
			       now->tm_hour,
			       now->tm_min,
			       now->tm_sec,
			       (int)tv_now.tv_usec /1000  // covert to msec
			       );
	
			fcLogx(__FILE__, fn,
			       globalMask,
			       PICOMGR_MISC,
			       "myID=%d set_value=%d",
			       myID, myvalue);
	
                        outMsg=(PICO_VOLTAGE_MSG *)outArea;
			outMsg->token=PICO_VOLTAGE;
			outMsg->voltage=myvoltage;
			outMsg->mystamp.tv_sec=tv_now.tv_sec;
			outMsg->mystamp.tv_usec=tv_now.tv_usec;;
	
			Reply(fromWhom, outArea, sizeof(PICO_VOLTAGE_MSG));
	
                    } else
                    {
                        PICO_STOP_MSG *outMsg;
    
                        outMsg=(PICO_STOP_MSG *)outArea;
                        outMsg->token=PICO_READING_STOP;
                            
                        fcLogx(__FILE__, fn,
                                globalMask,
                                PICOMGR_MISC,
                                "STOP Measurements token=%d", outMsg->token);
                            
                        Reply(fromWhom,  outArea,   sizeof (PICO_STOP_MSG));
                    }
                }
		break;
                
                case PICO_RESISTANCE:
                {
                    PICO_DO_READING_MSG *inMsg;
                    
                    int myvalue;

                    inMsg=(PICO_DO_READING_MSG *)inArea;                    
                    myID=inMsg->ID;
                    myvalue=inMsg->set_value; 
                                
                    if (routingTable[myID].stopFlag == 0) 
                    {
            
                        PICO_RESISTANCE_MSG *outMsg;
                    
                        int myresistance;
                        struct timeval	tv_now;
                        struct timezone tz_now;   // only needed to complete gettimeofday()
                        struct tm *now;   // only needed for trace log message
            
                        myresistance=readResistance(myvalue);
                    
                        gettimeofday(&tv_now,  &tz_now);
                        now = localtime((time_t *)&tv_now.tv_sec);  // only needed for log below
                    
                        fcLogx(__FILE__, fn,
                                globalMask,
                                PICOMGR_MISC,
                                "resistance=%d at %02d%02d%02d.%03d",
                                myresistance,
                                now->tm_hour,
                                now->tm_min,
                                now->tm_sec,
                                (int)tv_now.tv_usec /1000  // covert to msec
                                );
                    
                        fcLogx(__FILE__, fn,
                                globalMask,
                                PICOMGR_MISC,
                                "myID=%d set_value=%d",
                                myID, myvalue);
                    
                        outMsg=(PICO_RESISTANCE_MSG *)outArea;
                        outMsg->token=PICO_RESISTANCE;
                        outMsg->resistance=myresistance;
                        outMsg->mystamp.tv_sec=tv_now.tv_sec;
                        outMsg->mystamp.tv_usec=tv_now.tv_usec;;
                    
                        Reply(fromWhom, outArea, sizeof(PICO_RESISTANCE_MSG));
                    
                    } else
                    {
                        PICO_STOP_MSG *outMsg;
                
                        outMsg=(PICO_STOP_MSG *)outArea;
                        outMsg->token=PICO_READING_STOP;
                                        
                        fcLogx(__FILE__, fn,
                                globalMask,
                                PICOMGR_MISC,
                                "STOP Measurements token=%d", outMsg->token);
                                        
                        Reply(fromWhom,  outArea,   sizeof (PICO_STOP_MSG));
                    }
                }
                break;

		case PICO_PH:
                {
                    int myvalue;
	
                    PICO_DO_READING_MSG *inMsg;
                    
                    inMsg=(PICO_DO_READING_MSG *)inArea;                    
                    myID=inMsg->ID;
                    myvalue=inMsg->set_value; 
                    
		    if (routingTable[myID].stopFlag == 0) 
                    {

			PICO_PH_MSG *outMsg;
	
			int myph;
			
                        struct timeval	tv_now;
			struct timezone tz_now;   // only needed to complete gettimeofday()
			struct tm *now;   // only needed for trace log message

			myph=readPH(myvalue);
	
			gettimeofday(&tv_now,  &tz_now);
			now = localtime((time_t *)&tv_now.tv_sec);  // only needed for log below
	
			fcLogx(__FILE__, fn,
			       globalMask,
			       PICOMGR_MISC,
			       "ph=%d at %02d%02d%02d.%03d",
			       myph,
			       now->tm_hour,
			       now->tm_min,
			       now->tm_sec,
			       (int)tv_now.tv_usec /1000  // covert to msec
			       );
	
			fcLogx(__FILE__, fn,
			       globalMask,
			       PICOMGR_MISC,
			       "myID=%d set_value=%d",
			       myID, myvalue);
	
                        outMsg=(PICO_PH_MSG *)outArea;
			outMsg->token=PICO_PH;
			outMsg->ph=myph;
			outMsg->mystamp.tv_sec=tv_now.tv_sec;
			outMsg->mystamp.tv_usec=tv_now.tv_usec;;
	
			Reply(fromWhom, outArea, sizeof(PICO_PH_MSG));
	
                    } else
                    {
                        PICO_STOP_MSG *outMsg;
    
                        outMsg=(PICO_STOP_MSG *)outArea;
                        outMsg->token=PICO_READING_STOP;
                            
                        fcLogx(__FILE__, fn,
                                globalMask,
                                PICOMGR_MISC,
                                "STOP Measurements token=%d", outMsg->token);
                            
                        Reply(fromWhom,  outArea,   sizeof (PICO_STOP_MSG));
                    }
                }
		break;

		case PICO_TEMPERATURE:
                {
                    int myvalue;
	
                    PICO_DO_READING_MSG *inMsg;
                                
                    inMsg=(PICO_DO_READING_MSG *)inArea;                    
                    myID=inMsg->ID;
                    myvalue=inMsg->set_value; 

		    if (routingTable[myID].stopFlag == 0) 
		      {

			PICO_TEMPERATURE_MSG *outMsg;
	
			int mytemp;
			struct timeval	tv_now;
			struct timezone tz_now;   // only needed to complete gettimeofday()
			struct tm *now;   // only needed for trace log message

			mytemp=readTemperature(myvalue);
	
			gettimeofday(&tv_now,  &tz_now);
			now = localtime((time_t *)&tv_now.tv_sec);  // only needed for log below
	
			fcLogx(__FILE__, fn,
                               globalMask,
                               PICOMGR_MISC,
                               "sizeof(PICO_TEMPERATURE_MSG)=%d sizeof(struct timeval)=%d tv_now.tv_sec=%d tv_now.tv_usec=%d mytemp=%d)",
                               sizeof(PICO_TEMPERATURE_MSG),
			       sizeof(struct timeval),
                               tv_now.tv_sec,
			       tv_now.tv_usec,
                               mytemp);

			fcLogx(__FILE__, fn,
			       globalMask,
			       PICOMGR_MISC,
			       "myID=%d set_value=%d",
			       myID,
			       myID, myvalue);
			
			outMsg=(PICO_TEMPERATURE_MSG *)outArea;
			outMsg->token=PICO_TEMPERATURE;
			outMsg->ID=myID;
			outMsg->mystamp.tv_sec=tv_now.tv_sec;
			outMsg->mystamp.tv_usec=tv_now.tv_usec;
			outMsg->temperature=mytemp;;

            fcLogx(__FILE__, fn,
			       globalMask,
			       PICOMGR_MISC,
			       "DUMPHEX_0-7 0x%02x-%02x-%02x-%02x-%02x-%02x-%02x-%02x\n",
			       outArea[0],
			       outArea[1],
			       outArea[2],
			       outArea[3],
			       outArea[4],
			       outArea[5],
			       outArea[6],
			       outArea[7]);

            fcLogx(__FILE__, fn,
			       globalMask,
			       PICOMGR_MISC,
			       "DUMPHEX_8-15 0x%02x-%02x-%02x-%02x-%02x-%02x-%02x-%02x\n",
			       outArea[8],
			       outArea[9],
			       outArea[10],
			       outArea[11],
			       outArea[12],
			       outArea[13],
			       outArea[14],
			       outArea[15]);

			fcLogx(__FILE__, fn,
			       globalMask,
			       PICOMGR_MISC,
			       "temperature=%d.%d at %02d%02d%02d.%03d",
			       mytemp/10,
			       mytemp%10,
			       now->tm_hour,
			       now->tm_min,
			       now->tm_sec,
			       (int)tv_now.tv_usec /1000  // covert to msec
			       );
	
			Reply(fromWhom, outArea, sizeof(PICO_TEMPERATURE_MSG));
	
		      } else
			{
			  PICO_STOP_MSG *outMsg;
	
			  outMsg=(PICO_STOP_MSG *)outArea;
			  outMsg->token=PICO_READING_STOP;
				
			  fcLogx(__FILE__, fn,
				 globalMask,
				 PICOMGR_MISC,
				 "STOP Measurements token=%d", outMsg->token);
				
			  Reply(fromWhom,  outArea,   sizeof (PICO_STOP_MSG));
			}
		  }
		break;

		case PICO_LIGHT:
                {
                    int myvalue;
	
                    PICO_DO_READING_MSG *inMsg;
                                            
                    inMsg=(PICO_DO_READING_MSG *)inArea;                    
                    myID=inMsg->ID;
                    myvalue=inMsg->set_value; 

		    if (routingTable[myID].stopFlag == 0) 
                    {

			PICO_LIGHT_MSG *outMsg;
	
			int mylight;
   
			struct timeval	tv_now;
			struct timezone tz_now;   // only needed to complete gettimeofday()
			struct tm *now;   // only needed for trace log message

			mylight=readLight(myvalue);
	
			gettimeofday(&tv_now,  &tz_now);
			now = localtime((time_t *)&tv_now.tv_sec);  // only needed for log below
	
			fcLogx(__FILE__, fn,
			       globalMask,
			       PICOMGR_MISC,
			       "light=%d.%d at %02d%02d%02d.%03d",
			       mylight/10,
			       mylight%10,
			       now->tm_hour,
			       now->tm_min,
			       now->tm_sec,
			       (int)tv_now.tv_usec /1000  // covert to msec
			       );
	
			fcLogx(__FILE__, fn,
			       globalMask,
			       PICOMGR_MISC,
			       "myID=%d set_value=%d",
			       myID,
			       myID, myvalue);
	
			outMsg=(PICO_LIGHT_MSG *)outArea;
			outMsg->token=PICO_LIGHT;
			outMsg->light=mylight;
			outMsg->mystamp.tv_sec=tv_now.tv_sec;
			outMsg->mystamp.tv_usec=tv_now.tv_usec;;
	
			Reply(fromWhom, outArea, sizeof(PICO_LIGHT_MSG));
	
                    } else
                    {
			  PICO_STOP_MSG *outMsg;
	
			  outMsg=(PICO_STOP_MSG *)outArea;
			  outMsg->token=PICO_READING_STOP;
				
			  fcLogx(__FILE__, fn,
				 globalMask,
				 PICOMGR_MISC,
				 "STOP Measurements token=%d", outMsg->token);
				
			  Reply(fromWhom,  outArea,   sizeof (PICO_STOP_MSG));
                    }
                }
		break;

		case PICO_READING_STOP:
		{
      
                    PICO_STOP_MSG *inMsg;
                
                    inMsg=(PICO_STOP_MSG *)inArea;
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

		case PICO_ANGLE:
                {
                    PICO_DO_READING_MSG *inMsg;

                    int myvalue;
		    int mysensor;
                    
                    inMsg=(PICO_DO_READING_MSG *)inArea;                    
                    myID=inMsg->ID;
		    mysensor=(inMsg->sensor)-1;
                    myvalue=inMsg->set_value; 

		    if (routingTable[myID].stopFlag == 0) 
                    {

			PICO_ANGLE_MSG *outMsg;
	
			float myangle;
	
			struct timeval	tv_now;
			struct timezone tz_now;   // only needed to complete gettimeofday()
			struct tm *now;   	  // only needed for trace log message

			myangle=readAngle(myvalue, mysensor);
	
			gettimeofday(&tv_now,  &tz_now);
			now = localtime((time_t *)&tv_now.tv_sec);  // only needed for log below
	
			fcLogx(__FILE__, fn,
			       globalMask,
			       PICOMGR_MISC,
			       "ID=%d angle=%f sensor=%d set_value=%d at %02d%02d%02d.%03d",
			       myID,
			       myangle,
			       mysensor,
			       myvalue,
			       now->tm_hour,
			       now->tm_min,
			       now->tm_sec,
			       (int)tv_now.tv_usec /1000  // covert to msec
			       );
	
                        outMsg=(PICO_ANGLE_MSG *)outArea;
			outMsg->token=PICO_ANGLE;
			outMsg->angle=myangle;
			outMsg->mystamp.tv_sec=tv_now.tv_sec;
			outMsg->mystamp.tv_usec=tv_now.tv_usec;;
	
			Reply(fromWhom, outArea, sizeof(PICO_ANGLE_MSG));
	
                    } else
                    {
                        PICO_STOP_MSG *outMsg;
    
                        outMsg=(PICO_STOP_MSG *)outArea;
                        outMsg->token=PICO_READING_STOP;
                            
                        fcLogx(__FILE__, fn,
                                globalMask,
                                PICOMGR_MISC,
                                "STOP Measurements token=%d", outMsg->token);
                            
                        Reply(fromWhom,  outArea,   sizeof (PICO_STOP_MSG));
                    }
                }
		break;

		case PICO_ANGLE_CALIBRATE:
		{
			PICO_ANGLE_CALIBRATE_MSG *inMsg;
			
			inMsg=(PICO_ANGLE_CALIBRATE_MSG *)inArea;                    
			
			int myID;
			float myangle;
			int myvalue;
	
			myID=inMsg->ID;
			myangle=inMsg->angle;
			myvalue=inMsg->set_value; 
			
			int myvoltage;

			myvoltage=readVoltage(myvalue);
	
			calibrationArray[inMsg->index][inMsg->sensor].angle=myangle;
			calibrationArray[inMsg->index][inMsg->sensor].voltage=myvoltage;
			
			fcLogx(__FILE__, fn,
				globalMask,
				PICOMGR_MISC,
				"ID=%d index=%d angle=%f sensor=%d set_value=%d voltage=%d",
				inMsg->ID,
				inMsg->index,
				calibrationArray[inMsg->index][inMsg->sensor].angle,
				inMsg->sensor,
				inMsg->set_value,
				calibrationArray[inMsg->index][inMsg->sensor].voltage
				);
	

			Reply(fromWhom, outArea, sizeof(PICO_ANGLE_CALIBRATE_MSG));
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
