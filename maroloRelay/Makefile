#=======================================================
#
# DESCRIPTION:	
# Makefile for softwareICs/relay tree.
#
# AUTHOR:	R.D. Findlay
#
#-------------------------
# FCsoftware Inc. 2000, 2008
# This code is released as open source.   You are free to
# use this code without restriction.  We hope you find 
# it useful.  If you discover a bug or add an enhancement 
# contact us on the: 
#
#	SIMPL mailing list
#-------------------------
#
# Revision history:
#=======================================================
# $Log: Makefile,v $
# Revision 1.1  2008/11/26 17:04:33  bobfcsoft
# new file
#
# Revision 1.1  2002/12/03 19:51:31  root
# Initial revision
#
#=======================================================

PROJECT=SIMPL
TASK=relay

SRC_DIR=src
TEST_DIR=test

#===================================
# entry point for simple make
#===================================
all:
	@echo "$(PROJECT) $(TASK) build <all> starting"
	@echo `date`
	@make -C $(SRC_DIR)
	@make -C $(TEST_DIR)
	@echo "$(PROJECT) $(TASK) <all> done"
	@echo `date`

#===================================
# to force a total rebuild
#===================================
clobber: clean
clean:
	@echo "$(PROJECT) $(TASK) <clobber> starting"
	@make -C $(SRC_DIR) -s clobber
	@make -C $(TEST_DIR) -s clobber
	@echo "$(PROJECT) $(TASK) <clobber> done"

#===================================
# to move into master area
#===================================
install:
	@echo "$(PROJECT) $(TASK) build <install> starting"
	@echo `date`
	@make -C $(SRC_DIR) install
	@make -C $(TEST_DIR) install
	@echo "$(PROJECT) $(TASK) <install> done"
	@echo `date`
