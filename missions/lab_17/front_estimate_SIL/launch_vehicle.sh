#!/bin/bash 
#-------------------------------------------------------
#  Part 1: Check for and handle command-line arguments
#-------------------------------------------------------
SHORE_IP="192.168.1.217"
TIME_WARP=1
JUST_MAKE="no"
VNAME="archie"
COOL_FAC=50
COOL_STEPS=1000
CONCURRENT="true"
ADAPTIVE="false"

SURVEY_X=70
SURVEY_Y=-100
HEIGHT1=150
WIDTH1=120
LANE_WIDTH1=25
DEGREES1=270

for ARGI; do
    if [ "${ARGI}" = "--help" -o "${ARGI}" = "-h" ] ; then
	printf "%s [SWITCHES] [time_warp]   \n" $0
	printf "  --just_make, -j    \n" 
	printf "  --vname=VNAME      \n" 
	printf "  --help, -h         \n"
	printf "  --warp=WARP_VALUE      \n"
	printf "  --adaptive, -a         \n"
	printf "  --unconcurrent, -uc       \n"
	printf "  --angle=DEGREE_VALUE   \n"
	printf "  --cool=COOL_FAC        \n"
	exit 0;
    elif [ "${ARGI:0:8}" = "--vname=" ] ; then
        VNAME="${ARGI#--vname=*}"
    elif [ "${ARGI//[^0-9]/}" = "$ARGI" -a "$TIME_WARP" = 1 ]; then 
        TIME_WARP=$ARGI
    elif [ "${ARGI}" = "--just_build" -o "${ARGI}" = "-j" ] ; then
	JUST_MAKE="yes"
    elif [ "${ARGI:0:6}" = "--warp" ] ; then
        WARP="${ARGI#--warp=*}"
        UNDEFINED_ARG=""
    elif [ "${ARGI:0:6}" = "--cool" ] ; then
        COOL_FAC="${ARGI#--cool=*}"
        UNDEFINED_ARG=""
    elif [ "${ARGI:0:7}" = "--angle" ] ; then
        DEGREES1="${ARGI#--angle=*}"
        UNDEFINED_ARG=""
    elif [ "${ARGI}" = "--unconcurrent" -o "${ARGI}" = "-uc" ] ; then
        CONCURRENT="false"
        UNDEFINED_ARG=""
    elif [ "${ARGI}" = "--adaptive" -o "${ARGI}" = "-a" ] ; then
        ADAPTIVE="true"
        UNDEFINED_ARG=""
    elif [ ${ARGI} = "-a" ] ; then
        SIM="yes"

    else 
	printf "Bad Argument: %s \n" $ARGI
	exit 0
    fi
done

#-------------------------------------------------------
#  Part 2: Create the .moos and .bhv files. 
#-------------------------------------------------------
if [ ${VNAME} = "ALPHA" ] ; then
    START_POS="0,0"
    CLOCK="false"
    EXCHANGE="20,-50"
    CENTER_X="39"
    CENTER_Y="-108"

elif [ ${VNAME} = "BRAVO" ] ; then
    START_POS="9,5"
    CLOCK="false"
    EXCHANGE="45,-18"
    CENTER_X="85"
    CENTER_Y="-95"
fi



#start vehicle:                                                                                                                                                                                                                         
nsplug meta_vehicle.moos targ_$VNAME.moos -f WARP=$TIME_WARP  \
   VNAME=$VNAME      START_POS=$START_POS                    \
   VPORT="9001"       SHARE_LISTEN="9301"                      \
   VTYPE=UUV          COOL_FAC=$COOL_FAC  COOL_STEPS=$COOL_STEPS\
   CONCURRENT=$CONCURRENT  ADAPTIVE=$ADAPTIVE SHORE_IP=$SHORE_IP\
   SIM=$SIM

nsplug meta_vehicle.bhv targ_$VNAME.bhv -f VNAME=$VNAME      \
    START_POS=$START_POS SURVEY_X=$SURVEY_X SURVEY_Y=$SURVEY_Y \
    HEIGHT=$HEIGHT1   WIDTH=$WIDTH1 LANE_WIDTH=$LANE_WIDTH1 \
    DEGREES=$DEGREES1 CLOCK=$CLOCK CENTER_X=$CENTER_X \
    CENTER_Y=$CENTER_Y EXCHANGE_POS=$EXCHANGE


if [ ${JUST_MAKE} = "yes" ] ; then
    exit 0
fi

#-------------------------------------------------------
#  Part 3: Launch the processes
#-------------------------------------------------------
printf "Launching $VNAME MOOS Community (WARP=%s) \n" $TIME_WARP
pAntler targ_$VNAME.moos >& /dev/null &

uMAC targ_$VNAME.moos

kill %1 
printf "Done.   \n"


