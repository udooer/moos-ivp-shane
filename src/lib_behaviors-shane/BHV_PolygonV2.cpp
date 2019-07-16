/*    NAME: Shane                                              */
/*    ORGN: MIT                                             */
/*    FILE: BHV_PolygonV2.cpp                                    */
/*    DATE:                                                 */
/************************************************************/
#define _USE_MATH_DEFINES

#include <iterator>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include "MBUtils.h"
#include "BuildUtils.h"
#include "BHV_PolygonV2.h"
#include "ZAIC_PEAK.h"
#include "AngleUtils.h"
#include "OF_Coupler.h"


using namespace std;

//---------------------------------------------------------------
// Constructor

BHV_PolygonV2::BHV_PolygonV2(IvPDomain domain) :
  IvPBehavior(domain)
{
  // Provide a default behavior name
  IvPBehavior::setParam("name", "defaultname");

  // Declare the behavior decision space
  m_domain = subDomain(m_domain, "course,speed");
  
  //Default values for all parameters
  m_index = 0;
  m_osx = 0;
  m_osy = 0;
  m_arrival_radius = 0.5;
  m_desired_speed = 2;
  m_repeat = 1;
  m_count = 0;
  m_collect = false;
  m_first = true;
  // Add any variables this behavior needs to subscribe for
  addInfoVars("NAV_X, NAV_Y");
}

//---------------------------------------------------------------
// Procedure: setParam()

bool BHV_PolygonV2::setParam(string param, string val)
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
  else if (param == "polygon"){
    m_polygon = val;
    return true;
  }
  else if (param == "arrival_radius"){
    m_arrival_radius = double_val;
    return true;
  }
  else if (param == "desired_speed"){
    m_desired_speed = double_val;
    return true;
  }
  else if (param == "clockwise"){
    m_clockwise = val;
    return true;
  }
  else if (param == "repeat"){
    m_repeat = double_val;
    return true;
  }

  // If not handled above, then just return false;
  return(false);
}

//---------------------------------------------------------------
// Procedure: onSetParamComplete()
//   Purpose: Invoked once after all parameters have been handled.
//            Good place to ensure all required params have are set.
//            Or any inter-param relationships like a<b.

void BHV_PolygonV2::onSetParamComplete()
{
}

//---------------------------------------------------------------
// Procedure: onHelmStart()
//   Purpose: Invoked once upon helm start, even if this behavior
//            is a template and not spawned at startup

void BHV_PolygonV2::onHelmStart()
{
}

//---------------------------------------------------------------
// Procedure: onIdleState()
//   Purpose: Invoked on each helm iteration if conditions not met.

void BHV_PolygonV2::onIdleState()
{
}

//---------------------------------------------------------------
// Procedure: onCompleteState()

void BHV_PolygonV2::onCompleteState()
{
}

//---------------------------------------------------------------
// Procedure: postConfigStatus()
//   Purpose: Invoked each time a param is dynamically changed

void BHV_PolygonV2::postConfigStatus()
{
}

//---------------------------------------------------------------
// Procedure: onIdleToRunState()
//   Purpose: Invoked once upon each transition from idle to run state

void BHV_PolygonV2::onIdleToRunState()
{
}

//---------------------------------------------------------------
// Procedure: onRunToIdleState()
//   Purpose: Invoked once upon each transition from run to idle state

void BHV_PolygonV2::onRunToIdleState()
{
    m_count = 0;
    m_collect = false;
    m_first = true;
    postViewPoint("active=false");
    m_point.clear();

}

//---------------------------------------------------------------
// Procedure: onRunState()
//   Purpose: Invoked each iteration when run conditions have been met.

IvPFunction* BHV_PolygonV2::onRunState()
{
  if(m_first){
    m_first = false;
    m_x_point.clear();
    m_y_point.clear();
    decidePath();
    postViewPoint("active=true");
  }
  bool ok1, ok2;
  m_osx = getBufferDoubleVal("NAV_X", ok1);
  m_osy = getBufferDoubleVal("NAV_Y", ok2);
  if(!ok1 || !ok2) {
    postWMessage("No ownship X/Y info in info_buffer.");
    return(0);
  }

  // Part 1: Build the IvP function
  IvPFunction *ipf = 0;
  ipf = buildFunctionWithZAIC();
  double dist;
  dist = sqrt(pow((m_osx-m_x_point.at(m_index)), 2) + pow((m_osy-m_y_point.at(m_index)), 2));
  
  if(dist < m_arrival_radius)
    if(m_index == m_x_point.size()-1){
      m_index = 0;
      m_count++;
      postRepeatableMessage("COLLECT","estimating");
    }
    else{
      m_index++;
      if(!m_collect){
        postMessage("COLLECT","start");
        m_collect = true;
      }
    }

  if(m_count == m_repeat){
      postMessage("CIRCLE", "false");
      postMessage("RETURN2EXCHANGE", "true");
      postMessage("COLLECT","end");
  }
  
  // Part N: Prior to returning the IvP function, apply the priority wt
  // Actual weight applied may be some value different than the configured
  // m_priority_wt, depending on the behavior author's insite.
  if(ipf)
    ipf->setPWT(m_priority_wt);

  return(ipf);
}

