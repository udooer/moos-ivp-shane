/************************************************************/
/*    NAME: Shane                                              */
/*    ORGN: MIT                                             */
/*    FILE: AngleEstimate.h                                          */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#ifndef AngleEstimate_HEADER
#define AngleEstimate_HEADER

#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"
#include "XYPointV2.h"
class AngleEstimate : public AppCastingMOOSApp
{
 public:
   AngleEstimate();
   ~AngleEstimate();

 protected: // Standard MOOSApp functions to overload  
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();

 protected: // Standard AppCastingMOOSApp function to overload 
   bool buildReport();

 protected:
   void registerVariables();
   void dataProcessing(std::string);
   void decode(std::string);
   void deletePoint();
 private: // Configuration variables

 private: // State variables
   struct WFD{
    std::string vname;
    double x;
    double y;
    double temp;
   };
   std::vector<WFD> m_collected_data;
   struct points{
    double theta = 0;
    double x1 = 0;
    double x2 = 0;
    double y1 = 0;
    double y2 = 0;
    double weight = 0;
   };
   std::vector<points> m_points;
   std::string m_node;

   XYPointV2 m_P_A;
   XYPointV2 m_P_B;
};

#endif 
