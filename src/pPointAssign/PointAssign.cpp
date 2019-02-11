/************************************************************/
/*    NAME: handshane                                              */
/*    ORGN: MIT                                             */
/*    FILE: PointAssign.cpp                                        */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
//#include "XYPoint.h"
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
    m_x.clear();
    m_y.clear();
    m_id.clear();

    m_done = false;
    m_received = false;

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
    string str;
    if(key == "FOO") 
        cout << "great!";
    else if(key == "VISIT_POINT"){
        str = msg.GetString();
        if(str != "firstpoint" && str != "lastpoint")
            m_coordinate_list.push_back(msg.GetString());
        else if(str == "lastpoint")
            m_received = true;
    }  
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
    if(m_done == false && m_received == true && (m_assign_by_region == "false" || m_assign_by_region == "FALSE")){
        decode();
        list<string>::iterator plist;
        plist = m_coordinate_list.begin();
        int n = m_x.size()/2;
        for(int i=0;i<m_x.size();i++){
            double x = m_x.at(i);
            double y = m_y.at(i);
            string id = m_id.at(i);
            if(i==0){
                Notify("VISIT_POINT_"+m_v_vector.at(0),"firstpoint");
                Notify("VISIT_POINT_"+m_v_vector.at(0),*plist);
                postViewPoint(x,y,id,"red");
            }
            else if(i>0 && i<n){
                Notify("VISIT_POINT_"+m_v_vector.at(0),*plist);
                postViewPoint(x,y,id,"red");
            }
            else if(i==n){
                Notify("VISIT_POINT_"+m_v_vector.at(0),*plist);
                postViewPoint(x,y,id,"red");
                Notify("VISIT_POINT_"+m_v_vector.at(0),"lastpoint");    
            }
            else if(i==n+1){
                Notify("VISIT_POINT_"+m_v_vector.at(1),"firstpoint");
                Notify("VISIT_POINT_"+m_v_vector.at(1),*plist);
                postViewPoint(x,y,id,"yellow");
            }
            else if(i>n+2 && i<m_x.size()-2){
                Notify("VISIT_POINT_"+m_v_vector.at(1),*plist);
                postViewPoint(x,y,id,"yellow");
            }
            else{
                Notify("VISIT_POINT_"+m_v_vector.at(1),*plist);
                postViewPoint(x,y,id,"yellow");
                Notify("VISIT_POINT_"+m_v_vector.at(1),"lastpoint");
            }
            plist++;
        }
        m_done = true;
    }   
    else if(m_done == false && m_received == true && (m_assign_by_region == "true" || m_assign_by_region == "TRUE")){
        decode();
        separatePointsByHalfX();
                
        int index;
        double x;
        double y;
        string id;
        
        list<string>::iterator plist=m_coordinate_list.begin();
        for(int i=0;i<m_left_index.size();i++){
            
            index = m_left_index.at(i);
            if(i==0)
                Notify("VISIT_POINT_"+m_v_vector.at(0),"firstpoint");
            
            Notify("VISIT_POINT_"+m_v_vector.at(0), *( next(plist, index) ));
            x = m_x.at(index);
            y = m_y.at(index);
            id = m_id.at(index);
            postViewPoint(x,y,id,"red");
            
            if(i==m_left_index.size()-1)
                Notify("VISIT_POINT_"+m_v_vector.at(0),"lastpoint");
          
        }
        for(int i=0;i<m_right_index.size();i++){
            
            index = m_right_index.at(i);
            if(i==0)
                Notify("VISIT_POINT_"+m_v_vector.at(1),"firstpoint");
            
            Notify("VISIT_POINT_"+m_v_vector.at(1), *( next(plist, index)));
            x = m_x.at(index);
            y = m_y.at(index);
            id = m_id.at(index);
            postViewPoint(x,y,id,"yellow");

            if(i==m_right_index.size()-1)
                Notify("VISIT_POINT_"+m_v_vector.at(1),"lastpoint");          
        }
        m_done = true;

    }
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

    Notify("POINT_ASSIGN","start");
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

void PointAssign::separatePointsByHalfX()
{
    for(int i=0;i<m_x.size();i++){
        double x = m_x.at(i);
        if(x>=-25 && x<87.5){
            m_left_index.push_back(i);
        }
        else if(x>=87.5 && x<=200) 
            m_right_index.push_back(i);
    }    
}

//void PointAssign::postViewPoint(double x, double y, string label, string color)
//{
//    XYPoint point(x, y);
//    point.set_label(label);
//    point.set_color("vertex", color);
//    point.set_param("vertex_size", "2");
//
//    string spec = point.get_spec();
//    Notify("VIEW_POINT", spec);
//}
void PointAssign::postViewPoint(double x, double y, string label, string color){
    string s;
    stringstream ss; 
    ss<<"x="<<x<<",y="<<y<<",label="<<label<<",vertex_size=2,vertex_color="<<color;
    ss>>s;
    Notify("VIEW_POINT",s);
    
}

void PointAssign::decode(){
    string x;
    string y;
    string id;
    stringstream ss;
    double x_point;
    double y_point;
    string empty="9999";

    list<string>::iterator plist = m_coordinate_list.begin();
    
    for(int i=0;i<m_coordinate_list.size();i++){
        x = tokStringParse(*plist, "x", ',', '=');
        if(x=="")
            x=empty;
        ss<<x;
        ss>>x_point;
        ss.clear();
        m_x.push_back(x_point);
        
        y = tokStringParse(*plist, "y", ',', '=');
        if(y=="")
            y=empty;
        ss<<y;
        ss>>y_point;
        ss.clear();
        m_y.push_back(y_point);
        
        id = tokStringParse(*plist, "id", ',', '=');
        if(id=="")
            id=empty;
        m_id.push_back(id);
        plist++;        
    }
}
