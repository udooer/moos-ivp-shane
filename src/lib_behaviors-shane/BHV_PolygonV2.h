/************************************************************/
/*    NAME: Shane                                              */
/*    ORGN: MIT                                             */
/*    FILE: BHV_PolygonV2.h                                      */
/*    DATE:                                                 */
/************************************************************/

#ifndef PolygonV2_HEADER
#define PolygonV2_HEADER

#include <string>
#include "IvPBehavior.h"
#include "XYPoint.h"

class BHV_PolygonV2 : public IvPBehavior {
public:
  BHV_PolygonV2(IvPDomain);
  ~BHV_PolygonV2() {};
  
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
  void decidePath();
  double getTheta(double , double, double, double);
  IvPFunction* buildFunctionWithZAIC();
  void postViewPoint(std::string);

protected: // Configuration parameters
  double m_arrival_radius;
  double m_desired_speed;
  std::string m_clockwise;
  double m_repeat;
  std::string m_polygon;


protected: // State variables
  double m_osx;
  double m_osy;
  std::vector<double> m_x_point;
  std::vector<double> m_y_point;
  int m_index;
  double m_count;
  bool m_collect;
  bool m_first;
  XYPoint m_point;
};

#define IVP_EXPORT_FUNCTION

extern "C" {
  IVP_EXPORT_FUNCTION IvPBehavior * createBehavior(std::string name, IvPDomain domain) 
  {return new BHV_PolygonV2(domain);}
}
#endif
