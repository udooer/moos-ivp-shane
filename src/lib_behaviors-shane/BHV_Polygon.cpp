/************************************************************/
/*    NAME: shane                                              */
/*    ORGN: MIT                                             */
/*    FILE: BHV_Polygon.cpp                                    */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include <cstdlib>
#include "MBUtils.h"
#include "BuildUtils.h"
#include "BHV_Polygon.h"
#include <sstream>
#include <cmath>
#include "ZAIC_PEAK.h"
#include "AngleUtils.h"
#include "OF_Coupler.h"

#define PI 3.14159265
using namespace std;

//---------------------------------------------------------------
// Constructor

BHV_Polygon::BHV_Polygon(IvPDomain domain) :
  IvPBehavior(domain)
{
  // Provide a default behavior name
  IvPBehavior::setParam("name", "defaultname");

  // Declare the behavior decision space
  m_domain = subDomain(m_domain, "course,speed");

  // Default values for configuration parameters
  m_path = "";
  m_polygon = "circle";
  m_center_x = 0;
  m_center_y = 0;
  m_radius = 10;
  m_omega = 0;
  m_amplitude = 0;
  m_desired_speed = 0;
  m_arrival_radius = 0.5;
  x_point.clear();
  y_point.clear();
  m_index = 0;
  point.clear();

  
  // Default values for behavior state variables
  m_osx = 0;
  m_osy = 0;
  
  // Add any variables this behavior needs to subscribe for
  addInfoVars("NAV_X, NAV_Y");
}

//---------------------------------------------------------------
// Procedure: setParam()

bool BHV_Polygon::setParam(string param, string val)
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
  else if (param == "path") {
    m_path = val;
    decode();
    return true;
  }
