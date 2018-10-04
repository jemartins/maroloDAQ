/****************************************************************************
 *
 * Project:      maroloDAQ data logger
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 *
 *
 *   autor: José Eduardo martins
 *   email: jemartins@fis.unb.br
 *          Instituto de Física
 *          Universidade de Brasília
 *   
 * programers: José Eduardo Martins
 *             Rafael Ramos [rafaelframos@gmail.com]
 *             
 ****************************************************************************/
 
#ifndef CALIBRATION_H
#define CALIBRATION_H

// Temperature Sensor Calibration
const int temp[101][2] = {
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

// Sound Sensor Calibration
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

// Light Sensor Calibration
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


typedef struct
{
    double angle;
    double voltage;
}CALIBRATION;

CALIBRATION calibrationArray[2];

#endif // CALIBRATION_H
