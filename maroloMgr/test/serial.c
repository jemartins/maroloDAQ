	#include <stdio.h>
	#include <fcntl.h>   /* File Control Definitions           */
	#include <termios.h> /* POSIX Terminal Control Definitions */
	#include <unistd.h>  /* UNIX Standard Definitions 	   */ 
	#include <errno.h>   /* ERROR Number Definitions           */
	void main()
	{
		int fd; /*File Descriptor*/

		fd = open("/dev/ttyS0",O_RDWR | O_NOCTTY);    /* ttyUSB0 is the FT232 based USB2SERIAL Converter   */
			   					/* O_RDWR   - Read/Write access to serial port       */
								/* O_NOCTTY - No terminal will control the process   */
								/* Open in blocking mode,read will wait              */

		if(fd == -1)					/* Error Checking */
          	   printf("\n  Error! in Opening ttyUSB0\n\n");
       		else
         	   printf("\n\n  ttyUSB0 Opened Successfully\n\n");

	        close(fd); /* Close the serial port */

	}
