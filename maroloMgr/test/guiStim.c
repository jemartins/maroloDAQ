#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "drdaqMsgs.h"

#define _ALLOC
#include "guiStim.h"
#undef _ALLOC

#include "guiStimProto.h"
#include "simplProto.h"
#include "loggerProto.h"

int myID;

/*--------------------------------------
	guiStim - entry point
--------------------------------------*/
int main(int argc, char **argv)
{
static char *fn="guiStim";
int x_it=0;

char line[80];
char *p;

initialize(argc, argv);

fcLogx(__FILE__, fn,
	globalMask,
	GUI_STIM_MARK,
	"starting myID=%d",
        myID
	);

printf("-> ");
fflush(stdout);
while(!x_it)
	{
	inset = watchset;
	select(maxfd+1, &inset, NULL, NULL, NULL);

	if(FD_ISSET(my_fds[0], &inset))  //  keyboard is ready
		{
		fgets(line,80,stdin);

		switch(line[0])
			{
			case '?':
				printf("guiStim commands:\n");
				printf("s <period> <maxReadings> - start readings\n");
				printf("c <ID> <index> <angle> <sensor> <set_value>\n");
				printf("h - stop readings\n");
				printf("q - quit\n");
				break;

			case 's':
				{
				PICO_START_MSG *outMsg;
		
				outMsg=(PICO_START_MSG *)outArea;
				outMsg->token=PICO_READING_START;
                                outMsg->ID=0;
				outMsg->TMax=0;

				p=skipOverWhiteSpace(line); // start of period
				outMsg->period=atoi(p);
				
				p=skipOverWhiteSpace(p); // start of maxReadings
				outMsg->maxReadings=atoi(p);


				outMsg->nsensors=1;
				outMsg->sensor[0].n_modo=8;
				outMsg->sensor[0].set_value=5;
				outMsg->sensor[1].n_modo=8;
				outMsg->sensor[1].set_value=5;
				outMsg->n_passo=1;
				outMsg->AutoEscala=1;
				outMsg->xmax=0;
				outMsg->ymax=0;
				outMsg->ymin=0;
				outMsg->maior_divx=0;
				outMsg->menor_divx=0;
				outMsg->maior_divy=0;
				outMsg->menor_divy=0;

				Send(picoMgrID, 
					outArea, 
					NULL, 
					sizeof(PICO_START_MSG), 
					0);
				}
				break;

			case 'c':
				{
				PICO_ANGLE_CALIBRATE_MSG *outMsg;
		
				outMsg=(PICO_ANGLE_CALIBRATE_MSG *)outArea;
				outMsg->token=PICO_ANGLE_CALIBRATE;
				
				p=skipOverWhiteSpace(line); 
				outMsg->ID=atoi(p); // ID

				p=skipOverWhiteSpace(p); // index
				outMsg->index=atoi(p);

				p=skipOverWhiteSpace(p); // angle
				outMsg->angle=atoi(p);

				p=skipOverWhiteSpace(p); // sensor
				outMsg->sensor=atoi(p);

				p=skipOverWhiteSpace(p); // set_value
				outMsg->set_value=atoi(p);

				printf("ID=%d, index=%d, angle=%d, sensor=%d, set_value=%d\n", 
					outMsg->ID,
					outMsg->index,
					outMsg->angle,
					outMsg->sensor,
					outMsg->set_value);
				
				Send(picoMgrID, 
					outArea, 
					NULL, 
					sizeof(PICO_ANGLE_CALIBRATE_MSG), 
					0);
				}
				break;

                                case 'h':
                                {
                                    PICO_STOP_MSG *outMsg;
                                            
                                    outMsg=(PICO_STOP_MSG *)outArea;
                                    outMsg->token=PICO_READING_STOP;
                            
                                    Send(picoMgrID, 
                                            outArea, 
                                            NULL, 
                                            sizeof(PICO_STOP_MSG), 
                                            0);
                            
                                }
                                break;
       			case 'q':
				x_it=1;
				break;

			default:
				printf("%s: unknown keypress <%c>\n",
					fn,
					line[0]);
				break;
			} // end switch

		printf("-> ");
		fflush(stdout);
		} // end if keyboard

	} // end while

printf("end game\n");

fcLogx(__FILE__, fn,
	globalMask,
	GUI_STIM_MISC,
	"done");

name_detach();

exit(1);
}// end guiStim
