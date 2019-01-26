/************************************************************/
/*    NAME: handshane                                              */
/*    ORGN: MIT                                             */
/*    FILE: PointAssign.h                                          */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#ifndef PointAssign_HEADER
#define PointAssign_HEADER

#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"

class PointAssign : public AppCastingMOOSApp
{
 public:
   PointAssign();
   ~PointAssign();

 protected: // Standard MOOSApp functions to overload  
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();

 protected: // Standard AppCastingMOOSApp function to overload 
   bool buildReport();

 protected:
   void registerVariables();
 
 protected:
    void cutString();
    void separate_points_by_half_x();   
 private: // Configuration variables
    std::string m_vname;
    std::vector<std::string> m_v_vector;
    std::string m_assign_by_region;
    std::list<std::string> m_coordinate_list;
    bool m_done;
    std::vector<int> m_left_index;
    std::vector<int> m_right_index;
 private: // State variables
};

#endif 
