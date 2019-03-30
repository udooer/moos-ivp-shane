#!/bin/bash
#--------------------------------------------------------------
# Part 1: Check for and handle command-line arguments
#--------------------------------------------------------------

TIME_WARP=1
JUST_MAKE=no
MAKE_CHIRP=no
SIM=yes

for ARGI in $@; do 
#    if [ $GET_VNAME == "yes" ]; then 
#        VNAME=$ARGI
#        GET_VNAME=no
    if [ $ARGI == "--help" -o $ARGI == "-h" ]; then
        echo "$0 [SWITCHES] [time_warp]"
        echo "--just_make, -j"
        echo "--sim, -s"
        echo "--chirp, -c"
#        echo "-v VNAME"
        echo "--help, -h"
        exit 0
    elif [ $ARGI == "${ARGI//[^0-9]/}" -a $TIME_WARP == 1 ]; then
        TIME_WARP=$ARGI
    elif [ $ARGI == "--just_build" -o $ARGI == "-j" ]; then
        JUST_MAKE=yes
    elif [ $ARGI == "--sim" -o $ARGI == "-s" ]; then
        SIM=yes
    elif [ $ARGI == "--chirp" -o $ARGI == "-c" ]; then
        MAKE_CHIRP=yes   
#    elif [ $ARGI == "-v" ]; then
#        GET_VNAME=yes
    else 
        echo "Bad Argument: $ARGI"
        exit 0
    fi
done

#--------------------------------------------------------------
# Part 2: Create the .moos and .bhv files.
#--------------------------------------------------------------
# vehicle.moos

VNAME1=SHANE
VPORT1=9001
SHARE_LISTEN1="localhost:9301"
SIM_START_X1=0
SIM_START_Y1=-20

VNAME2=HENRY
VPORT2=9002
SHARE_LISTEN2="localhost:9302"
SIM_START_X2=30
SIM_START_Y2=-20

# shorside.moos
SHORESIDE=SHORESIDE
VPORT_S=9000
SHORE_LISTEN="localhost:9300"

#--------------------------------------------------------------
# .bhv
TIMER=180
SINE_START_X=40
SINE_START_Y=-30
OMEGA=0.02
AMPLITUDE=10
CENTER_X=30
CENTER_Y=-50
RADIUS=20

LEFT1=true
RIGHT1=false

LEFT2=false
RIGHT2=true
#--------------------------------------------------------------
# make targ moos file
nsplug meta_vehicle.moos targ_$VNAME1.moos -f WARP=$TIME_WARP \
    VNAME=$VNAME1 START_X=$SIM_START_X1 START_Y=$SIM_START_Y1  \
    VPORT=$VPORT1 SHARE_LISTEN=$SHARE_LISTEN1 SHORE_LISTEN=$SHORE_LISTEN \
    SIM=$SIM 

nsplug meta_vehicle.moos targ_$VNAME2.moos -f WARP=$TIME_WARP \
    VNAME=$VNAME2 START_X=$SIM_START_X2 START_Y=$SIM_START_Y2  \
    VPORT=$VPORT2 SHARE_LISTEN=$SHARE_LISTEN2 SHORE_LISTEN=$SHORE_LISTEN \
    SIM=$SIM 

nsplug meta_shoreside.moos targ_$SHORESIDE.moos -f WARP=$TIME_WARP \
    SHORESIDE=$SHORESIDE VPORT=$VPORT_S SHORE_LISTEN=$SHORE_LISTEN
#--------------------------------------------------------------
# make targ bhv file
nsplug meta_vehicle.bhv targ_$VNAME1.bhv -f LEFT=$LEFT1 RIGHT=$RIGHT1 \
    TIMER=$TIMER CENTER_X=$CENTER_X CENTER_Y=$CENTER_Y RADIUS=$RADIUS \
    START_X=$SINE_START_X START_Y=$SINE_START_Y OMEGA=$OMEGA AMPLITUDE=$AMPLITUDE \
    VNAME=$VNAME1 DEST_NODE=$VNAME2

nsplug meta_vehicle.bhv targ_$VNAME2.bhv -f LEFT=$LEFT2 RIGHT=$RIGHT2 \
    TIMER=$TIMER CENTER_X=$CENTER_X CENTER_Y=$CENTER_Y RADIUS=$RADIUS \
    START_X=$SINE_START_X START_Y=$SINE_START_Y OMEGA=$OMEGA AMPLITUDE=$AMPLITUDE \
    VNAME=$VNAME2 DEST_NODE=$VNAME1

if [ $JUST_MAKE == "yes" ]; then
    exit 0
fi

if [ $MAKE_CHIRP == "yes" ]; then
    echo "not finish yet"
fi

#--------------------------------------------------------------
# Part 3: Launch the process
#--------------------------------------------------------------
echo "Launching $VNAME1 MOOS Community (WARP=$TIME_WARP)"
pAntler targ_$VNAME1.moos >& /dev/null &
echo "Launching $VNAME2 MOOS Community (WARP=$TIME_WARP)" 
pAntler targ_$VNAME2.moos >& /dev/null &
echo "Launching $SHORESIDE MOOS Community (WARP=$TIME_WARP)"
pAntler targ_$SHORESIDE.moos >& /dev/null &
echo "Done"

#--------------------------------------------------------------
# Part 4: Launch uMAC and kill everything upon exiting uMAC
#--------------------------------------------------------------
uMAC targ_$SHORESIDE.moos
echo "killing all processes ..."
kill %1 %2 %3
echo "Done Killing processes."





