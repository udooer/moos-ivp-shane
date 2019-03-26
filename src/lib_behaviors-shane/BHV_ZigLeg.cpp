/************************************************************/
/*    NAME: shane                                              */
/*    ORGN: MIT                                             */
/*    FILE: BHV_ZigLeg.cpp                                    */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include <cstdlib>
#include "MBUtils.h"
#include "BuildUtils.h"
#include "BHV_ZigLeg.h"
#include "ZAIC_PEAK.h"

using namespace std;

//---------------------------------------------------------------
// Constructor

BHV_ZigLeg::BHV_ZigLeg(IvPDomain domain) :
  IvPBehavior(domain)
{
  // Provide a default behavior name
  IvPBehavior::setParam("name", "defaultname");

  // Declare the behavior decision space
  m_domain = subDomain(m_domain, "course");

  // Defult values configuration parameters
  m_zig_angle = 45;
  m_zig_duration = 10;
  m_priority_wt = 2000;
  m_case = 0;
  m_count = 0;

  // Defult values for behavior state variables
  m_osx = 0;
  m_osy = 0;
  
  // Add any variables this behavior needs to subscribe for
  addInfoVars("NAV_X, NAV_Y, WPT_INDEX, DESIRED_HEADING");
}

//---------------------------------------------------------------
// Procedure: setParam()

bool BHV_ZigLeg::setParam(string param, string val)
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
  else if ((param == "zig_angle") && (double_val > 0) && (isNumber(val))) {
    m_zig_angle = double_val; 
    return(true);
  }
  else if ((param == "zig_duration") && (double_val > 0) && (isNumber(val))) {
    m_zig_duration = double_val;
    return(true);
  }
  else if ((param == "zig_pwt") && (double_val > 0) && (isNumber(val))){
    m_priority_wt = double_val;
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

void BHV_ZigLeg::onSetParamComplete()
{
}

//---------------------------------------------------------------
// Procedure: onHelmStart()
//   Purpose: Invoked once upon helm start, even if this behavior
//            is a template and not spawned at startup

void BHV_ZigLeg::onHelmStart()
{
}

//---------------------------------------------------------------
// Procedure: onIdleState()
//   Purpose: Invoked on each helm iteration if conditions not met.

void BHV_ZigLeg::onIdleState()
{
}

//---------------------------------------------------------------
// Procedure: onCompleteState()

void BHV_ZigLeg::onCompleteState()
{
}

//
//
//---------------------------------------------------------------
// Procedure: postConfigStatus()
//   Purpose: Invoked each time a param is dynamically changed

void BHV_ZigLeg::postConfigStatus()
{
}

//---------------------------------------------------------------
// Procedure: onIdleToRunState()
//   Purpose: Invoked once upon each transition from idle to run state

void BHV_ZigLeg::onIdleToRunState()
{
}

//---------------------------------------------------------------
// Procedure: onRunToIdleState()
//   Purpose: Invoked once upon each transition from run to idle state

void BHV_ZigLeg::onRunToIdleState()
{
}
//---------------------------------------------------------------
// Procedure: buildfunctionwithzaic()
// --------------------------------------------------------------
IvPFunction* BHV_ZigLeg::buildFunctionWithZAIC()
{
    bool headok;
    if(m_count == 0){
        m_heading = getBufferDoubleVal("DESIRED_HEADING", headok) + m_zig_angle;
        m_count++;
    }
    postMessage("STOP", 1);
    ZAIC_PEAK crs_zaic(m_domain, "course");
    crs_zaic.setSummit(m_heading);
    crs_zaic.setPeakWidth(0);
    crs_zaic.setBaseWidth(180);
    crs_zaic.setSummitDelta(0);
    crs_zaic.setValueWrap(true);
    postMessage("STOP", 2);
    if(crs_zaic.stateOK() == false) {
        string warnings = "Cource ZAIC problems " + crs_zaic.getWarnings();
        postWMessage(warnings);
        return 0;
    }
    postMessage("STOP", 3);
    IvPFunction *crs_ipf = crs_zaic.extractIvPFunction();
    postMessage("STOP", 4);
    return(crs_ipf);    
}
//---------------------------------------------------------------
// Procedure: onRunState()
//   Purpose: Invoked each iteration when run conditions have been met.

IvPFunction* BHV_ZigLeg::onRunState()
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
            m_zig_time = getBufferLocalTime()+5;
            m_last_index = m_WPT_index;
            m_case = 2;
        }
        break;
    }
    case 2:{
        postRepeatableMessage("M_CASE", m_case);
        m_local_time = getBufferLocalTime();
        if((m_local_time > m_zig_time) && (m_local_time < (m_zig_time + m_zig_duration))){
            postMessage("ZIG_TIME", m_zig_time);
            ipf = buildFunctionWithZAIC();
        } 
        if(m_local_time > (m_zig_time + m_zig_duration)){
            ipf = 0;
            m_case = 1;
            m_count = 0;
        }
        break;
    }
  }
  // Part N: Prior to returning the IvP function, apply the priority wt
  // Actual weight applied may be some value different than the configured
  // m_priority_wt, depending on the behavior author's insite.
  if(ipf){
    ipf->setPWT(m_priority_wt);
    postRepeatableMessage("PWT", m_priority_wt);
  }
  return(ipf);
}

