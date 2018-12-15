#!/bin/bash
###########################
#
# Launch file (maybe not right)
#
#######################
pAntler alpha.moos --MOOSTimeWarp=10 &
pAntler bravo.moos --MOOSTimeWarp=10 &
pAntler shoreside.moos --MOOSTimeWarp=10
exit 0
