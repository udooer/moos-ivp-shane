#--------------------------------------------------------
# The CMakeLists.txt for:                       pshoresideVehicle
# Author(s):                              handshane
#--------------------------------------------------------

SET(SRC
  shoresideVehicle.cpp
  shoresideVehicle_Info.cpp
  main.cpp
)

ADD_EXECUTABLE(pshoresideVehicle ${SRC})

TARGET_LINK_LIBRARIES(pshoresideVehicle
   ${MOOS_LIBRARIES}
   apputil
   mbutil
   m
   pthread)

