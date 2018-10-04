 ###########################################################################
 #
 # Project:      maroloDAQ data logger
 #
 #   This program is free software; you can redistribute it and/or modify
 #   it under the terms of the GNU General Public License as published by
 #   the Free Software Foundation; either version 3 of the License, or
 #   (at your option) any later version.
 #
 #   This program is distributed in the hope that it will be useful,
 #   but WITHOUT ANY WARRANTY; without even the implied warranty of
 #   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 #   GNU General Public License for more details.
 #
 #   You should have received a copy of the GNU General Public License
 #   along with this program; if not, write to the Free Software
 #   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 #
 #
 #   autor: José Eduardo martins
 #   email: jemartins@fis.unb.br
 #          Instituto de Física
 #          Universidade de Brasília
 #   
 # programers: José Eduardo Martins
 #             Rafael Ramos [rafaelframos@gmail.com]
 #             
 ############################################################################

#-------------------------------------------------
#
# Project created by QtCreator 2017-09-08T16:13:46
#
#-------------------------------------------------

QT       	+= core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET		= maroloDAQ
TEMPLATE	= app
RESOURCES 	= maroloDAQ.qrc
DESTDIR		= bin

INCLUDEPATH	+= $$PWD/include

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES   += main.cpp\
	maroloDAQ.cpp \
	comserial.cpp

HEADERS   += $$INCLUDEPATH/maroloDAQ.h \
	$$INCLUDEPATH/calibration.h 

FORMS     += maroloDAQ.ui

LIBS      += -lgrace_np

DISTFILES += abobora

