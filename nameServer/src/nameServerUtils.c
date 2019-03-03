/*=======================================================
   
FILE:		nameServerUtils.c

DESCRIPTION:	
This file contains source for nameServer.

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
$Log: nameServerUtils.c,v $
Revision 1.1  2006/07/06 14:34:27  bobfcsoft
seed code

=====================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>


#define _ALLOC extern
#include "nameServer.h"
#undef _ALLOC

#include "nameServerProto.h"
#include "loggerProto.h"

#if 0
/*============================================
	turnLedOn - entry point
============================================*/
int turnLedOn()
{
static char *fn="turnLedOn";
int value;
int rc=0;

fcLogx(__FILE__, fn,
	globalMask,
	PICOMGR_FUNC_IO,
	"ding"
	);

      value = 1 * DRDAQ_LED + digital_output * DRDAQ_DIGITAL_OUTPUT;
      ioctl (picofd, IOCTL_PICO_SET_DIGITAL_OUT, &value);

return(rc);

} // turnLedOn

/*============================================
	turnLedOff - entry point
============================================*/
int turnLedOff()
{
static char *fn="turnLedOff";
int value;
int rc;

fcLogx(__FILE__, fn,
	globalMask,
	PICOMGR_FUNC_IO,
	"ding"
	);

      value = 0 * DRDAQ_LED + digital_output * DRDAQ_DIGITAL_OUTPUT;
      ioctl (picofd, IOCTL_PICO_SET_DIGITAL_OUT, &value);

return(rc);

} // turnLedOff

/****************************************************************************
 *
 *
 ****************************************************************************/
int drdaq_open (int lp)
  {
    static 		char *fn="drdaq_open";
    int 		file;
    char 		dev_name [20];

    /* 
     * Open the device for this printer port
    */
    sprintf (dev_name, "/dev/picopar%d", lp);
    file = open (dev_name, 0);

    fcLogx(__FILE__, fn,
	globalMask,
	PICOMGR_FUNC_IO,
	"open device"
	);

    return file;
  }

/********************************************************************
 *
 ********************************************************************/

int readWaveForm(int set_value)
{
	static char *fn="readWaveForm";
	int value;
	int waveform;

	// Set scale ADC
	value = SCALE_ADC;
	ioctl(picofd, IOCTL_PICO_SET_SCALE, &value);
    
	// Set read mode to double
	value = READ_MODE_DOUBLE;
	ioctl(picofd, IOCTL_PICO_SET_READ_MODE, &value);

	//value = 1; // internal sensor
	//value = 5; // conector EXT1
	//value = 10; // conector EXT2
	value = set_value;
	
	// read wave in ADC units
	ioctl(picofd, IOCTL_PICO_GET_VALUE, &value);

	// convert ADC units to dB
	waveform = value;

	fcLogx(__FILE__, fn,
		globalMask,
		PICOMGR_FUNC_IO,
		"waveform=%d set_value=%d",
		waveform, set_value
		);
	
	return waveform;
}

/********************************************************************
 *
 ********************************************************************/

int readSoundLevel(int set_value)
{
	static char *fn="readSoundLevel";
	int value;
	int soundlevel;

	// Set scale ADC
	value = SCALE_ADC;
	ioctl(picofd, IOCTL_PICO_SET_SCALE, &value);
    
	// Set read mode to double
	value = READ_MODE_DOUBLE;
	ioctl(picofd, IOCTL_PICO_SET_READ_MODE, &value);

	//value = 3; // internal sensor
	//value = 5; // conector EXT1
	//value = 10; // conector EXT2
	value = set_value;
	
	// read soundlevel in ADC units
	ioctl(picofd, IOCTL_PICO_GET_VALUE, &value);

	// convert ADC units to dB
	soundlevel = scale_sound(value);

	fcLogx(__FILE__, fn,
		globalMask,
		PICOMGR_FUNC_IO,
		"soundlevel=%d set_value=%d",
		soundlevel, set_value
		);
	
	return soundlevel;
}

/********************************************************************
 *
 ********************************************************************/

int readVoltage(int set_value)
{
	static char *fn="readVoltage";
	int value;
	int voltage;

	// Set scale ADC
	value = SCALE_ADC;
	ioctl(picofd, IOCTL_PICO_SET_SCALE, &value);
    
	// Set read mode to double
	value = READ_MODE_DOUBLE;
	ioctl(picofd, IOCTL_PICO_SET_READ_MODE, &value);

	//value = 4; // internal sensor
	//value = 5; // conector EXT1
	//value = 10; // conector EXT2
	value = set_value;
	
	// read voltage in ADC units
	ioctl(picofd, IOCTL_PICO_GET_VALUE, &value);

	// convert ADC units to mV
	voltage = (value * 5000)/4095;

	fcLogx(__FILE__, fn,
		globalMask,
		PICOMGR_FUNC_IO,
		"voltage=%d set_value=%d",
		voltage, set_value
		);
	
	return voltage;
}