//  else if ((param == "resolution") && (double_val > 0) && (isNumber(val))){
//    m_resolution = double_val;
//    return true;
//  }
  else if ((param == "speed") && (double_val > 0) && (isNumber(val))){
    m_desired_speed = double_val;
    return true;
  }
  else if ((param == "radius") && (double_val > 0) && (isNumber(val))){
    m_arrival_radius = double_val;
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

void BHV_Polygon::onSetParamComplete()
{
}

//---------------------------------------------------------------
// Procedure: onHelmStart()
//   Purpose: Invoked once upon helm start, even if this behavior
//            is a template and not spawned at startup

void BHV_Polygon::onHelmStart()
{
}

//---------------------------------------------------------------
// Procedure: onIdleState()
//   Purpose: Invoked on each helm iteration if conditions not met.

void BHV_Polygon::onIdleState()
{
//    XYPoint erase;
//    postMessage("IDLE",9999);
//    if(!x_point.empty()){
//        for(int i=0;i<x_point.size();i++){
//            postMessage("IDLE",i);
//            erase.set_vx(x_point.at(i));
//            erase.set_vy(y_point.at(i));
//            postMessage("VIEW_POINT", erase.get_spec("active=false"));
//        }
//    }
}

//---------------------------------------------------------------
// Procedure: onCompleteState()

void BHV_Polygon::onCompleteState()
{
}

//---------------------------------------------------------------
// Procedure: postConfigStatus()
//   Purpose: Invoked each time a param is dynamically changed

void BHV_Polygon::postConfigStatus()
{
}

//---------------------------------------------------------------
// Procedure: onIdleToRunState()
//   Purpose: Invoked once upon each transition from idle to run state

void BHV_Polygon::onIdleToRunState()
{
}

//---------------------------------------------------------------
// Procedure: onRunToIdleState()
//   Purpose: Invoked once upon each transition from run to idle state

void BHV_Polygon::onRunToIdleState()
{
}

//---------------------------------------------------------------
// Procedure: buildFunctionWithZAIC()
//---------------------------------------------------------------
IvPFunction* BHV_Polygon::buildFunctionWithZAIC()
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

   double rel_ang_to_wpt = relAng(m_osx, m_osy, x_point.at(m_index), y_point.at(m_index));
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

//---------------------------------------------------------------
// Procedure: onRunState()
//   Purpose: Invoked each iteration when run conditions have been met.

IvPFunction* BHV_Polygon::onRunState()
{
  bool ok1, ok2;
  m_osx = getBufferDoubleVal("NAV_X", ok1);
  m_osy = getBufferDoubleVal("NAV_Y", ok2);
  if(!ok1 || !ok2) {
      postWMessage("No ownship X/Y info in info_buffer.");
      return(0);
  }
  // Part 1: Build the IvP function
  IvPFunction *ipf = 0;
  switch (m_char){
    case 'c':
    case 's':{
        postMessage("M_CASE", "c or s");
        x_point = getDiscretex();
        y_point = getDiscretey();
        m_char = 'w';
        break;
    }
    case 'w':{
        postMessage("M_CASE", "w");
        ipf = buildFunctionWithZAIC();
        break;
    }   
  }
  postViewPoint();
  double dist;
  dist = sqrt(pow((m_osx-x_point.at(m_index)), 2)+pow((m_osy-y_point.at(m_index)), 2));
  postMessage("DIST", dist);
  if(dist<m_arrival_radius)
      if(m_index == x_point.size()-1)
          m_index = 0;
      else
          m_index++;



  // Part N: Prior to returning the IvP function, apply the priority wt
  // Actual weight applied may be some value different than the configured
  // m_priority_wt, depending on the behavior author's insite.
  if(ipf)
    ipf->setPWT(m_priority_wt);

  return(ipf);
}

void BHV_Polygon::decode()
{
    m_polygon = tokStringParse(m_path, "polygon", ',', '=');
    if(m_polygon == "circle")
        m_char = 'c';
    if(m_polygon == "sinewave")
        m_char = 's';
    if((m_polygon != "circle") || (m_polygon != "sinewave"))
        postWMessage("wrong configuration on polygon");
    if (m_polygon == "circle") {
        string x,y,r;
        stringstream ss;
        x = tokStringParse(m_path, "center_x", ',', '=');
        y = tokStringParse(m_path, "center_y", ',', '=');
        r = tokStringParse(m_path, "radius", ',', '=');
        if(x == "")
            postWMessage("wrong configuration on center_x");
        if(y == "")
            postWMessage("wrong configuration on center_y");
        if(r == "")
            postWMessage("wrong configuration on radius");
        if((x != "") && (y != "") && (r != "")){
            ss<<x;ss>>m_center_x;ss.clear();
            ss<<y;ss>>m_center_y;ss.clear();
            ss<<r;ss>>m_radius;ss.clear();
        }
    }

    if (m_polygon == "sinewave") {
        string w, a, x, y;
        stringstream ss;
        w = tokStringParse(m_path, "omega", ',', '=');
        a = tokStringParse(m_path, "amplitude", ',', '=');
        x = tokStringParse(m_path, "start_x", ',', '=');
        y = tokStringParse(m_path, "start_y", ',', '=');
        if(w == "")
            postWMessage("wrong configuration on omega");
        if(a == "")
            postWMessage("wrong configuration on amplitude");
        if(x == "")
            postWMessage("wrong configuration on start_x");
        if(y == "")
            postWMessage("wrong configuration on start_y");
        if((w != "") && (a != "") && (x != "") && (y != "")){
            ss<<w;ss>>m_omega;ss.clear();
            ss<<a;ss>>m_amplitude;ss.clear();
            ss<<x;ss>>m_start_x;ss.clear();
            ss<<y;ss>>m_start_y;ss.clear();
        }
    }
}

vector<double> BHV_Polygon::getDiscretex()
{
    vector<double> x;
    int resolution;
    switch(m_char){
        case 'c':
            resolution = 20;
            for(int i=0;i<resolution;i++){
                x.push_back(m_center_x + m_radius*cos(2*PI/resolution*i));
            }
            break;
        case 's':
            resolution = 16;
            for(int j=0;j<2;j++)
                for(int i=0;i<resolution;i++){
                    x.push_back(m_start_x + j/m_omega + 1/m_omega/resolution*i);
                }
            break;
    }
    return x;
}

vector<double> BHV_Polygon::getDiscretey()
{
    vector<double> y;
    int resolution;
    switch(m_char){
        case 'c':
            resolution = 20;
            for(int i=0;i<resolution;i++){
                y.push_back(m_center_y + m_radius*sin(2*PI/resolution*i));
            }
            break;
        case 's':
            resolution = 16;
            for(int j=0;j<2;j++)
                for(int i=0;i<resolution;i++){
                    y.push_back(m_start_y + m_amplitude*sin(2*PI/resolution*i));
                }
            break;
    }
    return y;
}

void BHV_Polygon::postViewPoint()
{
    for(int i=0;i<x_point.size();i++){
        string s = intToString(i+1);
        point.set_vx(x_point.at(i));
        point.set_vy(y_point.at(i));
        point.set_label(s);
        postMessage("VIEW_POINT", point.get_spec("active=true"));
    }
}
