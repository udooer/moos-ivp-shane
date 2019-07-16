#--------------------------------------------------------
# The CMakeLists.txt for:                       pAngleEstimate
# Author(s):                              Shane
#--------------------------------------------------------

SET(SRC
  AngleEstimate.cpp
  AngleEstimate_Info.cpp
  main.cpp
  XYPointV2.cpp
)

ADD_EXECUTABLE(pAngleEstimate ${SRC})

TARGET_LINK_LIBRARIES(pAngleEstimate
   ${MOOS_LIBRARIES}
   apputil
   mbutil
   m
   pthread)

