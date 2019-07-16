#--------------------------------------------------------
# The CMakeLists.txt for:                       pAngleDecision
# Author(s):                              Logan
#--------------------------------------------------------

SET(SRC
  AngleDecision.cpp
  AngleDecision_Info.cpp
  main.cpp
)

ADD_EXECUTABLE(pAngleDecision ${SRC})

TARGET_LINK_LIBRARIES(pAngleDecision
   ${MOOS_LIBRARIES}
   apputil
   mbutil
   m
   pthread)

