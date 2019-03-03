#############################################################################
#
# Makefile - for nameServer/test
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
# Revision 1.1  2006/07/06 14:31:12  bobfcsoft
# seed code
#
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

NAME_STIM_OBJ=\
	$(OBJ_DIR)/nameStim.o\
	$(OBJ_DIR)/nameStimInit.o\
	$(OBJ_DIR)/nameStimUtils.o

CDFLAGS=\
	-c\
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
     $(BIN_DIR)/nameStim 
	@$(DO_END)

title:
	@echo "============== nameServer/test $(THIS_TARGET) ================"

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
$(BIN_DIR)/nameStim:	$(NAME_STIM_OBJ)
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) -o $(BIN_DIR)/nameStim $(NAME_STIM_OBJ) $(LDFLAGS)
	
#========================
# Compiles
#========================
$(OBJ_DIR)/nameStim.o: nameStim.c
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) $(CDFLAGS) -o $(OBJ_DIR)/nameStim.o nameStim.c

$(OBJ_DIR)/nameStimInit.o: nameStimInit.c
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) $(CDFLAGS) -o $(OBJ_DIR)/nameStimInit.o nameStimInit.c

$(OBJ_DIR)/nameStimUtils.o: nameStimUtils.c
	@make -s description PROGRAM_NAME="$<" OBJ_NAME="$@"
	$(CC) $(CDFLAGS) -o $(OBJ_DIR)/nameStimUtils.o nameStimUtils.c

#========================
# Cleanup
#========================
clobber:
	@-rm -f $(OBJ_DIR)/*.o
	@-rm -f $(BIN_DIR)/nameStim
	@$(DO_END)

#========================
# Install
#========================
install:\
     title \
     $(OBJ_DIR) \
     $(BIN_DIR) \
     $(BIN_DIR)/nameStim
	@$(DO_END)
