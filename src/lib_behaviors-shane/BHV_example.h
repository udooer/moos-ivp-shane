/************************************************************/
/*    NAME: shane                                              */
/*    ORGN: MIT                                             */
/*    FILE: BHV_example.h                                      */
/*    DATE:                                                 */
/************************************************************/

#ifndef example_HEADER
#define example_HEADER

#include <string>
#include "IvPBehavior.h"

class BHV_example : public IvPBehavior {
public:
  BHV_example(IvPDomain);
  ~BHV_example() {};
  
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

protected: // Configuration parameters

protected: // State variables
};

#define IVP_EXPORT_FUNCTION

extern "C" {
  IVP_EXPORT_FUNCTION IvPBehavior * createBehavior(std::string name, IvPDomain domain) 
  {return new BHV_example(domain);}
}
#endif