/********************************************************************
 *
 ********************************************************************/

int readResistance(int set_value)
{
	static char *fn="readResistance";
	int value;
	int resistance;

	// Set scale ADC
	value = SCALE_ADC;
	ioctl(picofd, IOCTL_PICO_SET_SCALE, &value);
    
	// Set read mode to double
	value = READ_MODE_DOUBLE;
	ioctl(picofd, IOCTL_PICO_SET_READ_MODE, &value);

	//value = ?; // internal sensor
	//value = 5; // conector EXT1
	//value = 10; // conector EXT2
	value = set_value;
	
	// read resistence in ADC units
	ioctl(picofd, IOCTL_PICO_GET_VALUE, &value);

	// convert ADC units to dB
	resistance = value;

	fcLogx(__FILE__, fn,
		globalMask,
		PICOMGR_FUNC_IO,
		"resistance=%d set_value=%d",
		resistance, set_value
		);
	
	return resistance;
}

/********************************************************************
 *
 ********************************************************************/

int readPH(int set_value)
{
	static char *fn="readPH";
	int value;
	int ph;

	// Set scale ADC
	value = SCALE_ADC;
	ioctl(picofd, IOCTL_PICO_SET_SCALE, &value);
    
	// Set read mode to double
	value = READ_MODE_DOUBLE;
	ioctl(picofd, IOCTL_PICO_SET_READ_MODE, &value);

	//value = ?; // internal sensor
	//value = 5; // conector EXT1
	//value = 10; // conector EXT2
	value = set_value;
	
	// read ph in ADC units
	ioctl(picofd, IOCTL_PICO_GET_VALUE, &value);

	// convert ADC units to dB
	ph = value;

	fcLogx(__FILE__, fn,
		globalMask,
		PICOMGR_FUNC_IO,
		"PH=%d set_value=%d",
		ph, set_value
		);
	
	return ph;
}

/********************************************************************
 *
 ********************************************************************/

int readTemperature(int set_value)
{
	static char *fn="readTemperature";
	int value;
	int temperature;

	// Set scale ADC
	value = SCALE_ADC;
	ioctl(picofd, IOCTL_PICO_SET_SCALE, &value);
    
	// Set read mode to double
	value = READ_MODE_DOUBLE;
	ioctl(picofd, IOCTL_PICO_SET_READ_MODE, &value);

	//value = 11; // internal sensor
	//value = 5; // conector EXT1
	//value = 10; // conector EXT2
	value = set_value;
	
	// read temperature in ADC units
	ioctl(picofd, IOCTL_PICO_GET_VALUE, &value);

	// convert ADC units to C degree
	temperature = scale_temp(value);

	fcLogx(__FILE__, fn,
		globalMask,
		PICOMGR_FUNC_IO,
		"temperature=%d set_value=%d",
		temperature, set_value
		);
	
	return temperature;
}

/********************************************************************
 *
 ********************************************************************/

int readLight(int set_value)
{
	static char *fn="readLight";
	int value;
	int light;

	// Set scale ADC
	value = SCALE_ADC;
	ioctl(picofd, IOCTL_PICO_SET_SCALE, &value);
    
	// Set read mode to double
	value = READ_MODE_DOUBLE;
	ioctl(picofd, IOCTL_PICO_SET_READ_MODE, &value);

	//value = 6; // internal sensor
	//value = 5; // conector EXT1
	//value = 10; // conector EXT2
	value = set_value;
	
	// read light in ADC units
	ioctl(picofd, IOCTL_PICO_GET_VALUE, &value);

	// convert ADC units to 
	light = scale_light(value);

	fcLogx(__FILE__, fn,
		globalMask,
		PICOMGR_FUNC_IO,
		"light=%d set_value=%d",
		light, set_value
		);
	
	return light;
}

/********************************************************************
 *
 ********************************************************************/

static int temp[17][2] = {
{ 55, 1500 },
{ 216, 1000 },
{ 400, 800 },
{ 755, 600 },
{ 1384, 400 },
{ 1813, 300 },
{ 2048, 250 },
{ 2289, 200 },
{ 2530, 150 },
{ 2765, 100 },
{ 2985, 50 },
{ 3187, 0 },
{ 3366, -50 },
{ 3520, -100 },
{ 3756, -200 },
{ 3907, -300 },
{ 4046, -500 },
};

