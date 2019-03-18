#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include<termios.h>

int main() {    

    int STATE_OK=0;
    int STATE_WARNING=1;
    int STATE_CRITICAL=2; 
    char tempbuf[10];
    struct termios tty;

    int fd=open("/dev/ttyACM1",O_RDWR | O_NOCTTY);
    if(fd == -1){
            printf("Unable to open /dev/ttyACM1\n");
            return STATE_WARNING;
    }else {
        if(tcgetattr(fd, &tty)!=0){
            perror("tcgetatt() error");
        }else{
                cfsetospeed(&tty, B9600);
                cfsetispeed(&tty, B9600);

                tty.c_cflag &= ~PARENB;
                tty.c_cflag &= ~CSTOPB;
                tty.c_cflag &= ~CSIZE;
                tty.c_cflag |= CS8;
                tty.c_cflag &= ~CRTSCTS; 
                tty.c_cflag |= CLOCAL | CREAD;

                tty.c_iflag |= IGNPAR | IGNCR;
                tty.c_iflag &= ~(IXON | IXOFF | IXANY);
                tty.c_lflag |= ICANON;
                tty.c_oflag &= ~OPOST;
                tcsetattr(fd, TCSANOW, &tty);

                int w=write(fd, "t", 1);/*printf("%d\n",w);
                fprintf(stderr, "fd = %d.\n", fd);*/
                usleep(1000);
                int n=read(fd,tempbuf,8);/*printf("%d \n",n);*/
                tempbuf[9]=0;
                float temp=atof(tempbuf);

                if (temp>27){
                    printf("CRITICAL: %f celsius\n",temp);
                    return STATE_CRITICAL;
                }else{
                    printf("Everything is OK and the temperature is %f Celsius\n",temp);
                    return STATE_OK;
                }
        }
    }
    close(fd);
    return 0;
}
