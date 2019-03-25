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
	PICO_MAROLO,
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
	DRDAQ_MAROLO,
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
	int CALL;
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

typedef struct
          {
	  PICO_TOKEN token;        // PICO_MAROLO
	  int ID;
	  struct timeval mystamp;  // timestamp for reading
	  int adcReading;
	  }PICO_MAROLO_MSG;

#endif
