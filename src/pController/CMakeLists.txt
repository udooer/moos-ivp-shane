#--------------------------------------------------------
# The CMakeLists.txt for:                       pController
# Author(s):                              shane
#--------------------------------------------------------

SET(SRC
  Controller.cpp
  Controller_Info.cpp
  main.cpp
  PID.cpp
)

ADD_EXECUTABLE(pController ${SRC})

TARGET_LINK_LIBRARIES(pController
   ${MOOS_LIBRARIES}
   apputil
   mbutil
   m
   pthread)

