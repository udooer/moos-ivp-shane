#--------------------------------------------------------
# The CMakeLists.txt for:                       pvehicle
# Author(s):                              handshane
#--------------------------------------------------------

SET(SRC
  vehicle.cpp
  vehicle_Info.cpp
  main.cpp
)

ADD_EXECUTABLE(pvehicle ${SRC})

TARGET_LINK_LIBRARIES(pvehicle
   ${MOOS_LIBRARIES}
   apputil
   mbutil
   m
   pthread)

