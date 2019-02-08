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

using namespace std;

//---------------------------------------------------------
// Constructor

GenPath::GenPath()
{
    m_start_position = "";
    m_input_list.clear();
    m_update_str = "points = ";
    m_done = false;

    m_x_vector.clear();
    m_y_vector.clear();
    m_received = false;
    m_total_distance = 0;
    m_total_number = 0;
    m_visited_number = 0;
    m_beside_number = 0;

    m_count = 0;

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
        if(point != "firstpoint" && point != "lastpoint"){
            point_data.SetOrin(point);
            point_data.decode();
            m_total_number++;
            m_input_list.push_back(point_data);
        }
        else if(point == "lastpoint")
            m_received = true;
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
    if(m_received == true && m_done == false){
        m_count++;

        list<MyData>::iterator ppost;
        ppost = GetMinDistance();
        //        XYSegList my_seglist;
        //        my_seglist.add_vertex(ppost->GetX(), ppost->GetY()); 
               
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
      
        if(m_input_list.empty()){
            m_done = true;
            Notify("DONE","true");
        }
    }
    Notify("GENPATH","true");
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
    ss>>m_start_x;
    ss.clear();
    
    s = stripBlankEnds(v.at(1));
    ss<<s;
    ss>>m_start_y;
    ss.clear();
}

list<MyData>::iterator GenPath::GetMinDistance()
{
    list<MyData>::iterator p;
    list<MyData>::iterator ppost;
    double distance;
    double min=1000;
    for(p=m_input_list.begin();p!=m_input_list.end();p++){
        distance = sqrt( pow( (m_start_x-p->GetX()), 2) + pow( (m_start_y-p->GetY()), 2) );
        if(min > distance){
            min = distance;
            ppost = p;
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
    for(p=m_input_list.begin();p!=m_input_list.end();p++){
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
            m_input_list.erase(p);
            m_beside_number++;
        }
    }  
}
