/************************************************************/
/*    NAME: handshane                                              */
/*    ORGN: MIT                                             */
/*    FILE: shoresideVehicle.h                                          */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#ifndef shoresideVehicle_HEADER
#define shoresideVehicle_HEADER

#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"

class shoresideVehicle : public AppCastingMOOSApp
{
 public:
   shoresideVehicle();
   ~shoresideVehicle();

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
   int m_received;
   int m_gps_number;
 private: // State variables
};

#endif 
