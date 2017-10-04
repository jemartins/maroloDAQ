#include "include/guireceiver.h"
#include "ui_guireceiver.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "include/receiverMsgs.h"
#include "include/stimulatorMsgs.h"

#define _ALLOC extern
_ALLOC int logger_ID;
_ALLOC char logBuf[LOGGER_BUFFER_SIZE];
_ALLOC char loggerArea[TRACE_MAX_BUFFER_SIZE];
_ALLOC char inArea[MAX_MSG_SIZE];
_ALLOC char outArea[MAX_MSG_SIZE];
#undef _ALLOC

#include "simpl.h"
#include "simplProto.h"
#include "loggerProto.h"
#include "simplmiscProto.h"
#include "include/receiverProto.h"

guiReceiver::guiReceiver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::guiReceiver)
{
    ui->setupUi(this);
}

guiReceiver::~guiReceiver()
{
    delete ui;
}

void guiReceiver::on_pbSair_clicked()
{
    exit(0);
}

/*============================================
    initialize - entry point
============================================*/
void initialize(int argc, char **argv) {
static char *fn="initialize";
int i;                          /* loop variable */
char myName[20];
char loggerName[20];
int myslot;

globalMask=0xff;
myName[0]=0;

/*===============================================
  process command args
===============================================*/
for(i=1; i<=argc; ++i)
        {
        char *p = argv[i];

        if(p == NULL) continue;

        if(*p == '-')
                {
                switch(*++p)
                        {
                        case 'n':
                                for(;*p != 0; p++);
                sprintf(myName,"%s",++p);
                myslot=name_attach(myName, NULL);
                if(myslot == -1)
                    {
                    printf("%s: unable to attach as <%s>\n",
                        fn,
                        myName);
                    exit(0);
                    }
                else
                    printf("attached as <%s> myslot=%d\n",myName,myslot);
                                break;

            case 'l':
                                for(;*p != 0; p++);
                sprintf(loggerName,"%.19s",++p);
                break;

            case 'm':
                if(*++p == 0) p++;
				globalMask=atoh(&p[2]);  // skip 0x
                break;

                        default:
                printf("%s:unknown arg %s\n",fn, p);
                                break;
                        }/*end switch*/
                } /* end if *p */
        }/*end for i*/

// check for compulsory args
if(myName[0] == 0)
    {
    myUsage();
    exit(0);
    }

// try to connect to trace logger
logger_ID = is_logger_upx(loggerName);

fcLogx(__FILE__, fn,
    0xff,
    RECV_MARK,
    "myName=<%s> myslot=%d",
    myName,
    myslot
    );

fcLogx(__FILE__, fn,
    0xff,
    RECV_MARK,
    "trace logger mask = 0x%04X",
    globalMask);

} /* end initialize */

/*===================================================
    myUsage - entry point
===================================================*/
void myUsage() {
printf("====================== usage =============================\n");
printf(" usage for receiver:\n");
printf("      receiver -n <myName> <optionals>\n");
printf("      where optionals are:\n");
printf("        -m 0x<mask> - trace logger mask override\n");
printf("        -l <loggerName> - connect to trace logger\n");
printf("==========================================================\n");
}// end myUsage
