/*************************************************************
FILE:	relayStimProto.h	

DESCRIPTION:	
This file contains prototypes for relayStim app.

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
$Log: relayStimProto.h,v $
Revision 1.2  2002/12/03 21:19:20  root
v2.0 compatible

Revision 1.1  2002/12/03 19:52:39  root
Initial revision

=======================================================

*************************************************************/
#ifndef _RELAY_STIM_PROTO_DEF
#define _RELAY_STIM_PROTO_DEF

void initialize(int, char **);
void myUsage();
void hndlReply(char *);

#endif
