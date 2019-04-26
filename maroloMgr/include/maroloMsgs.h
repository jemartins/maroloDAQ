/*=====================================================
 *    drdaqMsgs.c
 * 
 *    Copyright (C) 2006 DrDAQ Application Project.
 * 
 *    This software is in the public domain.
 *    Permission to use, copy, modify, and distribute this software and its
 *    documentation for any purpose and without fee is hereby granted,
 *    without any conditions or restrictions.
 *    This software is provided "as is" without express or implied warranty.
 * 
 *    If you discover a bug or add an enhancement here's how to reach us:
 * 
 *    https://sourceforge.net/projects/drdaq
 *    
 * =====================================================*/

#ifndef _MAROLO_MSGS_DEF
#define _MAROLO_MSGS_DEF

#include <sys/time.h>
#include "standardTypes.h"

/*=======================================
 *	 wrapper message tokens
 * =======================================*/

typedef enum
{
    MAROLO_WHAT_YA_GOT,
    MAROLO_READING_START,
    MAROLO_READING_STOP,
    MAROLO_LED,
    MAROLO_INFO,
    MAROLO_VERSION,
    MAROLO_DO_READING,
    MAX_NUM_MAROLO_TOKENS
}MAROLO_TOKEN;

typedef enum
{
    NONE=10,      	 //10
    MAROLO_CALL_LED,     //11
    MAROLO_CALL_INFO,    //12
    MAROLO_CALL_VERSION, //13
    MAROLO_CALL_GETA0,   //14
    MAROLO_CALL_GETA1,   //15
    MAROLO_CALL_GETA2,   //16
    MAROLO_CALL_GETA3,   //17
    MAROLO_CALL_GETA4,   //18
    MAROLO_CALL_GETA5,   //19
    MAX_NUM_MAROLO_MODES
}MAROLO_MODE;

/*============================================
 *	message templates
 * ============================================*/
typedef struct 
{
    MAROLO_TOKEN token;	// MAROLO_WHAT_YA_GOT
    //int ID;
}MAROLO_WHAT_YA_GOT_MSG;

typedef struct 
{
    MAROLO_TOKEN  token;
    int ID;
    MAROLO_MODE call;
}MAROLO_DO_READING_MSG;

typedef struct 
{
    MAROLO_TOKEN token;	// MAROLO_WHAT_READINGS
    int ID;
    float timer;
    float reading;
    int adcReading;
}MAROLO_WHAT_READINGS_MSG;

typedef struct 
{
    MAROLO_TOKEN token;	// MAROLO_READING_START
    int ID;
}MAROLO_START_MSG;

typedef struct
{
    MAROLO_TOKEN token;	// MAROLO_READING_STOP
    int ID;
}MAROLO_STOP_MSG;	

typedef struct
{
    MAROLO_TOKEN token;        // MAROLO_
    int ID;
    struct timeval mystamp;  // timestamp for reading
    int adcReading;
}MAROLO_MEASURE_MSG;

#endif
