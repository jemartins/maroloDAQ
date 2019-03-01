#############################################################################
#
#	This software was developed for
#	iCanProgram Inc., Toronto, Canada
#
# Makefile - for mypico/picoMgr/test
#
##############################################################################

##############################################################################
#
#    Copyright (C) 2006 DrDAQ Application Project.
#
#    This software is in the public domain.
#    Permission to use, copy, modify, and distribute this software and its
#    #    documentation for any purpose and without fee is hereby granted,
#    without any conditions or restrictions.
#    #    This software is provided "as is" without express or implied warranty.
#
#    If you discover a bug or add an enhancement here's how to reach us:
#
#        https://sourceforge.net/projects/drdaq
#
###############################################################################

###############################################################################
# Revision History:
# 
# $Log: Makefile,v $
# Revision 1.6  2006/06/25 14:01:40  jemartins
# *** empty log message ***
#
# Revision 1.5  2006/06/24 15:38:24  jemartins
# added myID
#
# Revision 1.4  2006/05/17 21:24:07  jemartins
# added Copyright
#
# Revision 1.3  2006/05/01 12:37:31  bobfcsoft
# cleanup
#
# Revision 1.2  2006/03/20 22:38:00  bobfcsoft
# added START logic
#
# Revision 1.1.1.1  2006/03/07 21:29:47  bobfcsoft
# startup
#
###############################################################################

SIMPL_DIR=$(SIMPL_HOME)

CC=cc

PROGRAM_NAME=
line1 = --------------------------------------------------------------------

OBJ_DIR=obj
BIN_DIR=../bin
LIB_DIR=../lib

LOCAL_INCL_DIR=../include
INCL_DIR=../../include
SIMPL_INCL_DIR=$(SIMPL_DIR)/include

PICO_STIM_OBJ=\
	$(OBJ_DIR)/picoStim.o\
	$(OBJ_DIR)/picoStimInit.o\
	$(OBJ_DIR)/picoStimUtils.o

AUTO_STIM_OBJ=\
	$(OBJ_DIR)/autoStim.o\
	$(OBJ_DIR)/picoStimInit.o\
	$(OBJ_DIR)/picoStimUtils.o

GUI_STIM_OBJ=\
	$(OBJ_DIR)/guiStim.o\
	$(OBJ_DIR)/guiStimInit.o\
	$(OBJ_DIR)/guiStimUtils.o

AUTOGUI_STIM_OBJ=\
	$(OBJ_DIR)/autoguiStim.o\
	$(OBJ_DIR)/guiStimInit.o\
	$(OBJ_DIR)/guiStimUtils.o

CDFLAGS=\
	-c\
	-g\
	-Wall\
        -I $(LOCAL_INCL_DIR)\
        -I $(INCL_DIR)\
        -I $(SIMPL_INCL_DIR)

LDFLAGS=\
	-L $(SIMPL_DIR)/lib\
	-lsimpllog\
	-lsimpl\
	-lsimplmisc

THIS_TARGET="starting"
DO_END=make -s title THIS_TARGET="<$@> done"

#========================
# Default targets
#========================
all:\
     title \
     $(OBJ_DIR) \
     $(BIN_DIR) \
     $(BIN_DIR)/picoStim \
     $(BIN_DIR)/autoStim \
     $(BIN_DIR)/guiStim \
     $(BIN_DIR)/autoguiStim 
	@$(DO_END)

title:
	@echo "============== picoMgr/test $(THIS_TARGET) ================"

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

#========================
# Link
#========================
$(BIN_DIR)/picoStim:	$(PICO_STIM_OBJ)
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) -o $(BIN_DIR)/picoStim $(PICO_STIM_OBJ) $(LDFLAGS)
	
$(BIN_DIR)/autoStim:	$(AUTO_STIM_OBJ)
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) -o $(BIN_DIR)/autoStim $(AUTO_STIM_OBJ) $(LDFLAGS)
	
$(BIN_DIR)/guiStim:	$(GUI_STIM_OBJ)
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) -o $(BIN_DIR)/guiStim $(GUI_STIM_OBJ) $(LDFLAGS)
	
$(BIN_DIR)/autoguiStim:	$(AUTOGUI_STIM_OBJ)
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) -o $(BIN_DIR)/autoguiStim $(AUTOGUI_STIM_OBJ) $(LDFLAGS)
	
#========================
# Compiles
#========================
$(OBJ_DIR)/picoStim.o: picoStim.c
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) $(CDFLAGS) -o $(OBJ_DIR)/picoStim.o picoStim.c

$(OBJ_DIR)/autoStim.o: autoStim.c
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) $(CDFLAGS) -o $(OBJ_DIR)/autoStim.o autoStim.c

$(OBJ_DIR)/picoStimInit.o: picoStimInit.c
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) $(CDFLAGS) -o $(OBJ_DIR)/picoStimInit.o picoStimInit.c

$(OBJ_DIR)/picoStimUtils.o: picoStimUtils.c
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) $(CDFLAGS) -o $(OBJ_DIR)/picoStimUtils.o picoStimUtils.c

$(OBJ_DIR)/guiStim.o: guiStim.c
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) $(CDFLAGS) -o $(OBJ_DIR)/guiStim.o guiStim.c

$(OBJ_DIR)/autoguiStim.o: autoguiStim.c
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) $(CDFLAGS) -o $(OBJ_DIR)/autoguiStim.o autoguiStim.c

$(OBJ_DIR)/guiStimInit.o: guiStimInit.c
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) $(CDFLAGS) -o $(OBJ_DIR)/guiStimInit.o guiStimInit.c

$(OBJ_DIR)/guiStimUtils.o: guiStimUtils.c
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) $(CDFLAGS) -o $(OBJ_DIR)/guiStimUtils.o guiStimUtils.c

#========================
# Cleanup
#========================
clobber:
	@-rm -f $(OBJ_DIR)/*.o
	@-rm -f $(BIN_DIR)/picoStim
	@-rm -f $(BIN_DIR)/autoStim
	@-rm -f $(BIN_DIR)/guiStim
	@-rm -f $(BIN_DIR)/autoguiStim
	@$(DO_END)

#========================
# Install
#========================
install:\
     title \
     $(OBJ_DIR) \
     $(BIN_DIR) \
     $(BIN_DIR)/picoStim \
     $(BIN_DIR)/guiStim
	@$(DO_END)
