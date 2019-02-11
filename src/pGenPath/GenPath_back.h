/************************************************************/
/*    NAME: handshane                                              */
/*    ORGN: MIT                                             */
/*    FILE: GenPath.h                                          */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#ifndef GenPath_HEADER
#define GenPath_HEADER

#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"
#include <vector>
#include <list>
#include "MyData.h"

class GenPath : public AppCastingMOOSApp
{
 public:
   GenPath();
   ~GenPath();

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
	void getStartPos(); 
    std::list<MyData>::iterator GetMinDistance();
    void EraseNearbyPoint();
    void CheckIfArrived();
    void RePath();
 private: // Configuration variables
    std::list<MyData> m_input_list;
    
    std::string m_start_position;
    double m_start_x;
    double m_start_y;
    
    std::string m_update_str;    
    std::string m_return_done;

    std::list<double> m_x_list;
    std::list<double> m_y_list;
    double m_visit_radius;
    double m_nav_x;
    double m_nav_y;
    
    std::string m_deploy;
    std::string m_return;
    
    bool m_received;
    bool m_gen;
    
    double m_total_distance;
    int m_total_number;
    int m_visited_number;
    int m_beside_number;
    double m_count;  
    int c; 
    int a; 
 private: // State variables
};

#endif 
