/*************************************************************
FILE:	stimulatorMsgs.h	

DESCRIPTION:	
This file contains globals for stimulator SIMPL software IC. 

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
$Log: stimulatorMsgs.h,v $
Revision 1.1  2008/04/28 17:58:06  bobfcsoft
new in CVS

Revision 1.2  2002/12/03 21:23:24  root
v2.0 compatible

Revision 1.1  2002/12/03 20:22:24  root
Initial revision

=======================================================

*************************************************************/

#ifndef _STIMULATOR_MSGS_DEF
#define _STIMULATOR_MSGS_DEF

#include "standardTypes.h"

typedef enum
	{
	STIM_TEST=0xa000,
	MAX_STIMULATOR_TOKENS
	}STIMULATOR_TOKEN;

typedef struct
	{
	UINT16 token; 	//STIM_TEST
	char str[80];
	}STIM_TEST_MSG;

#endif
