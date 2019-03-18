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

/*--------------------------------------
	picoStim - entry point
--------------------------------------*/
int main(int argc, char **argv)
{
static char *fn="picoStim";
int x_it=0;
char line[80];

initialize(argc, argv);

fcLogx(__FILE__, fn,
	globalMask,
	PICO_STIM_MARK,
	"starting"
	);

printf("-> ");
fflush(stdout);
while(!x_it)
	{
	inset = watchset;
	select(maxfd+1, &inset, NULL, NULL, NULL);

// Is this from keyboard
	if(FD_ISSET(my_fds[0], &inset))  //  keyboard is ready
		{
		fgets(line,80,stdin);

		switch(line[0])
			{
			case '?':
				printf("picoStim commands:\n");
				printf("t - temperature\n");
				printf("l - toggle LED\n");
				printf("a - angle \n");
				printf("w - WHAT_YA_GOT\n");
				printf("q - quit\n");
				break;

			case 'l':
				{
				PICO_LED_MSG *outMsg;
		
				outMsg=(PICO_LED_MSG *)outArea;
				outMsg->token=PICO_LED;

				Send(picoMgrID, 
					outArea, 
					NULL, 
					sizeof(PICO_LED_MSG), 
					0);

				}
				break;

			case 't':
				{
				PICO_TEMPERATURE_MSG *outMsg;
				PICO_TEMPERATURE_MSG *inMsg;
		
				outMsg=(PICO_TEMPERATURE_MSG *)outArea;
				outMsg->token=PICO_TEMPERATURE;

				Send(picoMgrID, 
					outArea, 
					inArea, 
					sizeof(PICO_TEMPERATURE_MSG), 
					sizeof(PICO_TEMPERATURE_MSG));

				inMsg=(PICO_TEMPERATURE_MSG *)inArea;

				fcLogx(__FILE__, fn,
					globalMask,
					PICO_STIM_MISC,
					"temperature=%d",
					inMsg->temperature
					);

				printf("temperature %d.%d C\n",
					inMsg->temperature/10,
					inMsg->temperature%10);
				}
				break;

			case 'a':
				{
				PICO_DO_READING_MSG *outMsg;
				PICO_ANGLE_MSG *inMsg;

				outMsg=(PICO_DO_READING_MSG *)outArea;
				outMsg->token=PICO_ANGLE;
				outMsg->ID=0;
				outMsg->sensor=2;
				outMsg->set_value=5;


				inMsg=(PICO_ANGLE_MSG *)inArea;

				Send(picoMgrID, 
					outArea, 
					inArea, 
					sizeof(PICO_DO_READING_MSG), 
					sizeof(PICO_ANGLE_MSG));

				fcLogx(__FILE__, fn,
					globalMask,
					PICO_STIM_MISC,
					"angle=%f",
					inMsg->angle
					);

				printf("angle=%5.2f degree\n",
					inMsg->angle
					);
				};
				break;

			case 'w':
				{
				PICO_WHAT_YA_GOT_MSG *outMsg;
				PICO_START_MSG *inMsg;
		
				printf("blocked pending START\n");
				fflush(stdout);

				outMsg=(PICO_WHAT_YA_GOT_MSG *)outArea;
				outMsg->token=PICO_WHAT_YA_GOT;

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

					printf("here got READING_START\n");
					printf("period=%d msec maxReadings=%d\n",
					inMsg->period,
					inMsg->maxReadings);

					} // end if READING_START

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
	PICO_STIM_MISC,
	"done");

name_detach();

exit(1);
}// end picoStim
