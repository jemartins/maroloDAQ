/*************************************************************

FILE:		relayStimUtils.c

DESCRIPTION:	
This file contains utility code for relayStim app.

AUTHOR:			R.D. Findlay

-----------------------------------------------------------------------
    Copyright (C) 2000, 2002 FCSoftware Inc. 

    This software is in the public domain.
    Permission to use, copy, modify, and distribute this software and its
    documentation for any purpose and without fee is hereby granted, 
    without any conditions or restrictions.
    This software is provided "as is" without express or implied warranty.

    If you discover a bug or add an enhancement here's how to reach us: 

	fcsoft@attcanada.ca
-----------------------------------------------------------------------
Revision history:
=======================================================
$Log: relayStimUtils.c,v $
Revision 1.2  2002/12/03 21:21:01  root
v2.0 compatible

Revision 1.1  2002/12/03 19:54:35  root
Initial revision

=======================================================

*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "relayMsgs.h"

#define _ALLOC extern
#include "relayStim.h"
#undef _ALLOC

#include "relayStimProto.h"
#include "simplProto.h"
#include "loggerProto.h"
#include "simplmiscProto.h"

/*====================================================
	hndlReply - entry point
====================================================*/
void hndlReply(char *msgArea)
{
static char *fn="hndlReply";
UINT16 *token;

token = (UINT16 *)msgArea;

switch(*token)
	{
	case RELAY_TEST:
		{
		RELAY_TEST_MSG *inMsg;

		inMsg=(RELAY_TEST_MSG *)inArea;

		fcLogx(__FILE__, fn,
			globalMask,
			RELAY_STIM_MISC,
			"TEST reply str=<%s>",
			inMsg->str
			);

printf("%s:TEST reply str=<%s>\n",
	fn,
	inMsg->str
	);
			
		}
		break;

	default:
		printf("%s:unknown token=%d\n",fn,*token);
		break;
	}
} // end hndlReply
