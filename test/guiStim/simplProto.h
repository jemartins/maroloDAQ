/*======================================================================

FILE:			simplProto.h

DESCRIPTION:	This file contains the function protoype definitions
				contained in the simpl library. 

AUTHOR:			FC Software Inc.

-----------------------------------------------------------------------
    Copyright (C) 2002, 2007 FCSoftware Inc. 

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    If you discover a bug or add an enhancement contact us on the
    SIMPL project mailing list.

-----------------------------------------------------------------------

Revision history:
====================================================================
$Log: simplProto.h,v $
Revision 1.5  2010/04/16 11:53:19  bobfcsoft
whatsMyShmPtr and whatsThisShmPtr name changes

Revision 1.4  2009/08/19 14:36:39  bobfcsoft
added whatsMyRecvPtr and whatsMyReplyPtr

Revision 1.3  2009/03/16 15:49:11  johnfcsoft
prototype repair

Revision 1.2  2009/01/12 16:09:15  bobfcsoft
removed inline from prototype

Revision 1.1  2009/01/08 16:14:11  bobfcsoft
relocated

Revision 1.5  2007/07/24 20:18:45  bobfcsoft
new contact info

Revision 1.4  2006/07/11 14:48:02  bobfcsoft
added Relay

Revision 1.3  2005/12/20 15:22:07  bobfcsoft
more 3.0 prerelease changes

Revision 1.2  2005/09/26 15:46:12  bobfcsoft
proxy/trigger changes

Revision 1.1.1.1  2005/03/27 11:50:35  paul_c
Initial import

Revision 1.5  2002/11/22 16:22:03  root
2.0rc3


====================================================================
======================================================================*/

#ifndef _SIMPL_PROTO_H
#define _SIMPL_PROTO_H

#include "simplDefs.h"    // needed for SIMPL_REC below

#ifdef __cplusplus
extern "C"
{
#endif

// function prototypes in simpl.c
int name_attach(const char *, void (*myExit)());
int name_detach(void);
int child_detach(void);
int name_locate(const char *);
int sur_detach(int);
int Receive(char **, void *, unsigned);
int Send(int, void *, void *, unsigned, unsigned);
int Trigger(int, int);
int Reply(char *, void *, unsigned);
int Relay(char *, int);
char *whatsMyName(void);
int whatsMyRecvfd(void);
int whatsMyReplyfd(void);
char *whatsMyError(void);
char *whatsThisShmPtr(char *);
char *whatsMyShmPtr(void);
void simplRcopy(char *, void *, unsigned);
void simplScopy(void *, unsigned);
int simplReplySize(char *);
int returnProxy(int);

int simplSetReceiverParms(char *name, SIMPL_REC *rec);
void simplSetSenderParms(char *sender, SIMPL_REC *rec);
int simplCheckProcess(SIMPL_REC *rec);

#ifdef __cplusplus
}
#endif

#endif
