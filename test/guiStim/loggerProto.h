/*************************************************************
	loggerProto.h

DESCRIPTION:	
This file contains prototypes of some trace logger functions.

AUTHOR:			R.D. Findlay

-----------------------------------------------------------------------
    Copyright (C) 1998, 2002 FCSoftware Inc. 

    This software is in the public domain.
    Permission to use, copy, modify, and distribute this software and its
    documentation for any purpose and without fee is hereby granted, 
    without any conditions or restrictions.
    This software is provided "as is" without express or implied warranty.

    If you discover a bug or add an enhancement contact us on the
    SIMPL project mailing list. 

-----------------------------------------------------------------------

Revision history:
=======================================================
    $Log: loggerProto.h,v $
    Revision 1.2  2009/01/13 20:57:23  bobfcsoft
    C++ hooks

    Revision 1.1  2009/01/08 16:18:44  bobfcsoft
    relocated

    Revision 1.2  2007/07/24 20:18:45  bobfcsoft
    new contact info

    Revision 1.1.1.1  2005/03/27 11:50:35  paul_c
    Initial import

    Revision 1.6  2002/11/22 16:20:44  root
    2.0rc3

    Revision 1.5  2002/11/22 15:08:38  root
    2.0rc2

    Revision 1.4  2002/06/12 18:13:51  root
    fcipc merge completed

    Revision 1.3  2000/10/04 01:45:34  root
    LGPL'd

    Revision 1.2  1999/09/09 15:57:33  root
    new x API
    this new API will eventually roll back to existing API

    Revision 1.1  1999/04/08 14:20:22  root
    Initial revision

=======================================================

*************************************************************/
#ifndef _LOGGER_PROTO_DEF
#define _LOGGER_PROTO_DEF

#include "simpl.h"

#ifdef __cplusplus
extern "C"
{
#endif

int is_logger_upx(char *);
int logMsgx(char *, char *, char*);
int fcLogx( char *, char *, unsigned int, unsigned int, char *, ...);

#ifdef __cplusplus
}
#endif

#endif
