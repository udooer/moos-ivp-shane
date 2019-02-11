/************************************************************/
/*    NAME:                                               */
/*    ORGN: MIT                                             */
/*    FILE: NewmailIterate.cpp                                        */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "ACTable.h"
#include "NewmailIterate.h"
#include <string>
#include <sstream>
using namespace std;

//---------------------------------------------------------
// Constructor

NewmailIterate::NewmailIterate()
{
    m_count_i = 0;
    m_count_o = 0;
}

//---------------------------------------------------------
// Destructor

NewmailIterate::~NewmailIterate()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool NewmailIterate::OnNewMail(MOOSMSG_LIST &NewMail)
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
    else if(key == "I_COUNT"){
        stringstream ss;
        string str;    
        ss<<"OnNewMail"<<m_count_o;
        ss>>str;
        ss.clear();
        reportEvent(str);
        Notify("O_COUNT",str);
        m_count_o++;
    }
       
     else if(key != "APPCAST_REQ") // handled by AppCastingMOOSApp
       reportRunWarning("Unhandled Mail: " + key);
   }
  return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool NewmailIterate::OnConnectToServer()
{
   registerVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool NewmailIterate::Iterate()
{
  AppCastingMOOSApp::Iterate();
  // Do your thing here!
  stringstream ss;
  string str;
  ss<<"Iterate"<<m_count_i;
  ss>>str;
  ss.clear();
  reportEvent(str);
  m_count_i++;
  Notify("I_COUNT",str);
  AppCastingMOOSApp::PostReport();
  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool NewmailIterate::OnStartUp()
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
    Notify("NEWMAIL_ITERATE","start");
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

void NewmailIterate::registerVariables()
{
  AppCastingMOOSApp::RegisterVariables();
  // Register("FOOBAR", 0);
  Register("I_COUNT",0);
}


//------------------------------------------------------------
// Procedure: buildReport()

bool NewmailIterate::buildReport() 
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




