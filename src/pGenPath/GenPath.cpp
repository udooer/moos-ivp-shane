/************************************************************/
/*    NAME: handshane                                              */
/*    ORGN: MIT                                             */
/*    FILE: GenPath.cpp                                        */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include "GenPath.h"
#include "MBUtils.h"
#include "ACTable.h"
#include <string>
#include <sstream>
using namespace std;

//---------------------------------------------------------
// Constructor

GenPath::GenPath()
{
    m_input_list.clear();
    
    m_start_position = "";
    m_start_x = 0;
    m_start_y = 0;
    m_origin_x = 0;
    m_origin_y = 0;
    
    m_update_str = "points = ";
    m_return_done = "";
    
    m_x_list.clear();
    m_y_list.clear();
    m_visit_radius = 5;

    m_lastpoint_received = false;
    m_firstpoint_received = false;
    m_done = false;
    m_gen = false;
    
    m_state = "";

    m_total_distance = 0;
    m_total_number = 0;
    m_visited_number = 0;
    m_beside_number = 0;
    m_count = 0;
    c=0;
    a=0;
}

//---------------------------------------------------------
// Destructor

GenPath::~GenPath()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool GenPath::OnNewMail(MOOSMSG_LIST &NewMail)
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
    
    MyData point_data;
    string point;
    if(key == "FOO") 
       cout << "great!";
    else if(key == "VISIT_POINT"){
        point = msg.GetString();
        Notify("GET_POINT",point);
        point_data.SetOrin(point);
        if(point != "firstpoint" && point != "lastpoint"){
            point_data.decode();
            m_total_number++;
        }
        else if(point == "firstpoint"){
            m_firstpoint_received = true;
            Notify("firstpoint","get");
        }
        else if(point == "lastpoint"){
            m_lastpoint_received = true;
            Notify("lastpoint","get");
        }
        m_input_list.push_back(point_data);
    }
    else if(key == "RETURN_DONE"){
        m_return_done = msg.GetString();
        Notify("GET_RETURN_DONE", m_return_done);
    }
    else if(key == "NAV_X"){
        m_nav_x = msg.GetDouble();
        Notify("GET_X", m_nav_x);
    }
    else if(key == "NAV_Y"){
        m_nav_y = msg.GetDouble();
        Notify("GET_Y",m_nav_y);
    }
    else if(key == "STATE"){
        m_state = msg.GetString();
        Notify("GET_STATE",m_state);
    }
    else if(key != "APPCAST_REQ") // handled by AppCastingMOOSApp
        reportRunWarning("Unhandled Mail: " + key);
    }
	
    return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool GenPath::OnConnectToServer()
{
   registerVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool GenPath::Iterate()
{
  AppCastingMOOSApp::Iterate();
  // Do your thing here!
    
//    Notify("GET_X", m_nav_x);
//    Notify("GET_Y", m_nav_y);
//    Notify("GET_RETURN_DONE", m_return_done);
//    Notify("GET_DEPLOY", m_deploy);
//    Notify("GET_RETURN", m_return);
    c++;
    Notify("COUNT", c);
    if(!m_input_list.empty()){
        list<MyData>::iterator p;
        p = m_input_list.begin();
        if(p->GetOrin()=="lastpoint"){
            m_input_list.clear();
            m_lastpoint_received = false;
            m_count = 0;
            m_total_distance = 0;
            m_total_number = 0;
            m_visited_number = 0;
            m_beside_number = 0;
            m_start_x = m_origin_x;
            m_start_y = m_origin_y;
            m_update_str = "points = ";
        }
    }

    if(m_lastpoint_received == true){
        m_count++;
        list<MyData>::iterator ppost;
        ppost = GetMinDistance();
        
            
        //        XYSegList my_seglist;
        //        my_seglist.add_vertex(ppost->GetX(), ppost->GetY()); 
        m_x_list.push_back(m_start_x);
        m_y_list.push_back(m_start_y);
        m_id_list.push_back(ppost->GetID());        
        stringstream ss;
        string str;
        ss<<m_count;
        ss>>str;
        ss.clear();
        ppost->SetVisited(str);
        
        m_visited_number++;
        if(m_count == 1){
            ss<<m_start_x<<","<<m_start_y;
            ss>>str;
            ss.clear();
            m_update_str += str;
        }        
        else{
            ss<<":"<<m_start_x<<","<<m_start_y;
            ss>>str;
            ss.clear();
            m_update_str += str;
        }
        //update_str      += my_seglist.get_spec();
        Notify("UPDATE_POINTS", m_update_str);        
        string report;
        report = ppost->Report();
        reportEvent(report);
        Notify("REPORT",report);
        m_input_list.erase(ppost);
        
        EraseNearbyPoint();
    }    
    else if(!m_x_list.empty() && m_state == "returning" && m_gen == false){
        GenVisitPoint();
        Notify("GENPATH","new visit point posted");
        m_gen = true;
    }
    else if(m_x_list.empty() && m_input_list.empty() && m_state == "waiting" && m_done == false){
        Notify("GENPATH","all points arrived");
        Notify("UPDATE_POINTS","points =0,0:");
        m_done = true;
    }
    if(!m_x_list.empty() && m_state == "point surveying"){
        CheckIfArrived();
        int n;
        if(m_x_list.empty())
            n=0;
        else 
            n = m_x_list.size();
        Notify("M_X_LIST",n);
        m_gen = false;
    }
   AppCastingMOOSApp::PostReport();
    return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool GenPath::OnStartUp()
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

    bool handled = false;
    Notify("GENPATH","start");
    if(param == "foo") {
      handled = true;
    }
    else if(param == "bar") {
      handled = true;
    }
    else if(param == "start_position"){
        m_start_position = value;
        getStartPos();	
        handled = true;
    }
    else if(param == "visit_radius"){
        stringstream ss;
        ss<<value;
        ss>>m_visit_radius;
        ss.clear();
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

void GenPath::registerVariables()
{
  AppCastingMOOSApp::RegisterVariables();
  // Register("FOOBAR", 0);
  Register("VISIT_POINT",0);
  Register("NAV_X",0);
  Register("NAV_Y",0);
  Register("STATE",0);
  Register("RETURN_DONE",0);
}


//------------------------------------------------------------
// Procedure: buildReport()

bool GenPath::buildReport() 
{
  m_msgs << "============================================ \n";
  m_msgs << "File:                                        \n";
  m_msgs << "============================================ \n";

  ACTable actab(4);
  actab << "Alpha | Bravo | Charlie | Delta";
  actab.addHeaderLines();
  actab << "one" << "two" << "three" << "four";
  m_msgs << actab.getFormattedString();

  m_msgs<<"\n==============================================\n\n";
  m_msgs<<"total point number: "<<m_total_number<<'\n';
  m_msgs<<"visited number: "<<m_visited_number<<'\n';
  m_msgs<<"beside number: "<<m_beside_number<<'\n';
  m_msgs<<"total distance: "<<m_total_distance<<'\n';
  return(true);
}

void GenPath::getStartPos()
{
    string s;
    stringstream ss;
    double point;
    string tmp = m_start_position;
    vector<string> v = parseString(tmp, ',');

    s = stripBlankEnds(v.at(0));
    ss<<s;
    ss>>m_origin_x;
    m_start_x = m_origin_x;
    ss.clear();
    
    s = stripBlankEnds(v.at(1));
    ss<<s;
    ss>>m_origin_y;
    m_start_y = m_origin_y;
    ss.clear();
}

list<MyData>::iterator GenPath::GetMinDistance()
{
    list<MyData>::iterator p;
    list<MyData>::iterator ppost;
    double distance;
    double min=1000;
    for(p=m_input_list.begin();p->GetOrin()!="lastpoint";){
        if(p->GetOrin() == "firstpoint")
            m_input_list.erase(p++);
        else{
            distance = sqrt( pow( (m_start_x-p->GetX()), 2) + pow( (m_start_y-p->GetY()), 2) );
            if(min > distance){
                min = distance;
                ppost = p;
            }
            p++;
        }
    }
    m_start_x = ppost->GetX();
    m_start_y = ppost->GetY();
    ppost->SetDist(min);
    m_total_distance += min;
    return ppost;
}

void GenPath::EraseNearbyPoint()
{
    list<MyData>::iterator p;
    double distance;
    stringstream ss;
    string str;
    string report;
    for(p=m_input_list.begin();p->GetOrin()!="lastpoint";){
        distance = sqrt( pow( (m_start_x-p->GetX()), 2) + pow( (m_start_y-p->GetY()), 2) );
        if( distance < 0.5){
            ss<<"beside:"<<distance;
            ss>>str;
            ss.clear();
            p->SetVisited(str);
            p->SetDist(0);
            report = p->Report();
            reportEvent(report);
            Notify("REPORT",report);
            m_input_list.erase(p++);
            m_beside_number++;
        }
        else
            p++;
    }  
}

void GenPath::CheckIfArrived()
{
    list<double>::iterator px = m_x_list.begin();
    list<double>::iterator py = m_y_list.begin();
    list<string>::iterator pid = m_id_list.begin();
    list<double>::iterator p;
    double distance;
    for(;px!=m_x_list.end();){
        distance = sqrt( pow( (m_nav_x-*px), 2) + pow( (m_nav_y-*py), 2) );
        if(distance<m_visit_radius){
            m_x_list.erase(px++);
            m_y_list.erase(py++);
            m_id_list.erase(pid++);
        }
        else{
            px++;
            py++;
            pid++;
        }
    }
}

void GenPath::GenVisitPoint(){
    list<double>::iterator px = m_x_list.begin();
    list<double>::iterator py = m_y_list.begin();
    list<string>::iterator pid = m_id_list.begin();
    string str;
    stringstream ss;
    int n = m_x_list.size();
    for(int i=0;i<n;i++,px++,py++,pid++){
        ss<<"x="<<*px<<",y="<<*py<<",id="<<*pid;
        ss>>str;
        ss.clear();
        if(i==0){
            Notify("VISIT_POINT","firstpoint");
        }
        Notify("VISIT_POINT",str);
        if(i==n-1){
            Notify("VISIT_POINT","lastpoint");
        }    
    }
    m_x_list.clear();
    m_y_list.clear();
    m_id_list.clear(); 
}
