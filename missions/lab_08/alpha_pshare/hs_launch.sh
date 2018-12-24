#!/bin/bash
###########################
#
# Launch file
#
#######################

#-----------------------------------------------------
# Part 1: check for and handle command-line arguments
#------------------------------------------------------
TIME_WARP=1

for ARGI;do
    if [ $ARGI = "--help" -o $ARGI = "-h" ];then
        printf "%s time_warp_change\n" $0
        exit 0;
    elif [ "${ARGI//[^0-9]/}" = "$ARGI" -a $TIME_WARP = 1 ];then 
        TIME_WARP=$ARGI
    else
        printf "Bad Argument %s\n" $ARGI
        printf "./hs_launch.sh --help\n"
        exit 0;
    fi
done
#------------------------------------------------------
# Part 2: Launch the processes
#-----------------------------------------------------

pAntler alpha.moos --MOOSTimeWarp=$TIME_WARP &> /dev/null &
pAntler bravo.moos --MOOSTimeWarp=$TIME_WARP &> /dev/null &
pAntler shoreside.moos --MOOSTimeWarp=$TIME_WARP &> /dev/null &
printf "Done\n"

#-----------------------------------------------------------
# Part 3: Launch uMAC and kill everything upon exiting uMAC
#-----------------------------------------------------------
uMAC shoreside.moos
printf "killing all processes ...\n"
kill %1 %2 %3
printf "Done killing processes.\n"
