/************************************************************/
/*    NAME: shane                                              */
/*    ORGN: MIT                                             */
/*    FILE: BHV_Polygon.h                                      */
/*    DATE:                                                 */
/************************************************************/

#ifndef Polygon_HEADER
#define Polygon_HEADER

#include <string>
#include "IvPBehavior.h"
#include "XYPoint.h"

class BHV_Polygon : public IvPBehavior {
public:
  BHV_Polygon(IvPDomain);
  ~BHV_Polygon() {};
  
  bool         setParam(std::string, std::string);
  void         onSetParamComplete();
  void         onCompleteState();
  void         onIdleState();
  void         onHelmStart();
  void         postConfigStatus();
  void         onRunToIdleState();
  void         onIdleToRunState();
  IvPFunction* onRunState();

protected: // Local Utility functions
  void decode();
  void postViewPoint();
  std::vector<double> getDiscretex();
  std::vector<double> getDiscretey();
  IvPFunction* buildFunctionWithZAIC();
protected: // Configuration parameters
  std::string m_path;
  std::string m_polygon;
  double m_center_x;
  double m_center_y;
  double m_radius;

  double m_start_x;
  double m_start_y;
  double m_omega;
  double m_amplitude;
  double m_desired_speed;
  double m_arrival_radius;

  char m_char;
  XYPoint point;
  std::vector<double> x_point;
  std::vector<double> y_point;
  int m_index;

protected: // State variables
  double m_osx;
  double m_osy;
};

#define IVP_EXPORT_FUNCTION

extern "C" {
  IVP_EXPORT_FUNCTION IvPBehavior * createBehavior(std::string name, IvPDomain domain) 
  {return new BHV_Polygon(domain);}
}
#endif
