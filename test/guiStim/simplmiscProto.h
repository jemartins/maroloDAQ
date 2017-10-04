/*===================================================
	simplmiscProto.h

Description:
This file contains the of prototypes for
atoh and other functions.

-----------------------------------------------------------------------
    Copyright (C) 2001, 2007 FCSoftware Inc. 

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
===================================================*/
/*
 *$Log: simplmiscProto.h,v $
 *Revision 1.1  2009/01/08 16:21:40  bobfcsoft
 *relocated
 *
 *Revision 1.2  2007/07/24 20:18:45  bobfcsoft
 *new contact info
 *
 *Revision 1.1.1.1  2005/03/27 11:50:37  paul_c
 *Initial import
 *
 *Revision 1.3  2003/04/23 20:42:53  root
 *added bto function prototypes
 *
 *Revision 1.2  2001/07/05 14:38:46  root
 *added cksum function prototype
 *
 *Revision 1.1  2001/01/29 15:08:48  root
 *Initial revision
 *
 */
#ifndef _SIMPLMISC_PROTO
#define _SIMPLMISC_PROTO

#ifdef __cplusplus
extern "C"
{
#endif

long atoh(char *);
long power(int base, int n);
void ato2h(char *pcHexStr, long *twoLongArray);
unsigned long cksum(char *);

void btosUI(unsigned int number, char *str, int clip);
void btosSI(signed int number, char *str, int clip);
void btosUSI(unsigned short int number, char *str, int clip);
void btosSSI(signed short int number, char *str, int clip);
void btosF(float number, char *str, int clip);
void btos4(unsigned int *ptr, char *str, int clip);
void btos2(unsigned short int *ptr, char *str, int clip);
unsigned int stobUI(char *str, int clip);
signed int stobSI(char *str, int clip);
unsigned short int stobUSI(char *str, int clip);
signed short int stobSSI(char *str, int clip);
float stobF(char *str, int clip);
void stob4(unsigned int *ptr, char *str, int clip);
void stob2(unsigned short int *ptr, char *str, int clip);

#ifdef __cplusplus
}
#endif

#endif
