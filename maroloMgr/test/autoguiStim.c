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

PICO_START_MSG *outMsg;

outMsg=(PICO_START_MSG *)outArea;
outMsg->token=PICO_READING_START;
outMsg->ID=myID;
outMsg->sensor[0].set_value=11;

p=skipOverWhiteSpace(line); // start of period
outMsg->period=atoi(p);

p=skipOverWhiteSpace(p); // start of maxReadings
outMsg->maxReadings=atoi(p);

Send(picoMgrID, 
        outArea, 
        NULL, 
        sizeof(PICO_START_MSG), 
        0);
        
printf("end game\n");

fcLogx(__FILE__, fn,
	globalMask,
	GUI_STIM_MISC,
	"done");

name_detach();

exit(1);
}// end guiStim
