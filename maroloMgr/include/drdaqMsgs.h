/*=====================================================
    drdaqMsgs.c

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
$Log: drdaqMsgs.h,v $
Revision 1.15  2010/02/11 17:28:57  jemartins
added XY feature

Revision 1.14  2007/06/12 18:09:34  jemartins
bugs fixed

Revision 1.13  2007/06/11 18:18:21  jemartins
changes in CALIBRATE struct

Revision 1.12  2007/06/07 00:01:18  jemartins
fix bugs

Revision 1.11  2007/06/06 20:52:12  jemartins
adjusted ANGLE option

Revision 1.10  2007/06/05 20:12:25  juniocruz
Angle adjusted as float

Revision 1.9  2007/06/04 13:35:50  jemartins
added PICO_ANGLE

Revision 1.8  2007/06/02 15:42:40  jemartins
added index in CALIBRATE

Revision 1.7  2007/06/01 17:07:46  jemartins
added #endif

Revision 1.6  2007/06/01 15:18:02  jemartins
added CALIBRATE msgs

Revision 1.5  2006/09/26 13:01:03  jemartins
added ymin var

Revision 1.4  2006/06/22 12:02:02  jemartins
added ID

Revision 1.3  2006/06/01 18:32:32  jemartins
changes in structures

Revision 1.2  2006/06/01 01:23:15  jemartins
added new functions

Revision 1.1  2006/05/27 12:10:32  jemartins
*** empty log message ***


Revision 1.22  2006/05/26 16:34:57  jemartins
*** empty log message ***

Revision 1.21  2006/05/25 19:01:12  jemartins
*** empty log message ***

Revision 1.20  2006/05/25 18:16:03  jemartins
added new token

Revision 1.19  2006/05/24 18:08:35  jemartins
added waveform token

Revision 1.18  2006/05/23 15:08:36  jemartins
added DO_READING_MSG

Revision 1.17  2006/05/19 22:42:08  jemartins
removed syntax error

Revision 1.16  2006/05/19 12:56:23  bobfcsoft
fixed missing comma

Revision 1.15  2006/05/18 18:09:17  jemartins
added new tokens

Revision 1.14  2006/05/18 11:55:43  jemartins
removed double entry

Revision 1.13  2006/05/17 21:29:08  jemartins
removed diffs

Revision 1.12  2006/05/17 21:26:49  jemartins
added Copyright

Revision 1.11  2006/05/17 13:44:35  jemartins
new checkin

Revision 1.10  2006/05/15 18:09:05  jemartins
added Copyright

Revision 1.9  2006/05/13 17:12:57  jemartins
added timestamp

Revision 1.8  2006/05/06 23:34:09  jemartins
changes in TMax

Revision 1.7  2006/05/04 14:03:30  jemartins
added =1

Revision 1.6  2006/05/03 22:15:12  jemartins
changes in DRDAQ_MODE

Revision 1.5  2006/05/03 19:29:53  jemartins
added new typedef

Revision 1.4  2006/04/21 21:55:23  jemartins
add PICO_STOP_MSG token

Revision 1.3  2006/03/21 20:40:29  bobfcsoft
guiStim.tcl added

Revision 1.2  2006/03/20 22:20:31  bobfcsoft
added more tokens

Revision 1.1.1.1  2006/03/07 21:29:38  bobfcsoft
startup
=======================================================

=====================================================*/

#ifndef _PICO_MGR_MSGS_DEF
#define _PICO_MGR_MSGS_DEF

#include <sys/time.h>
#include "standardTypes.h"

/*=======================================
	 wrapper message tokens
=======================================*/
typedef enum
	{
	PICO_WHAT_YA_GOT,
	PICO_SOUND_WAVEFORM,
	PICO_SOUND_LEVEL,
	PICO_VOLTAGE,
	PICO_RESISTANCE,
	PICO_PH,
	PICO_TEMPERATURE,
	PICO_LIGHT,	
	PICO_READING_START,
	PICO_READING_STOP,
	PICO_WHAT_READINGS,
	PICO_LED,
	PICO_ANGLE,
	PICO_ANGLE_CALIBRATE,
	MAX_NUM_PICO_TOKENS
	}PICO_TOKEN;

typedef enum
	{
	DRDAQ_SOUND_WAVEFORM=1,
	DRDAQ_SOUND_LEVEL,
	DRDAQ_VOLTAGE,
	DRDAQ_RESISTANCE,
	DRDAQ_PH,
	DRDAQ_TEMPERATURE,
	DRDAQ_LIGHT,
	DRDAQ_ANGLE,
	MAX_NUM_DRDAQ_MODES
	}DRDAQ_MODE;

