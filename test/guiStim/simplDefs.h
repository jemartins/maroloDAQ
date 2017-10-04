/*======================================================================

FILE:			simplDefs.h

DESCRIPTION:	This file contains definitions used by the simpl source
				code library functions.

AUTHOR:			FC Software Inc.

-----------------------------------------------------------------------
    Copyright (C) 2000, 2005, 2007 FCSoftware Inc. 

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
$Log: simplDefs.h,v $
Revision 1.9  2012/10/30 20:05:24  bobfcsoft
added shmsize to SIMPL header

Revision 1.8  2011/03/23 17:04:40  bobfcsoft
added PROXY_CLONE for remote name attach

Revision 1.7  2010/04/16 11:57:48  bobfcsoft
created SIMPL_NAME_DELIMITER define

Revision 1.6  2010/02/09 21:51:58  bobfcsoft
rename to simpl.log

Revision 1.5  2009/01/20 15:03:10  bobfcsoft
added DEFAULT_FIFO_PATH

Revision 1.4  2009/01/16 21:37:58  bobfcsoft
added MAX_FIFO_PATH_LEN

Revision 1.3  2009/01/13 20:48:09  johnfcsoft
added RECEIVE/REPLY/REMOVE/NO_REMOVE defs

Revision 1.2  2009/01/09 20:49:13  johnfcsoft
included unistd.h for pid_t

Revision 1.1  2009/01/08 16:14:11  bobfcsoft
relocated

Revision 1.7  2008/12/23 17:06:14  bobfcsoft
added SIMPL_NAME_SIZE

Revision 1.6  2007/07/24 20:18:45  bobfcsoft
new contact info

Revision 1.5  2006/01/10 15:28:45  bobfcsoft
v3.0 changes

Revision 1.4  2005/12/20 15:22:07  bobfcsoft
more 3.0 prerelease changes

Revision 1.3  2005/11/12 12:15:34  bobfcsoft
PROXY_SHUTDOWN -> 7fffffff

Revision 1.2  2005/09/29 00:51:24  bobfcsoft
added proxy shutdown

Revision 1.1.1.1  2005/03/27 11:50:37  paul_c
Initial import

Revision 1.3  2003/04/14 13:20:21  root
fixed spelling error

Revision 1.2  2002/11/22 16:22:25  root
2.0rc3


====================================================================
======================================================================*/

/*
NOTE
----

The values of MAX_PROTOCOL_NAME_LEN, MAX_HOST_NAME_LEN and
MAX_PROGRAM_NAME_LEN have been purposefully set to the values
below. These values plus 1 are evenly divisible by 4. The gcc
compiler seems to like to pad out each structure value if it is
a character variable to a double word boundary. In operating systems
other than Linux, this may not occur and consequently structure
sizes will vary. For example:

typedef struct 
	{
	int i;
	int j;
	char k[2];
	} TEST0;

In Linux, sizeof(TEST0) will return 12 bytes. In QNX, sizeof(TEST0)
will return 10 bytes. Linux has padded out the string k to 4 bytes.

Another example:

typedef struct 
	{
	int i;
	int j;
	char k;
	} TEST1;

In Linux, sizeof(TEST1) will return 12 bytes. In QNX, sizeof(TEST1)
will return 9 bytes. Linux has added another 3 bytes to the structure.

For compatibility, one could adjust each of the above in the following
way:

typedef struct 
	{
	int i;
	int j;
	char k[4];
	} TEST0;

typedef struct 
	{
	int i;
	int j;
	char k;
	char l;
	char m;
	char n;
	} TEST1;

In TEST1, l, m and n are superfluous but the sizes will match.

Why is this a concern? On a single computer, so long as there internal
consistency there is no problem. On a network of computers running the
same o/s, again there is no problem. However, suppose that you have
a Linux computer using SIMPL messaging to talk to a QNX computer. The
message headers that describe details of the communication will be
perceived differently and herein lies the rub.
*/

#ifndef _SIMPL_DEFS_H
#define _SIMPL_DEFS_H

#include <unistd.h>

// defines
#define MAX_PROTOCOL_NAME_LEN		23	
#define MAX_HOST_NAME_LEN			51
#define MAX_NUM_PROTOCOLS			10
#define MAX_PROGRAM_NAME_LEN		31
#define	MAX_NUM_REMOTE_RECEIVERS	40
#define	MAX_NUM_BLOCKED_SENDERS		40
#define MAX_SIMPL_LOG_SIZE			102400 // 100 kbytes	
#define SIMPL_LOG_FILE				"/var/tmp/simpl.log"	
#define PROXY_SHUTDOWN				0x7FFFFFFF	
#define PROXY_CLONE				0x7FFFFFFE	
#define	RECEIVE						0
#define REPLY						1
#define	REMOVE						1
#define NO_REMOVE					0
#define DEFAULT_FIFO_PATH		"/var/tmp"
#define MAX_FIFO_PATH_LEN		127
#define SIMPL_NAME_SIZE			MAX_PROGRAM_NAME_LEN + 1
#define SIMPL_NAME_DELIMITER		':'

typedef struct
	{
	char whom[MAX_PROGRAM_NAME_LEN + 1];
	pid_t pid;
	int fd;
	int y_fd;
	int shmid;
	char *shmPtr;
	unsigned shmSize;
	void (*myExit)();
	} WHO_AM_I;

// must be kept atomic
typedef struct
	{
	int shmid;
	} FIFO_MSG;

typedef struct
	{
	char whom[MAX_PROGRAM_NAME_LEN + 1];
	pid_t pid;
	int shmsize;
	int nbytes;
	int ybytes;
	char data;
	} FCMSG_REC;

typedef struct
	{
	char whom[MAX_PROGRAM_NAME_LEN + 1];
	pid_t pid;
	} SIMPL_REC;

typedef struct
	{
	char protocolName[MAX_PROTOCOL_NAME_LEN + 1];
	char programName[MAX_PROGRAM_NAME_LEN + 1];
	char *sender;
	} PROTOCOL_TABLE_ENTRY;

#endif
