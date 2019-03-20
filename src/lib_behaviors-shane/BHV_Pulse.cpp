/************************************************************/
/*    NAME: shane                                              */
/*    ORGN: MIT                                             */
/*    FILE: BHV_Pulse.cpp                                    */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include <cstdlib>
#include "MBUtils.h"
#include "BuildUtils.h"
#include "BHV_Pulse.h"
#include "XYRangePulse.h"
#include "ZAIC_PEAK.h"

using namespace std;

//---------------------------------------------------------------
// Constructor

BHV_Pulse::BHV_Pulse(IvPDomain domain) :
  IvPBehavior(domain)
{
  // Provide a default behavior name
  IvPBehavior::setParam("name", "defaultname");

  // Declare the behavior decision space
  m_domain = subDomain(m_domain, "course,speed");

  // Defult values configuration parameters
  m_pulse_range = 20;
  m_pulse_duration = 4;
  m_case = 0;

  // Defult values for behavior state variables
  m_osx = 0;
  m_osy = 0;
  
  // Add any variables this behavior needs to subscribe for
  addInfoVars("NAV_X, NAV_Y, WPT_INDEX");
}

//---------------------------------------------------------------
// Procedure: setParam()

bool BHV_Pulse::setParam(string param, string val)
{
  // Convert the parameter to lower case for more general matching
  param = tolower(param);

  // Get the numerical value of the param argument for convenience once
  double double_val = atof(val.c_str());
  
  if((param == "foo") && isNumber(val)) {
    // Set local member variables here
    return(true);
  }
  else if (param == "bar") {
    // return(setBooleanOnString(m_my_bool, val));
  }
  else if ((param == "pulse_range") && (double_val > 0) && (isNumber(val))) {
    m_pulse_range = double_val; 
    return(true);
  }
  else if ((param == "pulse_duration") && (double_val > 0) && (isNumber(val))) {
    m_pulse_duration = double_val;
    return(true);
  }

  // If not handled above, then just return false;
  return(false);
}

//---------------------------------------------------------------
// Procedure: onSetParamComplete()
//   Purpose: Invoked once after all parameters have been handled.
//            Good place to ensure all required params have are set.
//            Or any inter-param relationships like a<b.

void BHV_Pulse::onSetParamComplete()
{
}

//---------------------------------------------------------------
// Procedure: onHelmStart()
//   Purpose: Invoked once upon helm start, even if this behavior
//            is a template and not spawned at startup

void BHV_Pulse::onHelmStart()
{
}

//---------------------------------------------------------------
// Procedure: onIdleState()
//   Purpose: Invoked on each helm iteration if conditions not met.

void BHV_Pulse::onIdleState()
{
}

//---------------------------------------------------------------
// Procedure: onCompleteState()

void BHV_Pulse::onCompleteState()
{
}

//
//
//---------------------------------------------------------------
// Procedure: postConfigStatus()
//   Purpose: Invoked each time a param is dynamically changed

void BHV_Pulse::postConfigStatus()
{
}

//---------------------------------------------------------------
// Procedure: onIdleToRunState()
//   Purpose: Invoked once upon each transition from idle to run state

void BHV_Pulse::onIdleToRunState()
{
}

//---------------------------------------------------------------
// Procedure: onRunToIdleState()
//   Purpose: Invoked once upon each transition from run to idle state

void BHV_Pulse::onRunToIdleState()
{
}

//---------------------------------------------------------------
// Procedure: postViewRangePulse
void BHV_Pulse::postViewRangePulse()
{   
    bool ok1, ok2;
    m_osx = getBufferDoubleVal("NAV_X", ok1);
    m_osy = getBufferDoubleVal("NAV_Y", ok2);    
    if(ok1 && ok2){
        XYRangePulse pulse;
        pulse.set_x(m_osx);
        pulse.set_y(m_osy);
        pulse.set_label("bhv_pulse");
        pulse.set_rad(m_pulse_range);
        pulse.set_duration(m_pulse_duration);
        pulse.set_time(m_curr_time);
        pulse.set_color("edge", "yellow");
        pulse.set_color("fill", "yellow");

        string spec = pulse.get_spec();
        postMessage("VIEW_RANGE_PULSE", spec);
    }
    else
      postWMessage("No ownship X/Y info in info_buffer.");  
     
}

//---------------------------------------------------------------
// Procedure: onRunState()
//   Purpose: Invoked each iteration when run conditions have been met.

IvPFunction* BHV_Pulse::onRunState()
{
  // Part 1: Build the IvP function
  IvPFunction *ipf = 0;
  bool WPTok;
  switch(m_case){
    case 0:{
        postMessage("M_CASE", m_case);
        m_WPT_index = getBufferDoubleVal("WPT_INDEX", WPTok);
        m_last_index = m_WPT_index;
        if(WPTok)
            m_case = 1;
        break;
    }
    case 1:{
        postMessage("M_CASE", m_case);
        m_WPT_index = getBufferDoubleVal("WPT_INDEX", WPTok);
        if(m_last_index != m_WPT_index){
            postMessage("LAST_INDEX", m_last_index);
            postMessage("WPT_INDEX_VALUE", m_WPT_index);
            m_pulse_time = getBufferLocalTime()+5;
            m_last_index = m_WPT_index;
            m_case = 2;
        }
        break;
    }
    case 2:{
        postMessage("M_CASE", m_case);
        m_local_time = getBufferLocalTime();
        if(m_local_time > m_pulse_time){
            postMessage("PULSE_TIME", m_pulse_time);
            m_curr_time = getBufferCurrTime();
            postViewRangePulse();
            m_case = 1;
        }
        break;
    }
  }
  // Part N: Prior to returning the IvP function, apply the priority wt
  // Actual weight applied may be some value different than the configured
  // m_priority_wt, depending on the behavior author's insite.
  if(ipf)
    ipf->setPWT(m_priority_wt);

  return(ipf);
}

