#############################################################################
# FILE:        moos-ivp-extend/src/CMakeLists.txt
# DATE:        2010/09/07
# DESCRIPTION: CMakeLists.txt file for the moos-ivp-extend source directory
##############################################################################


#============================================================================
# Add the libraries in the current directory to the include path
#============================================================================
FILE(GLOB LOCAL_LIBRARY_DIRS ./lib_*)
INCLUDE_DIRECTORIES(${LOCAL_LIBRARY_DIRS})

#============================================================================
# List the subdirectories to build...
#============================================================================
ADD_SUBDIRECTORY(lib_behaviors-test)
ADD_SUBDIRECTORY(lib_behaviors-shane)
ADD_SUBDIRECTORY(pXRelayTest)
ADD_SUBDIRECTORY(pExampleApp)
ADD_SUBDIRECTORY(pOdometry)
ADD_SUBDIRECTORY(test/pTest)
ADD_SUBDIRECTORY(test/pshoresideVehicle)
ADD_SUBDIRECTORY(test/pNewmailIterate)
ADD_SUBDIRECTORY(test/pvehicle)
ADD_SUBDIRECTORY(pPrimeFactor)
ADD_SUBDIRECTORY(pNumberCal)
ADD_SUBDIRECTORY(pChirp)
ADD_SUBDIRECTORY(pPointAssign)
ADD_SUBDIRECTORY(pGenPath)
ADD_SUBDIRECTORY(pController)
ADD_SUBDIRECTORY(uFldHazardMgrX)
ADD_SUBDIRECTORY(pAngleEstimate)
ADD_SUBDIRECTORY(pAngleDecision)
#ADD_SUBDIRECTORY(pFoobar)
#ADD_SUBDIRECTORY(pOdometry)

##############################################################################
#                           END of CMakeLists.txt
##############################################################################

