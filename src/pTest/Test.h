/************************************************************/
/*    NAME: handsomeshane                                              */
/*    ORGN: MIT                                             */
/*    FILE: Test.h                                          */
/*    DATE:                                                 */
/************************************************************/

#ifndef Test_HEADER
#define Test_HEADER

#include "MOOS/libMOOS/MOOSLib.h"

class Test : public CMOOSApp
{
  double k;
  double l;
  int count;
  int count_2;
 public:
   Test();
   ~Test();

 protected: // Standard MOOSApp functions to overload  
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();

 protected:
   void RegisterVariables();

 private: // Configuration variables

 private: // State variables
};

#endif 
