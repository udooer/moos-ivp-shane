#--------------------------------------------------------
# The CMakeLists.txt for:                       pNumberCal
# Author(s):                              handsomeshane
#--------------------------------------------------------

SET(SRC
  NumberCal.cpp
  NumberCal_Info.cpp
  main.cpp
  MyData.cpp
)

ADD_EXECUTABLE(pNumberCal ${SRC})

TARGET_LINK_LIBRARIES(pNumberCal
   ${MOOS_LIBRARIES}
   apputil
   mbutil
   m
   pthread)