/*============================================
	message templates
============================================*/
typedef struct 
	{
	PICO_TOKEN token;	// PICO_WHAT_YA_GOT
	int ID;
	}PICO_WHAT_YA_GOT_MSG;
	
typedef struct 
	{
	PICO_TOKEN  token;
	int ID;
	int set_value;
	int sensor;
	}PICO_DO_READING_MSG;

typedef struct 
	{
	PICO_TOKEN token;	// PICO_SOUND_WAVEFORM
	int ID;
	struct timeval mystamp; // timestamp for reading
	int sound_waveform;	// 
	}PICO_SOUND_WAVEFORM_MSG;
 
typedef struct 
	{
	PICO_TOKEN token;	// PICO_SOUND_LEVEL
	int ID;
	struct timeval mystamp; // timestamp for reading
	int sound_level;	// dB x10
	}PICO_SOUND_LEVEL_MSG;
 
typedef struct 
        {
        PICO_TOKEN token;	// PICO_VOLTAGE
	int ID;
        struct timeval mystamp; // timestamp for reading
        int voltage;    	// mV x10
        }PICO_VOLTAGE_MSG;

typedef struct 
        {
        PICO_TOKEN token;	// PICO_RESISTANCE
	int ID;
        struct timeval mystamp; // timestamp for reading
        int resistance; 	// Ohm x10
        }PICO_RESISTANCE_MSG;

typedef struct 
        {
        PICO_TOKEN token;	// PICO_PH
	int ID;
        struct timeval mystamp; // timestamp for reading
        int ph;         	// deg C x10
        }PICO_PH_MSG;

typedef struct 
        {
        PICO_TOKEN token;	// PICO_TEMPERATURE
	int ID;
        struct timeval mystamp; // timestamp for reading
        int temperature;	// deg C x10
        }PICO_TEMPERATURE_MSG;

typedef struct 
        {
        PICO_TOKEN token;	// PICO_LIGHT
	int ID;
        struct timeval mystamp; // timestamp for reading
        int light;      	// Lux? x10
        }PICO_LIGHT_MSG;
 	
typedef struct 
        {
        PICO_TOKEN token;	// PICO_WHAT_READINGS
	int ID;
	float timer;
	float reading;
	int sensor;
        }PICO_WHAT_READINGS_MSG;

typedef struct 
        {
        PICO_TOKEN token;	// PICO_LED
	int ID;
	}PICO_LED_MSG;

typedef struct
	{
	int set_value;		// number for sensor
	DRDAQ_MODE n_modo;	// Temperature, Light, Voltage, 
				// Resistance, pH, etc.
	}DRDAQ_SENSOR;

typedef struct 
	{
	PICO_TOKEN token;	// PICO_READING_START
	int ID;
	float TMax;		// max value of time in sec
	int period;		// period in msec
	int maxReadings;	// max number of readings,  0- infinite
	int nsensors;  		// number of sensors 1 or 2
	int Sensor1;		// (0 or 1) if 1 sensor1 was selected 
	int Sensor2;		// (0 or 1) if 1 sensor2 was selected
	DRDAQ_SENSOR sensor[2];
	int n_passo;		// if = 1 measures are made until TMax 
				// with a certain period
				// if = 2 The actual period, maxReadings
	int AutoEscala;		// (0 or 1) 1 for Auto Scale
				// if not AutoEscala then grace parameters 
				// for scale:
	float xmax; 
	float ymax;
	float ymin;
	float maior_divx;
	float menor_divx;
	float maior_divy;
	float menor_divy;
	int XY;
	}PICO_START_MSG;

typedef struct
	{
	PICO_TOKEN token;	// PICO_READING_STOP
	int ID;
	}PICO_STOP_MSG;	

typedef struct 
        {
        PICO_TOKEN token;	// PICO_ANGLE_CALIBRATE
	int ID;
	int index;		// 0 or 1
	float angle;		// one initial angle
	int sensor;    		// 1 if Sensor 1 was selected
		  		// or 2 if Sensor 2 was seleted
        int set_value;    	// number for sensor
        }PICO_ANGLE_CALIBRATE_MSG;

typedef struct
          {
	  PICO_TOKEN token;        // PICO_ANGLE
	  int ID;
	  struct timeval mystamp;  // timestamp for reading
	  float angle;             // degree conversion from voltage
	  }PICO_ANGLE_MSG;

#endif
