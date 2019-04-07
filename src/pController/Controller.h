/************************************************************/
/*    NAME: shane                                              */
/*    ORGN: MIT                                             */
/*    FILE: Controller.h                                          */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#ifndef Controller_HEADER
#define Controller_HEADER

#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"
#include "PID.h"

class Controller : public AppCastingMOOSApp
{
 public:
   Controller();
   ~Controller();

 protected: // Standard MOOSApp functions to overload  
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();

 protected: // Standard AppCastingMOOSApp function to overload 
   bool buildReport();

 protected:
   void registerVariables();

 public:
   void sleepInSecond(clock_t, double);
 private: // Configuration variables
   double m_kp;
   double m_ki;
   double m_kd;
   double m_min;
   double m_max;

 private: // State variables
   double m_desired_heading;
   double m_my_heading;
   double m_first_exe;
   PID m_pid;
};

#endif 
