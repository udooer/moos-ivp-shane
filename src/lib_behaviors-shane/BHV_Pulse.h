/************************************************************/
/*    NAME: shane                                              */
/*    ORGN: MIT                                             */
/*    FILE: BHV_Pulse.h                                      */
/*    DATE:                                                 */
/************************************************************/

#ifndef Pulse_HEADER
#define Pulse_HEADER

#include <string>
#include "IvPBehavior.h"

class BHV_Pulse : public IvPBehavior {
public:
  BHV_Pulse(IvPDomain);
  ~BHV_Pulse() {};
  
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
  void postViewRangePulse();
  IvPFunction* buildFunctionWithZAIC();

protected: // Configuration parameters
  double m_pulse_range;
  double m_pulse_duration;
  double m_pulse_time;
  double m_local_time;
  double m_WPT_index;
  double m_last_index;

  double m_curr_time;
  double m_WPT_time;
  int m_case;
  
protected: // State variables
  double m_osx;
  double m_osy;
};

#define IVP_EXPORT_FUNCTION

extern "C" {
  IVP_EXPORT_FUNCTION IvPBehavior * createBehavior(std::string name, IvPDomain domain) 
  {return new BHV_Pulse(domain);}
}
#endif
