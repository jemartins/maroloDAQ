/*************************************************************
FILE:	relayMsgs.h	

DESCRIPTION:	
This file contains globals for relay SIMPL software IC. 

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
$Log: relayMsgs.h,v $
Revision 1.2  2002/12/03 21:18:41  root
v2.0 compatible

Revision 1.1  2002/12/03 19:52:22  root
Initial revision

=======================================================

*************************************************************/

#ifndef _RELAY_MSGS_DEF
#define _RELAY_MSGS_DEF

#include "standardTypes.h"

typedef enum
	{
	RELAY_REGISTER,
	RELAY_TEST,
	RELAY_ERROR,
	MAX_RELAY_TOKENS
	}RELAY_TOKEN;

typedef struct
	{
	UINT16 token; 	//RELAY_REGISTER
	char myName[20];
	}RELAY_REGISTER_MSG;

typedef struct
	{
	UINT16 token; 	//RELAY_TEST
	char str[80];
	}RELAY_TEST_MSG;

typedef struct
	{
	UINT16 token; 	//RELAY_ERROR
	int code;
	}RELAY_ERROR_MSG;
#endif
