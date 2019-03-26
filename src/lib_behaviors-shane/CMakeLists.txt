#--------------------------------------------------------
# The CMakeLists.txt for:              lib_behaviors-test
# Author(s):                                
#--------------------------------------------------------

# Set System Specific Libraries
if (${WIN32})
  # Windows Libraries
  SET(SYSTEM_LIBS
      )
else (${WIN32})
  # Linux and Apple Libraries
  SET(SYSTEM_LIBS
      m )
endif (${WIN32})


MACRO(ADD_BHV BHV_NAME)
  ADD_LIBRARY(${BHV_NAME} SHARED ${BHV_NAME}.cpp)
  TARGET_LINK_LIBRARIES(${BHV_NAME} 
    helmivp
    behaviors 
    ivpbuild 
    logic 
    ivpcore 
    bhvutil 
    mbutil 
    geometry 
    ${SYSTEM_LIBS} )
ENDMACRO(ADD_BHV)

##example behavior
  ADD_LIBRARY(BHV_example SHARED BHV_example.cpp)
  TARGET_LINK_LIBRARIES(BHV_example 
    helmivp
    behaviors 
    ivpbuild 
    logic 
    ivpcore 
    bhvutil 
    mbutil 
    geometry 
    ${SYSTEM_LIBS} )
##--------------------------------------------------------
## Pulse behavior
##--------------------------------------------------------
  ADD_LIBRARY(BHV_Pulse SHARED BHV_Pulse.cpp)
  TARGET_LINK_LIBRARIES(BHV_Pulse 
    helmivp
    behaviors 
    ivpbuild 
    logic 
    ivpcore 
    bhvutil 
    mbutil 
    geometry 
    ${SYSTEM_LIBS} )

##--------------------------------------------------------
##  ZigLeg behavior
##--------------------------------------------------------
  ADD_LIBRARY(BHV_ZigLeg SHARED BHV_ZigLeg.cpp)
  TARGET_LINK_LIBRARIES(BHV_ZigLeg 
    helmivp
    behaviors 
    ivpbuild 
    logic 
    ivpcore 
    bhvutil 
    mbutil 
    geometry 
    ${SYSTEM_LIBS} )

##--------------------------------------------------------
## BHV_Polygon
##--------------------------------------------------------
  ADD_LIBRARY(BHV_Polygon SHARED BHV_Polygon.cpp)
  TARGET_LINK_LIBRARIES(BHV_Polygon 
    helmivp
    behaviors 
    ivpbuild 
    logic 
    ivpcore 
    bhvutil 
    mbutil 
    geometry 
    ${SYSTEM_LIBS} )

##--------------------------------------------------------
##                                      BHV_SimpleWaypoint
##--------------------------------------------------------
#ADD_LIBRARY(BHV_SimpleWaypoint SHARED 
#   BHV_SimpleWaypoint.cpp AOF_SimpleWaypoint.cpp)
#TARGET_LINK_LIBRARIES(BHV_SimpleWaypoint
#   helmivp
#   behaviors 
#   ivpbuild 
#   logic 
#   ivpcore 
#   bhvutil 
#   mbutil 
#   geometry 
#   ${SYSTEM_LIBS} )