/********************************************************************
 *
 ********************************************************************/

int scale_temp(int adcCount)
{
	int i, diffScaled, diffRaw, diffAdc, scaledValue=0;
    	double scaleFactor;
    	for (i=0; i<16; i++)
    	{
    		if (adcCount >= temp[i][0] && adcCount < temp[i+1][0])
        	{
            		diffScaled = temp[i][1] - temp[i+1][1];
            		diffRaw = temp[i+1][0] - temp[i][0];
            		scaleFactor = (double)diffScaled / (double)diffRaw;
            		diffAdc = adcCount - temp[i][0];
            		scaledValue = temp[i][1] - (diffAdc * scaleFactor);
            		return scaledValue;
        	}
	}
	return -1;
}

/********************************************************************
 *
 ********************************************************************/

static int sound[48][2] = {
{ 0, 550 },
{ 3, 550 },
{ 4, 570 },
{ 5, 590 },
{ 6, 600 },
{ 7, 620 },
{ 8, 630 },
{ 9, 650 },
{ 10, 660 },
{ 11, 670 },
{ 13, 680 },
{ 14, 690 },
{ 16, 700 },
{ 17, 705 },
{ 19, 710 },
{ 23, 720 },
{ 28, 730 },
{ 34, 740 },
{ 41, 750 },
{ 50, 760 },
{ 61, 770 },
{ 73, 780 },
{ 89, 790 },
{ 108, 800 },
{ 131, 810 },
{ 159, 820 },
{ 193, 830 },
{ 213, 835 },
{ 242, 840 },
{ 275, 850 },
{ 313, 860 },
{ 357, 870 },
{ 406, 880 },
{ 462, 890 },
{ 526, 900 },
{ 599, 910 },
{ 682, 920 },
{ 777, 930 },
{ 885, 940 },
{ 1007, 950 },
{ 1147, 960 },
{ 1305, 970 },
{ 1486, 980 },
{ 1692, 990 },
{ 1926, 1000 },
{ 2193, 1010 },
{ 2497, 1020 },
{ 2843, 1030 },
};

/********************************************************************
 *
 ********************************************************************/

int scale_sound(int adcCount)
{
	int i, diffScaled, diffRaw, diffAdc, scaledValue=0;
	double scaleFactor;
	for (i=0; i<47; i++)
	{
		if (adcCount >= sound[i][0] && adcCount < sound[i+1][0])
		{
			diffScaled = sound[i+1][1] - sound[i][1];
			diffRaw = sound[i+1][0] - sound[i][0];
			scaleFactor = (double)diffScaled / (double)diffRaw;
			diffAdc = adcCount - sound[i][0];
			scaledValue = (diffAdc * scaleFactor) + sound[i][1];
			return scaledValue;
		}
	}
	return -1;
}

/********************************************************************
 *
 ********************************************************************/

static int light[11][2] = {
{ 0, 0 },
{ 410, 20 },
{ 819, 40 },
{ 1229, 60 },
{ 1638, 110 },
{ 2048, 160 },
{ 2457, 230 },
{ 2867, 320 },
{ 3276, 440 },
{ 3686, 620 },
{ 4095, 1000 },
};

/********************************************************************
 *
 ********************************************************************/

int scale_light(int adcCount)
{
	int i, diffScaled, diffRaw, diffAdc, scaledValue=0;
	double scaleFactor;
	for (i=0; i<10; i++)
	{
		if (adcCount >= light[i][0] && adcCount < light[i+1][0])
		{
			diffScaled = light[i+1][1] - light[i][1];
			diffRaw = light[i+1][0] - light[i][0];
			scaleFactor = (double)diffScaled / (double)diffRaw;
			diffAdc = adcCount - light[i][0];
			scaledValue = (diffAdc * scaleFactor) + light[i][1];
			return scaledValue;
		}
	}
	return -1;
}

/********************************************************************
 *
 ********************************************************************/

