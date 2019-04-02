#=======================================================
#
# DESCRIPTION:	
# Makefile for softwareICs/relay/src tree.
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
# Revision 1.2  2009/04/14 16:18:59  bobfcsoft
# added i386 target
#
# Revision 1.1  2008/11/26 17:06:11  bobfcsoft
# new file
#
# Revision 1.2  2002/12/03 21:21:17  root
# v2.0 compatible
#
# Revision 1.1  2002/12/03 19:51:46  root
# Initial revision
#
#=======================================================
#
#=======================================================

SOFT_IC_DIR=../..
SIMPL_DIR=$(SIMPL_HOME)

CC=cc

PROGRAM_NAME=
line1 = --------------------------------------------------------------------

OBJ_DIR=obj
BIN_DIR=../bin
LIB_DIR=../lib

INSTALL_BIN_DIR=$(SOFT_IC_DIR)/bin
INSTALL_LIB_DIR=$(SOFT_IC_DIR)/lib

LOCAL_INCL_DIR=../include
SIMPL_INCL_DIR=$(SIMPL_DIR)/include

RELAY_OBJ=\
	$(OBJ_DIR)/relay.o\
	$(OBJ_DIR)/relayInit.o

CFLAGS=\
	-c\
	-g\
	-Wall\
        -I $(LOCAL_INCL_DIR)\
        -I $(SIMPL_INCL_DIR)

LDFLAGS=\
	-L $(SIMPL_DIR)/lib\
	-lsimplmisc\
	-lsimpllog\
	-lsimpl

ARCHFLAGS =

THIS_TARGET="starting"
DO_END=make -s title THIS_TARGET="<$@> done"

#========================
# Default targets
#========================
all:\
     title \
     $(OBJ_DIR) \
     $(BIN_DIR) \
     $(BIN_DIR)/relay
	@$(DO_END)

title:
	@echo "=============== relay/src $(THIS_TARGET) ================"

description:
	@(\
	echo;\
	echo "$(line1)";\
	echo "Compiling $(PROGRAM_NAME) -> $(OBJ_NAME)";\
	echo )

$(OBJ_DIR):
	mkdir obj
	chmod a+w obj

$(BIN_DIR):
	mkdir ../bin
	chmod a+w ../bin

$(LIB_DIR):
	mkdir ../lib
	chmod a+w ../lib

#========================
# Link
#========================
$(BIN_DIR)/relay:	$(RELAY_OBJ)
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) -o $(BIN_DIR)/relay $(RELAY_OBJ) $(LDFLAGS)

#===================
# Compiles
#===================
$(OBJ_DIR)/relay.o: relay.c
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) $(ARCHFLAGS) $(CFLAGS) -o $(OBJ_DIR)/relay.o relay.c

$(OBJ_DIR)/relayInit.o: relayInit.c
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) $(ARCHFLAGS) $(CFLAGS) -o $(OBJ_DIR)/relayInit.o relayInit.c

#===================
# Cleanup
#===================
clobber: clean
clean:
	@-rm -f $(OBJ_DIR)/*.o
	@-rm -f $(BIN_DIR)/relay
	@$(DO_END)

#===================
# Install
#===================
install:\
     title \
     $(OBJ_DIR) \
     $(BIN_DIR) \
     $(BIN_DIR)/relay
	cp $(BIN_DIR)/relay $(INSTALL_BIN_DIR)/relay
	@$(DO_END)

#===================
#  i386
#===================
i386:
	make install ARCHFLAGS="-march=i386"
	@echo relay i386

