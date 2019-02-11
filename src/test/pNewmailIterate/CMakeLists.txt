#--------------------------------------------------------
# The CMakeLists.txt for:                       pNewmailIterate
# Author(s):                              
#--------------------------------------------------------

SET(SRC
  NewmailIterate.cpp
  NewmailIterate_Info.cpp
  main.cpp
)

ADD_EXECUTABLE(pNewmailIterate ${SRC})

TARGET_LINK_LIBRARIES(pNewmailIterate
   ${MOOS_LIBRARIES}
   apputil
   mbutil
   m
   pthread)

