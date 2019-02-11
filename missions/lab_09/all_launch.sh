#!/bin/bash
TIME_WARP=1
for ARGI; do
    if [ "${ARGI}" = "--help" -o "${ARGI}" = "-h" ] ; then
        printf "%s [SWITCHES] [time_warp]   \n" $0
        printf "  --help, -h         \n"
        exit 0;
    elif [ "${ARGI//[^0-9]/}" = "$ARGI" -a "$TIME_WARP" = 1 ]; then
        TIME_WARP=$ARGI
    else
        printf "Bad Argument: %s \n" $ARGI
        exit 0
    fi
done


pAntler shor.moos --MOOSTimeWarp=$TIME_WARP >& /dev/null &
pAntler shane.moos --MOOSTimeWarp=$TIME_WARP >& /dev/null &
pAntler henry.moos --MOOSTimeWarp=$TIME_WARP >& /dev/null &

uMAC shor.moos
printf "Killing all processes ... \n"
kill %1 %2 %3
printf "Done killing processes.   \n"

