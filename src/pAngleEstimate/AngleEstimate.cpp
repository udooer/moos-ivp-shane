/************************************************************/
/*    NAME: Shane                                              */
/*    ORGN: MIT                                             */
/*    FILE: AngleEstimate.cpp                                        */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "ACTable.h"
#include "AngleEstimate.h"

using namespace std;

//---------------------------------------------------------
// Constructor

AngleEstimate::AngleEstimate()
{
    m_collected_data.clear();
    m_points.clear();
    m_node = "";
}

//---------------------------------------------------------
// Destructor

AngleEstimate::~AngleEstimate()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool AngleEstimate::OnNewMail(MOOSMSG_LIST &NewMail)
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
     else if (key == "COLLECT"){
       dataProcessing(msg.GetString());
     }
     else if (key == "UCTD_MSMNT_REPORT"){
       decode(msg.GetString());
     }
     else
       reportRunWarning("Unhandled Mail: " + key);

   }

	
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool AngleEstimate::OnConnectToServer()
{
   registerVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool AngleEstimate::Iterate()
{
  AppCastingMOOSApp::Iterate();
  // Do your thing here!
  AppCastingMOOSApp::PostReport();
  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool AngleEstimate::OnStartUp()
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

    if(!handled)
      reportUnhandledConfigWarning(orig);

  }
  
  registerVariables();	
  return(true);
}

//---------------------------------------------------------
// Procedure: registerVariables

void AngleEstimate::registerVariables()
{
  AppCastingMOOSApp::RegisterVariables();
  Register("COLLECT", 0);
  Register("UCTD_MSMNT_REPORT", 0);
  // Register("FOOBAR", 0);
}


//------------------------------------------------------------
// Procedure: buildReport()

bool AngleEstimate::buildReport() 
{
  m_msgs << "============================================" << endl;
  m_msgs << "File:                                       " << endl;
  m_msgs << "============================================" << endl;

  ACTable actab(4);
  actab << "Alpha | Bravo | Charlie | Delta";
  actab.addHeaderLines();
  actab << "one" << "two" << "three" << "four";
  m_msgs << actab.getFormattedString();

  return(true);
}

//----------------------------------------------------------
//process the data
//----------------------------------------------------------