#if 0
/****************************************************************************
 *
 * Pico DrDAQ example program
 *
 * Module:       ddtest.c
 *
 * Copyright 2001 Pico Technology Limited
 *
 * Description:
 * This module demonstrates how to access the DrDAQ driver.
 *
 * The following IOCTLs are supported:
 *	IOCTL_PICO_SET_PRODUCT
 *		67 - product is DrDAQ
 *
 * 	IOCTL_PICO_SET_SCALE
 *		SCALE_ADC - return values in ADC counts
 *		SCALE_MV - return values in engineering units, eg degC for temperature
 *
 *	DrDAQ is a 10-bit device, but the driver treats it as a 12-bit device and
 *	returns a value between 0 and 4095. The external inputs accept signals in the 0..2500mV input range.
 *      the driver applies the following conversions:
 *		ADC	mV
 *		0	0
 *		4095    2500
 *
 *	IOCTL_PICO_SET_READ_MODE
 *		READ_MODE_SINGLE - take a single conversion for each call
 *		READ_MODE_DOUBLE - take two conversions for each call
 *
 *	On each conversion, the ADC returns the value of the previous conversion.
 *	If READ_MODE_SINGLE is used, the returned value is the value for the previous call.
 *	This may be acceptable when reading at high speed, but could cause problems
 *	if you take (say) one reading per second.
 *
 *	If READ_MODE_DOUBLE is used, each call takes twice as long, butthe
 *      returned value is the value for the first of the two conversions- ie
 *      it is a current reading, rather than one from the previous call.
 *
 *	IOCTL_PICO_SET_DO
 *		0 - digital output is off
 *		1 - digital output is on
 *		2 - LED is on
 *		3 - LED and digital output are on
 *
 *	IOCTL_PICO_GET_VALUE
 *	  accepts:
 *        	1 - Sound waveform
 *		2 - Sound level
 *		3 - Voltage
 *		4 - Resistance
 *		5 - pH
 *		6 - Temperature
 *		7 - Light
 *		8 - External input 1
 *		9 - External input 2
 *		10 - resistance value for EXT1
 *		11 - resistance value for EXT2
 *	  returns:
 *		adc value or reading in engineering units
 *
 * Revision Info: "file %n date %f revision %v"
 *                "file a11test.c date 11-Feb-95,17:40:10 revision 1"
 *
 ****************************************************************************/


#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <asm/ioctl.h>

#include "pico_lnx.h"

#define FALSE 		0
#define TRUE 		1
#define MAX_SAMPLES 	1000
#define MAX_CHANNELS	2      /* No of channels you can record from at once
				* You can increase this if required */
#define MAX_DRDAQ_CHANNELS 9


int	file;
int	values [MAX_CHANNELS] [MAX_SAMPLES];
long	times [MAX_SAMPLES];
int	scale_values = TRUE;
int	digital_output;
int	led;

/****************************************************************************
 *
 *
 ****************************************************************************/
int drdaq_open (int lp)
  {
  int 		file;
  char 		dev_name [20];
  int		value;

  /* Open the device for this printer port
   */
  sprintf (dev_name, "/dev/pico%d", lp);
  file = open (dev_name, 0);
  return file;
  }

/****************************************************************************
 *
 *
 ****************************************************************************/
void time_readings (void)
  {
  struct timeval 	start;
  struct timeval 	end;
  struct timezone 	tz;
  int			i;
  int			value;
  int			interval;

  /* Set single read mode
   *  (fast, but each call gives you get the result of the previous conversion)
   */

  value = READ_MODE_SINGLE;
  ioctl (file, IOCTL_PICO_SET_READ_MODE, &value);

  gettimeofday (&start, &tz);
  for (i = 0; i < MAX_SAMPLES; i++)
    {
    /* Single read from channel 3
     */
    value = 3;
    ioctl (file, IOCTL_PICO_GET_VALUE, &value);
    values [0] [i] = value;
    }
  gettimeofday (&end, &tz);

  interval = end.tv_usec - start.tv_usec;
  if (interval < 0)
    {
    interval += 1000000;
    }

  printf ("%d readings in %ld us\n", MAX_SAMPLES, interval);
  }


/****************************************************************************
 *
 *
 ****************************************************************************/
void write_block_to_file (void)
  {
  struct timeval 	time;
  struct timezone 	tz;
  int			i;
  int			j;
  int			value;
  int			interval;
  FILE *		out_fp;

  printf ("Writing data to drdaq.txt\n");

  /* Set single read mode
   *  (fast, but each call gives you get the result of the previous conversion)
   */

  value = READ_MODE_SINGLE;
  ioctl (file, IOCTL_PICO_SET_READ_MODE, &value);

  for (i = 0; i < MAX_SAMPLES; i++)
    {
    /* This is how to vary the sampling interval...
     *  or omit for full-speed operation
     */
    for (j = 0; j < 1000; j++);

    /* Single read  from channels 3 and 5
     *  remember that each ioctl gives the result of the PREVIOUS conversion,
     * So we have to take one extra reading to get the last conversion
     */
    value = 6;
    ioctl (file, IOCTL_PICO_GET_VALUE, &value);
    value = 7;
    ioctl (file, IOCTL_PICO_GET_VALUE, &value);
    values [0] [i] = value;
    value = 7;
    ioctl (file, IOCTL_PICO_GET_VALUE, &value);
    values [1] [i] = value;

    gettimeofday (&time, &tz);
    times [i] = time.tv_usec;
    }

  out_fp = fopen ("drdaq.txt", "w");
  if (out_fp != NULL)
    {
    for (i = 0; i < MAX_SAMPLES; i++)
      {
      interval = times [i] - times [0];
      if (interval < 0)
        interval += 1000000;

      fprintf (out_fp, "%d %d %d\n", interval, values [0] [i], values [1] [i]);
      }
    fclose (out_fp);

    }
  }

