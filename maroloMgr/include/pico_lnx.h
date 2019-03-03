/****************************************************************************
 *
 * Project:      Linux parallel port driver
 *
 * Copyright 2001 - 2004 Pico Technology Limited
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 *
 *
 * Revision Info: "file %n date %f revision %v" *
 *                "file pico_lnx.h date 11-Feb-95,17:40:10 revision 1"
 *
 *   M K Green   email: mike.green@picotech.com
 *               http: www.picotech.com
 *
 *                "file pico_lnx.h date 06-Sep-04 revision 2"
 *   Thanks to J R Hunt, added support for kernel 2.6
 *
 *   J R Hunt    email: jrhunt at iee dot org
 *               http:  www.yoredale.uklinux.net
 *
 ****************************************************************************
 *
 * Module:       pico_lnx.h
 *
 * Description:
 * This header file links an application to the Pico installable
 * kernel mode driver.
 *
 ****************************************************************************/
#ifndef _PICO_LNX
#define _PICO_LNX

/*
 * The major device number. Choose something not used on your system.
 * According to /usr/src/linux/Documentation/devices.txt, the range
 * 240-254 is free for LOCAL/EXPERIMENTAL USE.
 */
#define MAJOR_NUM 242

// Device file name, gets port number 0, 1, or 2 appended
#define DEVICE_FILE_NAME "/dev/picopar"

// the driver name
#define DRIVER_NAME "picopar"

#define PICO_ID	'P'

#define IOCTL_PICO_GET_VERSION 		_IOR( PICO_ID, 1, int )

#define IOCTL_PICO_READ_PORT 		_IOWR( PICO_ID, 10, int )
#define IOCTL_PICO_WRITE_PORT 		_IOWR( PICO_ID, 11, int )

#define IOCTL_PICO_SET_PRODUCT		_IOWR( PICO_ID, 20, int )
#define IOCTL_PICO_SET_HW_VERSION	_IOWR( PICO_ID, 21, int )
#define IOCTL_PICO_SET_DIGITAL_OUT 	_IOWR( PICO_ID, 22, int )
#define IOCTL_PICO_SET_RANGE	 	_IOWR( PICO_ID, 23, int )
#define IOCTL_PICO_SET_READ_MODE 	_IOWR( PICO_ID, 24, int )
#define IOCTL_PICO_GET_VALUE	 	_IOWR( PICO_ID, 25, int )
#define IOCTL_PICO_SET_SCALE	 	_IOWR( PICO_ID, 26, int )
#define IOCTL_PICO_GET_HW_VERSION	_IOWR( PICO_ID, 27, int )

/* Read mode:
 *      Passed to IOCTL_SET_READ_MODE
 *
 *	On each conversion, the ADC returns the value of the previous conversion.
 *	If READ_MODE_SINGLE is used, the returned value is the value for the previous call.
 *	This may be acceptable when reading at high speed, but could cause problems
 *	if you take (say) one reading per second.
 *
 *	If READ_MODE_DOUBLE is used, each call takes twice as long, butthe
 *      returned value is the value for the first of the two conversions- ie
 *      it is a current reading, rather than one from the previous call.
 */

#define READ_MODE_SINGLE		0
#define READ_MODE_DOUBLE		1

/* Product codes...
 * 	Passed to IOCTL_PICO_SET_PRODUCT
 *
 *  	You can probably guess all of them except DrDAQ
 */
#define PRODUCT_ADC10		10
#define PRODUCT_ADC11		11
#define PRODUCT_ADC12		12
#define PRODUCT_ADC22		22
#define PRODUCT_ADC40		40
#define PRODUCT_ADC42		42
#define PRODUCT_DRDAQ		67
#define PRODUCT_ADC100		100
#define PRODUCT_ADC101		101


/* Bit patterns for digital outputs
 * 	Passed to IOCTL_PICO_SET_DIGITAL_OUT
 */
#define DRDAQ_DIGITAL_OUTPUT	0x01
#define DRDAQ_LED		0x02

#define ADC11_DIGITAL_OUTPUT1	0x01
#define ADC11_DIGITAL_OUTPUT2	0x02

/* Channel numbers for ADC00 requests
 */
#define ADC100_CHANNEL_A	0
#define ADC100_CHANNEL_B	1

/* Rangesfor ADC100
 *  passed to IOCTL_PICO_SET_RANGE
 *
 * Note that the ADC101 ranges are 5x those indicated
 *  ie ADC100_RANGE_1V selects 5V on the ADC101
 */

#define ADC100_RANGE_50MV	0
#define ADC100_RANGE_100MV	1
#define ADC100_RANGE_200MV	2
#define ADC100_RANGE_500MV	3
#define ADC100_RANGE_1V		4
#define ADC100_RANGE_2V		5
#define ADC100_RANGE_5V		6
#define ADC100_RANGE_10V	7
#define ADC100_RANGE_20V	8

/* Scaling enable
 *   Passed to IOCTL_PICO_SET_SCALE
 */
#define SCALE_ADC	0
#define SCALE_MV	1   /* Or sensor units (eg degC) for DrDAQ */      

#endif //_PICO_LNX
