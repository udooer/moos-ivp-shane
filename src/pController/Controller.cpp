/************************************************************/
/*    NAME: shane                                              */
/*    ORGN: MIT                                             */
/*    FILE: Controller.cpp                                        */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "ACTable.h"
#include "Controller.h"

using namespace std;

//---------------------------------------------------------
// Constructor

Controller::Controller()
{
    m_kp = 0;
    m_ki = 0;
    m_kd = 0;
    m_max = 3;
    m_min = -3;

    m_desired_heading = 0;
    m_my_heading = 0;
    m_first_exe = true;
}

//---------------------------------------------------------
// Destructor

Controller::~Controller()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool Controller::OnNewMail(MOOSMSG_LIST &NewMail)
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
     else if (key == "DESIRED_HEADING"){
       m_desired_heading = msg.GetDouble();
     }
     else if (key == "MY_HEADING"){
       m_my_heading = msg.GetDouble();
     }

     else if(key != "APPCAST_REQ") // handled by AppCastingMOOSApp
       reportRunWarning("Unhandled Mail: " + key);
   }
	
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool Controller::OnConnectToServer()
{
   registerVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool Controller::Iterate()
{ 
  AppCastingMOOSApp::Iterate();
  // Do your thing here!
  clock_t start = clock();
  if(m_first_exe)
    m_pid.setConfig(m_kp, m_ki, m_kd, m_max, m_min);
  m_pid.setHeading(m_desired_heading);


  double error;
  double output;
  error = m_pid.getError(m_my_heading);
  output = m_pid.controller(error);
  Notify("OUTPUT_VOLTAGE", output);
  if(m_first_exe)
      m_first_exe = false;
  sleepInSecond(start, 0.01);

  AppCastingMOOSApp::PostReport();
  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool Controller::OnStartUp()
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
    else if (param == "kp") {
      m_kp = atof(value.c_str());
      handled = true;
    }
    else if (param == "ki") {
      m_ki = atof(value.c_str());
      handled = true;
    }
    else if (param == "kd") {
      m_kd = atof(value.c_str());
      handled = true;
    }
    else if (param == "min"){
      m_min = atof(value.c_str());
      handled = true;
    }
    else if (param == "max"){
      m_max = atof(value.c_str());
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

void Controller::registerVariables()
{
  AppCastingMOOSApp::RegisterVariables();
  // Register("FOOBAR", 0);
  Register("DESIRED_HEADING", 0);
  Register("MY_HEADING", 0);

}


//------------------------------------------------------------
// Procedure: buildReport()

bool Controller::buildReport() 
{
  m_msgs << "============================================ \n";
  m_msgs << "File:                                        \n";
  m_msgs << "============================================ \n";

  ACTable actab(4);
  actab << "Alpha | Bravo | Charlie | Delta";
  actab.addHeaderLines();
  actab << "one" << "two" << "three" << "four";
  m_msgs << "my heading: "<< m_my_heading << '\n';
  m_msgs << "desired heading: " << m_desired_heading << '\n';
  m_msgs << actab.getFormattedString();

  return(true);
}
void Controller::sleepInSecond(clock_t start, double sec)
{
    while(1)
        if(clock()-start/(double)CLOCKS_PER_SEC > sec)
            break;
}




