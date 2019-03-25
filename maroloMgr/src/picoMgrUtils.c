#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <math.h>

//#include "pico_lnx.h"

#define _ALLOC extern
#include "picoMgr.h"
#undef _ALLOC

#include "picoMgrProto.h"
#include "loggerProto.h"

// arduino-serial
#include <stdio.h>    // Standard input/output definitions
#include <stdlib.h>
#include <string.h>   // String function definitions
#include <unistd.h>   // for usleep()
#include <getopt.h>

#include "arduino-serial-lib.h"


/*============================================
 *	turnLedOn - entry point
 * ============================================*/
int turnLedOn()
{
    static char *fn="turnLedOn";
    //int value;
    int rc=0;
    
    fcLogx(__FILE__, fn,
           globalMask,
           PICOMGR_FUNC_IO,
           "ding"
    );
    
    //value = 1 * DRDAQ_LED + digital_output * DRDAQ_DIGITAL_OUTPUT;
    //ioctl (picofd, IOCTL_MAROLO_SET_DIGITAL_OUT, &value);
    
    return(rc);
    
} // turnLedOn

/*============================================
 *	turnLedOff - entry point
 * ============================================*/
int turnLedOff()
{
    static char *fn="turnLedOff";
    //int value;
    //int rc;
    
    fcLogx(__FILE__, fn,
           globalMask,
           PICOMGR_FUNC_IO,
           "ding"
    );
    
    //value = 0 * DRDAQ_LED + digital_output * DRDAQ_DIGITAL_OUTPUT;
    //ioctl (picofd, IOCTL_MAROLO_SET_DIGITAL_OUT, &value);
    
    //return(rc);
    return(0);
    
} // turnLedOff

//
void error(char* msg)
{
    fprintf(stderr, "%s\n",msg);
    exit(EXIT_FAILURE);
}

int marolo_open() {
    char *serialavailable[8] = {\
        "/dev/ttyS0",\
        "/dev/ttyS1",\
        "/dev/ttyS2",\
        "/dev/ttyS3",\
        "/dev/ttyACM0",\
        "/dev/ttyACM1",\
        "/dev/ttyACM2",\
        "/dev/ttyACM3"\
    };
    static char *fn="marolo_open";
    const int buf_max = 20;
    int fd = -1;
    char serialport[buf_max];
    int baudrate = 9600;  // default
    char eolchar = '\n';
    int timeout = 5000;
    char buf[buf_max];
    strcpy(buf,"12\n");
    char *buf_split;
    char *devinfo[2];
    int rc=-1;
    int i;
    
    for (i=0; i<=7; i++) {
        if (fd!=-1) serialport_close(fd);
        fd = serialport_init(serialavailable[i], baudrate);
        if( fd!=-1 ) {
            serialport_flush(fd);
            strcpy(buf,"12\n");
            rc = serialport_write(fd, buf);
            if(rc==-1) error("error writing"); 
            sleep(1);
            memset(buf,0,buf_max);
            serialport_read_until(fd, buf, eolchar, buf_max, timeout);
            buf_split = strtok(buf, "|");
            devinfo[0] = buf_split;
            buf_split = strtok(NULL, "|");
            devinfo[1] = buf_split;
            if (devinfo[1]!=NULL) {
                strcpy(serialport, serialavailable[i]);
	    	serialport_close(fd);
            }
	    serialport_close(fd);
        }
    }
    fd = serialport_init(serialport, baudrate);
    if( fd==-1 ) error("couldn't open port");
    sleep(1);
    serialport_flush(fd);
    
    fcLogx(__FILE__, fn,
           globalMask,
           PICOMGR_FUNC_IO,
           "opened port <%s> - fd = %i", serialport, fd
    );
    fcLogx(__FILE__, fn,
           globalMask,
           PICOMGR_FUNC_IO,
           "version = <%s>", devinfo[0]
    );
    fcLogx(__FILE__, fn,
           globalMask,
           PICOMGR_FUNC_IO,
           "device name = <%s> fd = %i",devinfo[1], fd
    );
    
    //exit(EXIT_SUCCESS);
    return(fd);
}

/********************************************************************
 * 
 ********************************************************************/

int readMarolo(int myCALL)
{
    static char *fn="readMarolo";
    int adcReading;
    
    //value = ?; // internal sensor
    //value = 5; // conector EXT1
    //value = 10; // conector EXT2
    //value = set_value;
    
    // read ph in ADC units
    //ioctl(picofd, IOCTL_MAROLO_GET_VALUE, &value);
    //value = 9999;
    // convert ADC units to dB
    adcReading = 9999;
    
    fcLogx(__FILE__, fn,
           globalMask,
           PICOMGR_FUNC_IO,
           "AdcReading=%d myCALL=%s",
           adcReading, myCALL
    );
    
    return adcReading;
}
/********************************************************************
 * 
 ********************************************************************/

static int temp[101][2] = {
    {55,1500},
    {95,1333},
    {136,1196},
    {176,1085},
    {217,998},
    {257,932},
    {298,882},
    {379,814},
    {419,787},
    {460,762},
    {500,736},
    {540,712},
    {581,689},
    {621,667},
    {662,645},
    {702,625},
    {743,606},
    {783,587},
    {824,570},
    {864,554},
    {904,538},
    {945,524},
    {985,510},
    {1026,497},
    {1066,484},
    {1107,472},
    {1147,461},
    {1188,450},
    {1228,439},
    {1269,429},
    {1309,418},
    {1349,408},
    {1390,399},
    {1430,389},
    {1471,379},
    {1511,369},
    {1552,360},
    {1592,350},
    {1633,341},
    {1673,331},
    {1713,322},
    {1794,304},
    {1835,295},
    {1875,286},
    {1916,278},
    {1956,269},
    {1997,261},
    {2037,252},
    {2078,244},
    {2118,235},
    {2158,227},
    {2199,219},
    {2239,210},
    {2280,202},
    {2320,194},
    {2361,185},
    {2401,177},
    {2442,168},
    {2482,160},
    {2522,152},
    {2563,143},
    {2603,135},
    {2644,126},
    {2684,117},
    {2725,109},
    {2765,100},
    {2806,91},
    {2846,82},
    {2887,73},
    {2927,64},
    {2967,54},
    {3008,45},
    {3048,35},
    {3089,25},
    {3129,15},
    {3170,5},
    {3210,-6},
    {3251,-17},
    {3291,-28},
    {3331,-40},
    {3372,-52},
    {3412,-64},
    {3453,-77},
    {3493,-91},
    {3534,-105},
    {3574,-120},
    {3615,-136},
    {3655,-153},
    {3696,-171},
    {3736,-190},
    {3776,-210},
    {3817,-232},
    {3857,-258},
    {3898,-291},
    {3938,-333},
    {3979,-385},
    {4019,-450},
    {4060,-528},
    {4096,-611},
};

/********************************************************************
 * 
 ********************************************************************/

int scale_temp(int adcCount)
{
    int i, diffScaled, diffRaw, diffAdc, scaledValue=0;
    double scaleFactor;
    for (i=0; i<100; i++)
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

        
        
        
        
        
