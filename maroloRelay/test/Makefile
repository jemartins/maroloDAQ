#=======================================================
#
# DESCRIPTION:	
# Makefile for softwareICs/relay/test tree.
#
# AUTHOR:	R.D. Findlay
#
#-----------------------------------------------------------------------
#    Copyright (C) 2000, 2002, 2008 FCSoftware Inc. 
#
#    This software is in the public domain.
#    Permission to use, copy, modify, and distribute this software and its
#    documentation for any purpose and without fee is hereby granted, 
#    without any conditions or restrictions.
#    This software is provided "as is" without express or implied warranty.
#
#    If you discover a bug or add an enhancement contact us on the: 
#
#	SIMPL project mailing list
#-----------------------------------------------------------------------
# Revision history:
#=======================================================
# $Log: Makefile,v $
# Revision 1.2  2009/04/14 16:22:12  bobfcsoft
# added i386 target
#
# Revision 1.1  2008/11/26 17:07:54  bobfcsoft
# new file
#
# Revision 1.2  2002/12/03 21:19:43  root
# v2.0 compatible
#
# Revision 1.1  2002/12/03 19:53:48  root
# Initial revision
#
#=======================================================

SOFT_IC_DIR=../..
SIMPL_DIR=$(SIMPL_HOME)

CC=cc
DE=DEBUG

PROGRAM_NAME=
line1 = --------------------------------------------------------------------
line2 = ====================================================================

OBJ_DIR=obj
LIB_DIR=../lib
BIN_DIR=../bin
INSTALL_BIN_DIR=$(SOFT_IC_DIR)/bin
INSTALL_LIB_DIR=$(SOFT_IC_DIR)/lib

LOCAL_INCL_DIR=../include
SIMPL_INCL_DIR=$(SIMPL_DIR)/include

RECV_SIM_OBJ=\
	$(OBJ_DIR)/receiverSim.o\
	$(OBJ_DIR)/recvSimInit.o\
	$(OBJ_DIR)/recvSimUtils.o

RELAY_STIM_OBJ=\
	$(OBJ_DIR)/relayStim.o\
	$(OBJ_DIR)/relayStimInit.o\
	$(OBJ_DIR)/relayStimUtils.o

CFLAGS=\
	-c \
	-Wall \
	-D $(DE) \
	-I $(LOCAL_INCL_DIR) \
	-I $(SIMPL_INCL_DIR)

LDFLAGS=\
	-L $(SIMPL_DIR)/lib\
	-lsimplmisc\
	-lsimpllog\
	-lsimpl

ARCHFLAGS =

HEADERS=

THIS_TARGET="starting"
DO_END=make -s title THIS_TARGET="<$@> done"

#========================
# Default targets
#========================
all:\
     title \
     $(OBJ_DIR) \
     $(BIN_DIR) \
     $(BIN_DIR)/receiverSim\
     $(BIN_DIR)/relayStim
	@$(DO_END)

title:
	@echo "=============== relay/test $(THIS_TARGET) ================"

description:
	@(\
	echo;\
	echo "$(line1)";\
	echo "Compiling $(PROGRAM_NAME) module -> $(OBJ_NAME)";\
	echo )

$(OBJ_DIR):
	mkdir obj
	chmod a+w obj

$(LIB_DIR):
	mkdir ../lib
	chmod a+w ../lib

$(BIN_DIR):
	mkdir ../bin
	chmod a+w ../bin

#========================
# Link
#========================
$(BIN_DIR)/receiverSim:	$(RECV_SIM_OBJ)
	$(CC) -o $(BIN_DIR)/receiverSim $(RECV_SIM_OBJ) $(LDFLAGS)
	
$(BIN_DIR)/relayStim:	$(RELAY_STIM_OBJ)
	$(CC) -o $(BIN_DIR)/relayStim $(RELAY_STIM_OBJ) $(LDFLAGS)
	
#===================
# Compiles
#===================
$(OBJ_DIR)/receiverSim.o: receiverSim.c
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) $(ARCHFLAGS) $(CFLAGS) -o $(OBJ_DIR)/receiverSim.o receiverSim.c

$(OBJ_DIR)/recvSimInit.o: recvSimInit.c
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) $(ARCHFLAGS) $(CFLAGS) -o $(OBJ_DIR)/recvSimInit.o recvSimInit.c

$(OBJ_DIR)/recvSimUtils.o: recvSimUtils.c
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) $(ARCHFLAGS) $(CFLAGS) -o $(OBJ_DIR)/recvSimUtils.o recvSimUtils.c

$(OBJ_DIR)/relayStim.o: relayStim.c
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) $(ARCHFLAGS) $(CFLAGS) -o $(OBJ_DIR)/relayStim.o relayStim.c

$(OBJ_DIR)/relayStimInit.o: relayStimInit.c
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) $(ARCHFLAGS) $(CFLAGS) -o $(OBJ_DIR)/relayStimInit.o relayStimInit.c

$(OBJ_DIR)/relayStimUtils.o: relayStimUtils.c
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) $(ARCHFLAGS) $(CFLAGS) -o $(OBJ_DIR)/relayStimUtils.o relayStimUtils.c

#========================
# Cleanup
#========================
clobber: clean
clean:
	@-rm -f $(OBJ_DIR)/*.o
	@-rm -f $(BIN_DIR)/receiverSim
	@-rm -f $(BIN_DIR)/relayStim
	@$(DO_END)

#========================
# Install
#========================
install:\
     title \
     $(OBJ_DIR) \
     $(BIN_DIR) \
     $(BIN_DIR)/receiverSim\
     $(BIN_DIR)/relayStim
	cp $(BIN_DIR)/relayStim $(INSTALL_BIN_DIR)/relayStim
	cp $(BIN_DIR)/receiverSim $(INSTALL_BIN_DIR)/rly_receiverSim
	@$(DO_END)

#===================
#  i386
#===================
i386:
	make install ARCHFLAGS="-march=i386"
	@echo relay/test i386