void AngleEstimate::dataProcessing(string cmd)
{
  if (cmd == "start"){
    m_collected_data.clear();
  }
  else if (cmd == "estimating"){
    double temp_min=1000;
    double temp_max=0;
    vector<WFD>::iterator pt;
    for(pt=m_collected_data.begin();pt!=m_collected_data.end();pt++){
      if(pt->temp > temp_max){
       temp_max = pt->temp;
      }
      else if(pt->temp < temp_min){
       temp_min = pt->temp;
      }
    }
    double thres = 0.05;
    double temp_mid = (temp_max+temp_min)/2;
    double sum_x = 0;
    double sum_y = 0;
    int count=0;
    vector<double> x_vec;
    vector<double> y_vec;
    
    if(!x_vec.empty()){
      Notify("VIEW_POINT", m_P_A.get_spec("active=false"));
      Notify("VIEW_POINT", m_P_B.get_spec("active=false"));
    }

E:
    x_vec.clear();
    y_vec.clear();
    for(pt=m_collected_data.begin();pt!=m_collected_data.end();pt++){
        if(abs(pt->temp-temp_mid) < thres){
            sum_x += pt->x;
            sum_y += pt->y;
            count++;
        }
        else if (abs(pt->temp-temp_mid)>=thres && count > 0){
          x_vec.push_back(sum_x/count);
          y_vec.push_back(sum_y/count);
          count = 0;
          sum_y = 0;
          sum_x = 0;
        }
    }
    
    if(x_vec.size()==2){
      m_node = m_collected_data.at(0).vname;
      points p;
      p.theta=atan(abs(y_vec.at(0)-y_vec.at(1))/abs(x_vec.at(0)-x_vec.at(1)))*180/M_PI;
      
      if(m_points.empty()){
        p.x1=x_vec.at(0);p.x2=x_vec.at(1);p.y1=y_vec.at(0);p.y2=y_vec.at(1);
      }
      else{
        double dist1=0;
        double dist2=0;
        dist1 = sqrt(pow((m_points.back().x1-x_vec.at(0)),2)+pow((m_points.back().y1-y_vec.at(0)),2));
        dist2 = sqrt(pow((m_points.back().x2-x_vec.at(0)),2)+pow((m_points.back().y2-y_vec.at(0)),2));
        if(dist2 > dist1){
          p.x1=x_vec.at(0);p.x2=x_vec.at(1);p.y1=y_vec.at(0);p.y2=y_vec.at(1);
        }
        else{
          p.x1=x_vec.at(1);p.x2=x_vec.at(0);p.y1=y_vec.at(1);p.y2=y_vec.at(0);
        }
      }

      p.weight = 1/thres;

      m_points.push_back(p);
      m_collected_data.clear();

      m_P_A.set_vx(p.x1);
      m_P_A.set_vy(p.y1);
      m_P_A.set_label(m_node+"_POINT_A");
      Notify("VIEW_POINT", m_P_A.get_spec("active=true"));

      m_P_B.set_vx(p.x2);
      m_P_B.set_vy(p.y2);
      m_P_B.set_label(m_node+"_POINT_B");
      Notify("VIEW_POINT", m_P_B.get_spec("active=true"));      
    }
    else{
      stringstream ss;string s;
      ss<<"category="<<x_vec.size()<<",thres="<<thres;
      ss>>s;ss.clear();
      Notify("WARNING",s);
      thres += 0.01;
      goto E;    
    }
  }  
    
  else if (cmd == "end"){
    Notify("VIEW_POINT", m_P_A.get_spec("active=false"));
    Notify("VIEW_POINT", m_P_B.get_spec("active=false"));
    deletePoint();   
    Notify("SIZE", m_points.size());
    points p;
    for(int i=0;i<m_points.size();i++){
      double weight = m_points.at(i).weight;
      p.weight += weight;
      p.theta += m_points.at(i).theta * weight;
      p.x1 += m_points.at(i).x1 * weight;
      p.x2 += m_points.at(i).x2 * weight;
      p.y1 += m_points.at(i).y1 * weight;
      p.y2 += m_points.at(i).y2 * weight;
    }
    p.theta /= p.weight;
    p.x1 /= p.weight;
    p.x2 /= p.weight;
    p.y1 /= p.weight;
    p.y2 /= p.weight;
    
    

    stringstream ss;
    string s;
    ss<<"theta="<<p.theta<<",x1="<<p.x1<<",y1="<<p.y1<<",x2="<<p.x2<<",y2="<<p.y2;
    ss>>s;ss.clear();
    Notify("THETA_REPORT", s);
    Notify("THETA", p.theta);

    ss<<"src_node="<<m_node<<",dest_node=all,var_name=THETA_REPORT,string_val=\"theta="<<p.theta<<",x1="<<p.x1<<",y1="<<p.y1<<",x2="<<p.x2<<",y2="<<p.y2<<"\"";
    ss>>s;ss.clear();
    Notify("NODE_MESSAGE_LOCAL", s);
    
    m_P_A.set_vx(p.x1);
    m_P_A.set_vy(p.y1);
    m_P_A.set_label(m_node+"_POINT_A");
    Notify("VIEW_POINT", m_P_A.get_spec("active=true"));

    m_P_B.set_vx(p.x2);
    m_P_B.set_vy(p.y2);
    m_P_B.set_label(m_node+"_POINT_B");
    Notify("VIEW_POINT", m_P_B.get_spec("active=true"));
  }
}

//-----------------------------------------------------------
//decode
//-----------------------------------------------------------

void AngleEstimate::decode(string ori)
{
  string vname, x, y, temp;
  vname = tokStringParse(ori, "vname", ',', '=');
  x = tokStringParse(ori, "x", ',', '=');
  y = tokStringParse(ori, "y", ',', '=');
  temp = tokStringParse(ori, "temp", ',', '=');

  stringstream ss;
  WFD data;
  ss<<vname;ss>>(data.vname);ss.clear();
  ss<<x;ss>>(data.x);ss.clear();
  ss<<y;ss>>(data.y);ss.clear();
  ss<<temp;ss>>(data.temp);ss.clear();
  m_collected_data.push_back(data);
}

//---------------------------------------------------------------
//delete 
//---------------------------------------------------------------
void AngleEstimate::deletePoint()
{
  double dist_max=0;
  double dist;
  for(int i=0;i<m_points.size();i++){
    dist = sqrt(pow((m_points.at(i).x1-m_points.at(i).x2),2)+pow((m_points.at(i).y1-m_points.at(i).y2),2));
    if(dist>dist_max)
      dist_max = dist;
  }
  vector<points>::iterator pt = m_points.begin();
  for(;pt!=m_points.end();){
    dist = sqrt(pow((pt->x1-pt->x2),2)+pow((pt->y1-pt->y2),2));
    if(dist_max/dist > 1.2)
      m_points.erase(pt++);
    else
      pt++;
  }
}

