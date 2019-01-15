/************************************************************/
/*    NAME: handshane                                              */
/*    ORGN: MIT                                             */
/*    FILE: vehicle.h                                          */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#ifndef vehicle_HEADER
#define vehicle_HEADER

#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"

class vehicle : public AppCastingMOOSApp
{
 public:
   vehicle();
   ~vehicle();

 protected: // Standard MOOSApp functions to overload  
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();

 protected: // Standard AppCastingMOOSApp function to overload 
   bool buildReport();

 protected:
   void registerVariables();

 private: // Configuration variables
   int m_gps;
   int m_received;   
 private: // State variables
};

#endif 
