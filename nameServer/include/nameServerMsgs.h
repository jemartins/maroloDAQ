/*=====================================================
    nameServerMsgs.h

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
$Log: nameServerMsgs.h,v $
Revision 1.3  2006/07/07 22:16:50  jemartins
removed comented lines

Revision 1.2  2006/07/07 19:52:46  bobfcsoft
bobs changes

Revision 1.1  2006/07/06 14:31:52  bobfcsoft
seed code

=======================================================

=====================================================*/

#ifndef _NAMESERVER_MSGS_DEF
#define _NAMESERVER_MSGS_DEF

#include "standardTypes.h"

/*=======================================
	 message tokens
=======================================*/
typedef enum
	{
	REQUEST_NAME,
        FREE_NAME,
        MAX_NAME_TOKENS
	}NAME_TOKEN;

/*============================================
	message templates
============================================*/
	
typedef struct 
	{
	NAME_TOKEN token;	// REQUEST, FREE
	char guiName[20];
	char readerName[20];
	int ID;
	}NAME_SERVER_MSG;

#endif
