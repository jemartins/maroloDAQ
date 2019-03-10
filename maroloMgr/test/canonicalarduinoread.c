/* www.chrisheydrick.com
     
   June 23 2012

   CanonicalArduinoRead write a byte to an Arduino, and then
   receives a serially transmitted string in response.

   The call/response Arduino sketch is here:
   https://gist.github.com/2980344

   Arduino sketch details at www.chrisheydrick.com
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

#define DEBUG 1
  
int main(int argc, char *argv[])
{
  int fd, n, i;
  //char buf[64] = "temp text";
  struct termios toptions;

  /* open serial port */
  //fd = open("/dev/ttyACM0", O_RDWR | O_NOCTTY);
  fd = open("/dev/ttyACM0",O_RDWR | O_NOCTTY | O_NDELAY);
  printf("fd opened as %i\n", fd);
  
  /* wait for the Arduino to reboot */
  usleep(3500000);
  
  /* get current serial port settings */
  tcgetattr(fd, &toptions);
  /* set 9600 baud both ways */
  cfsetispeed(&toptions, B9600);
  cfsetospeed(&toptions, B9600);
  /* 8 bits, no parity, no stop bits */
  toptions.c_cflag &= ~PARENB;
  toptions.c_cflag &= ~CSTOPB;
  toptions.c_cflag &= ~CSIZE;
  toptions.c_cflag |= CS8;
  /* Canonical mode */
  toptions.c_lflag |= ICANON;
  /* commit the serial port settings */
  tcsetattr(fd, TCSANOW, &toptions);

  /* Send byte to trigger Arduino to send string back */
  char buf_call[] = "14\n";
  //char *buf_call = "14\n";
  char buf_read[20];
  //strncpy(buf_call, "14", sizeof(buf_call));
  //buf_call[sizeof(buf_call) - 1] = '\n';
  printf("AQUI buf_call = %s", buf_call);
  write(fd, buf_call, sizeof(buf_call));
  
  printf("AQUI passou write, buf_call = %s", buf_call);
  /* Receive string from Arduino */
  n = read(fd, &buf_read, 20);
  printf("AQUI passou read\n");
  /* insert terminating zero in the string */
  //buf_read[n] = 0;

  printf("%i bytes read, buffer contains: %s\n", n, buf_read);
 
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
