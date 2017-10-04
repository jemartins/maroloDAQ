/*************************************************************
FILE:	receiverMsgs.h	

DESCRIPTION:	
This file contains globals for receiver app. 

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
$Log: receiverMsgs.h,v $
Revision 1.1  2008/04/28 17:58:05  bobfcsoft
new in CVS

Revision 1.2  2002/12/03 21:22:20  root
v2.0 compatible

Revision 1.1  2002/12/03 20:21:48  root
Initial revision

=======================================================

*************************************************************/

#ifndef _RECEIVER_MSGS_DEF
#define _RECEIVER_MSGS_DEF

#include "standardTypes.h"

typedef enum
	{
	RECV_TEST,
	MAX_RECEIVER_TOKENS
	}RECEIVER_TOKEN;

typedef struct
	{
	UINT16 token; 	//RECV_TEST
	char str[80];
	}RECV_TEST_MSG;

#endif
