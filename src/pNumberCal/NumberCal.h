/************************************************************/
/*    NAME: handsomeshane                                              */
/*    ORGN: MIT                                             */
/*    FILE: NumberCal.h                                          */
/*    DATE: Octobor 28th, 2018                             */
/************************************************************/

#ifndef NumberCal_HEADER
#define NumberCal_HEADER

#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"
#include <list>
#include "MyData.h"

class NumberCal : public AppCastingMOOSApp
{
 public:
   NumberCal();
   ~NumberCal();

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
    int m_container;

 private: // State variables
    std::list<MyData> m_input_buf_list;
};

#endif 
