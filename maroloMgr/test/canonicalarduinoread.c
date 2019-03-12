/* www.chrisheydrick.com
 *     
 *   June 23 2012
 * 
 *   CanonicalArduinoRead write a byte to an Arduino, and then
 *   receives a serially transmitted string in response.
 * 
 *   The call/response Arduino sketch is here:
 *   https://gist.github.com/2980344
 * 
 *   Arduino sketch details at www.chrisheydrick.com
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <sys/ioctl.h>

#define DEBUG 0

int main(int argc, char *argv[])
{
    int fd, n, i;
    /*------------------------------- Opening the Serial Port -------------------------------*/
    
    /* Change /dev/ttyUSB0 to the one corresponding to your system */
    
    fd = open("/dev/ttyACM0",O_RDWR | O_NOCTTY);	/* ttyUSB0 is the FT232 based USB2SERIAL Converter   */
    /* O_RDWR   - Read/Write access to serial port       */
    /* O_NOCTTY - No terminal will control the process   */
    /* Open in blocking mode,read will wait              */
    
    
    
    if(fd == -1)						/* Error Checking */
        printf("\n  Error! in Opening ttyUSB0  ");
    else
        printf("\n  ttyUSB0 Opened Successfully ");
    
    
    /*---------- Setting the Attributes of the serial port using termios structure --------- */
    
    struct termios SerialPortSettings;	/* Create the structure                          */
    
    tcgetattr(fd, &SerialPortSettings);	/* Get the current attributes of the Serial port */
    
    /* Setting the Baud rate */
    cfsetispeed(&SerialPortSettings,B9600); /* Set Read  Speed as 9600                       */
    cfsetospeed(&SerialPortSettings,B9600); /* Set Write Speed as 9600                       */
    
    /* 8N1 Mode */
    SerialPortSettings.c_cflag &= ~PARENB;   /* Disables the Parity Enable bit(PARENB),So No Parity   */
    SerialPortSettings.c_cflag &= ~CSTOPB;   /* CSTOPB = 2 Stop bits,here it is cleared so 1 Stop bit */
    SerialPortSettings.c_cflag &= ~CSIZE;	 /* Clears the mask for setting the data size             */
    SerialPortSettings.c_cflag |=  CS8;      /* Set the data bits = 8                                 */
    
    SerialPortSettings.c_cflag &= ~CRTSCTS;       /* No Hardware flow Control                         */
    SerialPortSettings.c_cflag |= CREAD | CLOCAL; /* Enable receiver,Ignore Modem Control lines       */ 
    
    
    SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY);          /* Disable XON/XOFF flow control both i/p and o/p */
    SerialPortSettings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);  /* Non Cannonical mode                            */
    
    SerialPortSettings.c_oflag &= ~OPOST;/*No Output Processing*/
    
    /* Setting Time outs */
    SerialPortSettings.c_cc[VMIN] = 20; /* Read at least 10 characters */
    SerialPortSettings.c_cc[VTIME] = 1; /* Wait indefinetly   */
    
    
    if((tcsetattr(fd,TCSANOW,&SerialPortSettings)) != 0) /* Set the attributes to the termios structure*/
        printf("\n  ERROR ! in Setting attributes");
    else
        printf("\n  BaudRate = 9600 \n  StopBits = 1 \n  Parity   = none \n");
    
    /*------------------------------- Read data from serial port -----------------------------*/
    
    tcflush(fd, TCIFLUSH);   /* Discards old data in the rx buffer            */
    /* Send byte to trigger Arduino to send string back */
    //char buf_call[] = "14\n";
    char buf_read[256];
    //strncpy(buf_call, "14", sizeof(buf_call));
    //buf_call[sizeof(buf_call)] = '\n';
    //printf("  AQUI buf_call = %s", buf_call);
    //tcflush(fd, TCIFLUSH);
    //write(fd, buf_call, sizeof(buf_call));
    
    const char* str="14\n";
    int len = strlen(str);
    n = write(fd, str, len);
    if( n!=len ) {
        perror("serialport_write: couldn't write whole string\n");
    }

    //printf("  AQUI passou write, buf_call = %s", buf_call);
    /* Receive string from Arduino */
    n = read(fd, &buf_read, 20);
    //printf("    AQUI passou read\n");
    /* insert terminating zero in the string */
    buf_read[n] = 0;
    
    printf("  %i bytes read, buffer contains: %s\n", n, buf_read);
    
    if(DEBUG)
    {
        printf("Printing individual characters in buf as integers...\n\n");
        for(i=0; i<n; i++)
        {
            printf("Byte %i:%i, ",i+1, (int)buf_read[i]);
        }
        printf("\n");
    }
    
    return 0;
}
