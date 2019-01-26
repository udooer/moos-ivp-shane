/************************************************************/
/*    NAME: handshane                                              */
/*    ORGN: MIT                                             */
/*    FILE: PointAssign.cpp                                        */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "ACTable.h"
#include "PointAssign.h"

using namespace std;

//---------------------------------------------------------
// Constructor

PointAssign::PointAssign()
{
    m_vname = "";
    m_v_vector.clear();
    m_assign_by_region = "false";
    m_coordinate_list.clear();
    m_done = 0;
    m_left_index.clear();
    m_right_index.clear();
}

//---------------------------------------------------------
// Destructor

PointAssign::~PointAssign()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool PointAssign::OnNewMail(MOOSMSG_LIST &NewMail)
{
  AppCastingMOOSApp::OnNewMail(NewMail);

  MOOSMSG_LIST::iterator p;
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;
    string key    = msg.GetKey();

#if 0 // Keep these around just for template
    string comm  = msg.GetCommunity();
    double dval  = msg.GetDouble();
    string sval  = msg.GetString(); 
    string msrc  = msg.GetSource();
    double mtime = msg.GetTime();
    bool   mdbl  = msg.IsDouble();
    bool   mstr  = msg.IsString();
#endif

     if(key == "FOO") 
       cout << "great!";
     else if(key == "VISIT_POINT")
       m_coordinate_list.push_back(msg.GetString());  
     else if(key != "APPCAST_REQ") // handled by AppCastingMOOSApp
       reportRunWarning("Unhandled Mail: " + key);
   }
	
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool PointAssign::OnConnectToServer()
{
   registerVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool PointAssign::Iterate()
{
  AppCastingMOOSApp::Iterate();
  // Do your thing here!
  if(m_done == false && m_coordinate_list.size() == 102 && (m_assign_by_region == "false" || m_assign_by_region == "FALSE")){
    list<string>::iterator plist;
    plist = m_coordinate_list.begin();

    for(int i=0;i<102;i++)
    {   
        if(i<50){
            Notify("VISIT_POINT_"+m_v_vector.at(0),*plist);    
        }
        else if(i==50){
            Notify("VISIT_POINT_"+m_v_vector.at(0),*plist);
            Notify("VISIT_POINT_"+m_v_vector.at(0),"lastpoint");
        }
        else if(i==51){
            Notify("VISIT_POINT_"+m_v_vector.at(1),"firstpoint");
            Notify("VISIT_POINT_"+m_v_vector.at(1),*plist);
        }
        else{
            Notify("VISIT_POINT_"+m_v_vector.at(1),*plist);
        
        }
        plist++;
    }
  }
  else if(m_done == false && m_coordinate_list.size() == 102 && (m_assign_by_region == "true" || m_assign_by_region == "TRUE")){
      separate_points_by_half_x();
      list<string>::iterator plist=m_coordinate_list.begin();
      for(int i=0;i<m_left_index.size();i++){
          if(i==0)
              Notify("VISIT_POINT_"+m_v_vector.at(0),"firstpoint");
          Notify("VISIT_POINT_"+m_v_vector.at(0), *( next(plist, m_left_index.at(i)) ));
          if(i==m_left_index.size()-1)
              Notify("VISIT_POINT_"+m_v_vector.at(0),"lastpoint");
        
      }
      for(int i=0;i<m_right_index.size();i++){
          if(i==0)
              Notify("VISIT_POINT_"+m_v_vector.at(1),"firstpoint");
          Notify("VISIT_POINT_"+m_v_vector.at(1), *( next(plist, m_right_index.at(i) )));
          if(i==m_right_index.size()-1)
              Notify("VISIT_POINT_"+m_v_vector.at(1),"lastpoint");
          
      }
  }
  m_done = true;
//  if(!m_coordinate_list.empty() && m_assign_by_region == "false"){
//      m_count++;
//      list<string>::iterator plist;
//      plist = m_coordinate_list.begin();
//
//      if(m_count<=50)     
//        Notify("VISIT_POINT_"+m_v_vector.at(0),m_coordinate_list.front());
//      else if(m_count==51){
//          Notify("VISIT_POINT_"+m_v_vector.at(0),m_coordinate_list.front());
//          Notify("VISIT_POINT_"+m_v_vector.at(0),"lastpoint");
//      }
//      else if(m_count==52){
//          Notify("VISIT_POINT_"+m_v_vector.at(1),"firstpoint");
//          Notify("VISIT_POINT_"+m_v_vector.at(1),m_coordinate_list.front());
//      }
//      else
//          Notify("VISIT_POINT_"+m_v_vector.at(1),m_coordinate_list.front());
//      m_coordinate_list.erase(plist);
//  }
  AppCastingMOOSApp::PostReport();
  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool PointAssign::OnStartUp()
{
  AppCastingMOOSApp::OnStartUp();

  STRING_LIST sParams;
  m_MissionReader.EnableVerbatimQuoting(false);
  if(!m_MissionReader.GetConfiguration(GetAppName(), sParams))
    reportConfigWarning("No config block found for " + GetAppName());

  STRING_LIST::iterator p;
  for(p=sParams.begin(); p!=sParams.end(); p++) {
    string orig  = *p;
    string line  = *p;
    string param = tolower(biteStringX(line, '='));
    string value = line;

    Notify("SCRIPT_COORDINATE","false");
    bool handled = false;
    
    if(param == "foo") {
      handled = true;
    }
    else if(param == "bar") {
      handled = true;
    }
    else if(param == "vname") {
        m_vname = value;
        cutString();
        handled = true;
    }
    else if(param == "assign_by_region") {
        m_assign_by_region = stripBlankEnds(value);
        handled = true;
    }
    if(!handled)
      reportUnhandledConfigWarning(orig);

  }
  
  registerVariables();	
  return(true);
}

//---------------------------------------------------------
// Procedure: registerVariables

void PointAssign::registerVariables()
{
  AppCastingMOOSApp::RegisterVariables();
  // Register("FOOBAR", 0);
  Register("VISIT_POINT",0);
}


//------------------------------------------------------------
// Procedure: buildReport()

bool PointAssign::buildReport() 
{
  m_msgs << "============================================ \n";
  m_msgs << "File:                                        \n";
  m_msgs << "============================================ \n";

  ACTable actab(4);
  actab << "Alpha | Bravo | Charlie | Delta";
  actab.addHeaderLines();
  actab << "one" << "two" << "three" << "four";
  m_msgs << actab.getFormattedString();

  return(true);
}

void PointAssign::cutString()
{
    stringstream ss;
    string token;
    ss<<m_vname;
    char delim = ',';
    while (getline(ss, token, delim)){
        m_v_vector.push_back(stripBlankEnds(token));
    }
}

void PointAssign::separate_points_by_half_x()
{
    string x;
    stringstream ss;
    double x_point;
    list<string>::iterator plist = m_coordinate_list.begin();
    for(int i=0;i<102;i++){
        x = tokStringParse(*( next(plist,i) ), "x", ',', '=');
        ss<<x;
        ss>>x_point;
        if(x!="" && x_point>=-25 && x_point<87.5){
            m_left_index.push_back(i);
        }
        else if(x!="" && x_point>=87.5 && x_point<=200) 
            m_right_index.push_back(i);
        ss.clear();
    }    
}

