/************************************************************/
/*    NAME:                                               */
/*    ORGN: MIT                                             */
/*    FILE: NewmailIterate.h                                          */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#ifndef NewmailIterate_HEADER
#define NewmailIterate_HEADER

#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"

class NewmailIterate : public AppCastingMOOSApp
{
 public:
   NewmailIterate();
   ~NewmailIterate();

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
    int m_count_i;
    int m_count_o;
 private: // State variables
};

#endif 