void BHV_PolygonV2::decidePath()
{
  string path = tokStringParse(m_polygon, "path", ',', '=');
  if(path == "circle"){
    string center_x_s, center_y_s, radius_s, pts_s;
    center_x_s = tokStringParse(m_polygon, "center_x", ',', '=');
    center_y_s = tokStringParse(m_polygon, "center_y", ',', '=');
    radius_s = tokStringParse(m_polygon, "radius", ',', '=');
    pts_s = tokStringParse(m_polygon, "pts", ',', '=');
    
    bool ok1, ok2;
    m_osx = getBufferDoubleVal("NAV_X", ok1);
    m_osy = getBufferDoubleVal("NAV_Y", ok2);
    if(!ok1 || !ok2){
      m_osx = 0;
      m_osy = 0;
    }
    double center_x, center_y, radius, pts;
    stringstream ss;
    if( (center_x_s=="") || (center_y_s=="") || (radius_s=="") || (pts_s=="") )
        postWMessage("wrong configuration on \"polygon\" ");
    else{
      ss<<center_x_s;ss>>center_x;ss.clear();
      ss<<center_y_s;ss>>center_y;ss.clear();
      ss<<radius_s;ss>>radius;ss.clear();
      ss<<pts_s;ss>>pts;ss.clear();
    }
    double theta = getTheta(center_x, center_y, m_osx, m_osy);
    if (m_clockwise == "false"){    
      for(int i=0;i<pts;i++){
        m_x_point.push_back(center_x + radius*cos(theta + 2*M_PI*i/pts));
        m_y_point.push_back(center_y + radius*sin(theta + 2*M_PI*i/pts));
      }
    }
    else{    
      for(int i=0;i<pts;i++){
        m_x_point.push_back(center_x + radius*cos(theta - 2*M_PI*i/pts));
        m_y_point.push_back(center_y + radius*sin(theta - 2*M_PI*i/pts));
      }
    }    
  }
}

//has a bug, because the domain of acos is [0,pi];
double BHV_PolygonV2::getTheta(double center_x, double center_y, double start_x, double start_y)
{
    double a = sqrt(pow((center_x-start_x),2) + pow((center_y-start_y),2));
    double b_x = center_x+1; 
    double b_y = center_y;
    double c = sqrt(pow((b_x-start_x),2) + pow((b_y-start_y),2));

    double theta = acos((pow(a,2)+pow(1,2)-pow(c,2))/(2*a*1));
    return theta;
}
//---------------------------------------------------------------
// Procedure: buildFunctionWithZAIC()
//---------------------------------------------------------------
IvPFunction* BHV_PolygonV2::buildFunctionWithZAIC()
{
   ZAIC_PEAK spd_zaic(m_domain, "speed");
   spd_zaic.setSummit(m_desired_speed);
   spd_zaic.setPeakWidth(0.5);
   spd_zaic.setBaseWidth(1.0);
   spd_zaic.setSummitDelta(0.8);
   if(spd_zaic.stateOK() == false) {
     string warnings = "Speed ZAIC problems " + spd_zaic.getWarnings();
     postWMessage(warnings);
     return(0);
   } 
     
   double rel_ang_to_wpt = relAng(m_osx, m_osy, m_x_point.at(m_index), m_y_point.at(m_index));
   ZAIC_PEAK crs_zaic(m_domain, "course");
   crs_zaic.setSummit(rel_ang_to_wpt);
   crs_zaic.setPeakWidth(0);
   crs_zaic.setBaseWidth(180.0);
   crs_zaic.setSummitDelta(0);
   crs_zaic.setValueWrap(true);
   if(crs_zaic.stateOK() == false) {
     string warnings = "Course ZAIC problems " + crs_zaic.getWarnings();
     postWMessage(warnings);
     return(0);
   } 
     
   IvPFunction *spd_ipf = spd_zaic.extractIvPFunction();
   IvPFunction *crs_ipf = crs_zaic.extractIvPFunction();
   
   OF_Coupler coupler;
   IvPFunction *ivp_function = coupler.couple(crs_ipf, spd_ipf, 50, 50);
   
   return(ivp_function);
}  

void BHV_PolygonV2::postViewPoint(string cmd)
{
    for(int i=0;i<m_x_point.size();i++){
        string s = intToString(i+1);
        m_point.set_vx(m_x_point.at(i));
        m_point.set_vy(m_y_point.at(i));
        m_point.set_label(s);
        postMessage("VIEW_POINT", m_point.get_spec(cmd));
    }
}

