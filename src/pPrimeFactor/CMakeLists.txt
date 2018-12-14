#--------------------------------------------------------
# The CMakeLists.txt for:                 pPrimeFactor
# Author(s):                              handsomeshane
#--------------------------------------------------------

SET(SRC
  PrimeFactor.cpp
  PrimeFactor_Info.cpp
  main.cpp
  MyData.cpp
)

ADD_EXECUTABLE(pPrimeFactor ${SRC})

TARGET_LINK_LIBRARIES(pPrimeFactor
   ${MOOS_LIBRARIES}
   apputil
   mbutil
   m
   pthread)

