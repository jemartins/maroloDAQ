#!/usr/bin/wish 

##############################################################################
#
#    Copyright (C) 2006 DrDAQ Application Project.
#
#    This software is in the public domain.
#    Permission to use, copy, modify, and distribute this software and its
#    documentation for any purpose and without fee is hereby granted,
#    without any conditions or restrictions.
#    This software is provided "as is" without express or implied warranty.
#
#    If you discover a bug or add an enhancement here's how to reach us:
#
#        https://sourceforge.net/projects/drdaq
#
###############################################################################

#=============================================
# Revision history:
#
# $Log: guiStim.tcl,v $
# Revision 1.4  2007/06/01 17:10:54  jemartins
# added auto_path
#
# Revision 1.3  2006/05/17 21:24:07  jemartins
# added Copyright
#
# Revision 1.2  2006/04/27 19:00:39  jemartins
# *** empty log message ***
#
# Revision 1.1  2006/03/21 20:40:47  bobfcsoft
# guiStim.tcl added
#
#=============================================

set this "guiStim"

lappend auto_path $env(SIMPL_HOME)/lib
package require Fctclx

set f [frame .myArea -borderwidth 5 -width 400 -height 250]
set m [frame $f.main -width 400 -height 200]
set b [frame .bottomBar]

set MASK_MISC		1
set MASK_IO		2

set PICO_TOKEN(PICO_READING_START)	3
set PICO_TOKEN(PICO_READING_STOP)	4

set j	1
set pendingEventFrom	-1

#=============================================
# 	hndlMsg - entry point
#=============================================
proc hndlMsg {fromWhom msg} {
global forever
global reply
global this
global logger
global MASK_MISC
global logMask
global PICO_TOKEN
set fn hndlMsg


binary scan $msg i1 token

logit $logger $this $fn $MASK_MISC $logMask [format "token=0x%X fromWhom=%d" $token $fromWhom]


if { $token == $PICO_TOKEN(PICO_READING_STOP) } {
	Reply $fromWhom NULL 0
	logit $logger $this $fn $MASK_MISC $logMask [format "token=STOP(0x%X)" $token]
} else {
	puts stdout [format "token=0x%X unsupported" $token]
}

};#end hndlMsg

#=============================================
#	renderMain - entry point
#=============================================
proc renderMain { } {

global m
global b_c
set fn "renderMain"

label $m.for -text "This application was created for iCanProgram DrDAQ course"

label $m.by -text "by iCanProgram Inc."

place $m.for -x 10 -y 50
place $m.by -x 10 -y 80

button $m.hitme -text "Start measurements" -command hitMe 
place $m.hitme -x 170 -y 165

pack $m -fill both -expand true

putInfo [format "%s: done" $fn]

} ;# end renderMain

#=========================================
#	hitMe - entry point
#=========================================
proc hitMe { } {
global logger
global this
global MASK_MISC
global logMask
global picoMgrID
global PICO_TOKEN

set fn "hitMe"

logit $logger $this $fn $MASK_MISC $logMask [format "picoMgrID=%d" $picoMgrID ]

if { $picoMgrID != -1 } {

	set outMsg(token)  $PICO_TOKEN(PICO_READING_START)
	set outMsg(period) 10
	set outMsg(maxReadings)	100
	set outArea [binary format "i1i1i1"\
		$outMsg(token)\
		$outMsg(period)\
		$outMsg(maxReadings) ]
	set sbytes [string length $outArea]

	set inArea [Send $picoMgrID $outArea $sbytes]

	putInfo [format "START to %d period=%d msec max=%d" $picoMgrID $outMsg(period) $outMsg(maxReadings) ]

	}

};# end hitMe

#========================================
#	quitThis - entry point
#========================================
proc quitThis { } {
global logger
global this
global MASK_MISC
global logMask
global forever
set fn "quitThis"


set forever 1

};# end quitThis

#========================================
#	putInfo - entry point
#========================================
proc putInfo { infoText } {
global b

$b.info config -justify left -text $infoText -background lightblue

}; #end putInfo

#=============================================
#	doReceive - entry point
#=============================================
proc doReceive {} {
global j
global this
global logger
global MASK_MISC
global logMask
set fn doReceive

set buf [Receive]

binary scan $buf i1i1 fromWhom nbytes 
logit $logger $this $fn $MASK_MISC $logMask [format "received %d bytes from %d" $nbytes $fromWhom]
	
binary scan $buf x8a$nbytes msg 
hndlMsg $fromWhom $msg

};# end doReceive

#================================================
#	main - entry point
#================================================
set fn main
set logMask 0xff
set loggerName ""
set picoMgrName ""

set state flag
foreach arg $argv {
	switch -- $state {
		flag {
			switch -glob -- $arg {
				-N	{ set state name }
				-p	{ set state pico }
				-m	{ set state mask }
				-l	{ set state logger }
				default { error "unknown flag $arg"}
			}
		}
		
		name {
			set myName $arg
			set state flag
		}

		pico {
			set picoMgrName $arg
			set state flag
		}

		mask {
			set logMask $arg
			set state flag
		}

		logger {
			set loggerName $arg
			set state flag
		}
	};# end switch state
};# end foreach

set myslot [name_attach $myName 2048]
catch {puts stdout [format "myName=<%s> myslot=%d" $myName $myslot]}

if { $loggerName == "" } {
	set logger -1
} else {
	set logger [name_locate "LOGGER"]
}

if { $picoMgrName == "" } {
	set picoMgrID -1
} else {
	set picoMgrID [name_locate $picoMgrName]
	}

set myFifo [ format "%s/%s" $env(FIFO_PATH) $myslot ]
set recvid [ open $myFifo {RDWR}]

logit $logger $this $fn $MASK_MISC $logMask [format "myName=<%s> myslot=%s" $myName $myslot]
logit $logger $this $fn $MASK_MISC $logMask [format "loggerName=<%s> id=%d" $loggerName $logger]
logit $logger $this $fn $MASK_MISC $logMask [format "logMask=%X" $logMask]
logit $logger $this $fn $MASK_MISC $logMask [format "myFifo=<%s> fd=<%s>" $myFifo $recvid]

button $b.quit -text "quit" -command quitThis
pack $b.quit -side right

label $b.info -width 50 -relief groove -borderwidth 5 -justify left
pack $b.info -side left

pack $b -side bottom -fill x

renderMain

pack $f -side top -expand true -fill both

putInfo [format "myName=<%s> myslot=%s" $myName $myslot]

fileevent $recvid readable doReceive
vwait forever

name_detach

puts stdout {done}

exit