/****************************************************************************
 *
 *
 ****************************************************************************/
long get_ms (void)
  {
  struct timeval 	time;
  struct timezone 	tz;

  gettimeofday (&time, &tz);

  return time.tv_sec * 1000 + time.tv_usec / 1000;
  }

void write_continuous_to_file (void)
  {
  int			i;
  int			j;
  int			value;
  int			start_ms;
  int			next_ms;
  int			ms;
  FILE *		out_fp;
  int			ch;

  value = READ_MODE_DOUBLE;
  ioctl (file, IOCTL_PICO_SET_READ_MODE, &value);

  out_fp = fopen ("drdaq.txt", "w");
  if (out_fp != NULL)
    {
    start_ms = get_ms ();
    ms = 0;
    next_ms = 0;
    for (i = 0; i < 50; i++)
      {
      while (ms < next_ms)
        {
        ms = get_ms () - start_ms;
        }
      next_ms += 10;

      for (ch = 1; ch <= 11; ch++)
        {
        value = ch;
        ioctl (file, IOCTL_PICO_GET_VALUE, &value);

        fprintf (out_fp, "%5d", value);
        printf ("%5d", value);
        }
      fprintf (out_fp, "\n");
      printf ("\n");
      }

    fclose (out_fp);

    }
  }


/****************************************************************************
 *
 *
 ****************************************************************************/

int main (void)
  {
  char 		line [80];
  char		ch;
  int		port;
  int		value;

  printf ("Pico DrDAQ example for Linux V1.0\n");
  printf ("Enter printer port (0..2)\n");
  fgets (line, sizeof (line), stdin);
  port = line [0] - '0';

  file = drdaq_open (port);
  if (file == 0)
    {
    printf ("Unable to open port\n");
    exit (99);
    }

  ioctl (file, IOCTL_PICO_GET_VERSION, &value);
  printf ("Kernel driver version %04x\n", value);

  value = PRODUCT_DRDAQ;
  ioctl (file, IOCTL_PICO_SET_PRODUCT, &value);


  ch = ' ';
  while (ch != 'X')
    {
    printf ("A - switch between ADC values and measurement units\n");
    printf ("D - Toggle the digital output\n");
    printf ("L - Toggle the LED\n");
    printf ("T - timed readings\n");
    printf ("B - write block to file\n");
    printf ("C - write continuous data to file\n");
    printf ("X - exit\n");

    fgets (line, sizeof (line), stdin);
    ch = toupper (line [0]);
    switch (ch)
      {
      case 'A':
      scale_values = !scale_values;
      value = scale_values;
      ioctl (file, IOCTL_PICO_SET_SCALE, &value);
      if (scale_values)
        {
        printf ("Values will be displayed in measurement units\n");
        }
      else
        {
        printf ("Values will be displayed in ADC counts\n");
        }
      break;

      case 'D':
      digital_output = !digital_output;
      value = led * DRDAQ_LED + digital_output * DRDAQ_DIGITAL_OUTPUT;
      ioctl (file, IOCTL_PICO_SET_DIGITAL_OUT, &value);
      if (digital_output)
        {
        printf ("Digital output is ON\n");
        }
      else
        {
        printf ("Digital output is OFF\n");
        }
      break;

      case 'L':
      led = !led;
      value = led * DRDAQ_LED + digital_output * DRDAQ_DIGITAL_OUTPUT;
      ioctl (file, IOCTL_PICO_SET_DIGITAL_OUT, &value);
      if (led)
        {
        printf ("LED is ON\n");
        }
      else
        {
        printf ("LED is OFF\n");
        }
      break;

      case 'T':
      time_readings ();
      break;

      case 'B':
      write_block_to_file ();
      break;

      case 'C':
      write_continuous_to_file ();
      break;
      }
    }


  close (file);

  return 0;
  }
#endif

#endif
