/************************************************************/
/*    NAME: hs                                              */
/*    ORGN: NTU                                             */
/*    FILE: Chirp.cpp                                        */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include <ctime>
#include <cstdlib>
#include "MBUtils.h"
#include "ACTable.h"
#include "Chirp.h"

using namespace std;

//---------------------------------------------------------
// Constructor

Chirp::Chirp()
{
    m_loiter = "";
    m_chirp  = "";
    m_station = "";
}

//---------------------------------------------------------
// Destructor

Chirp::~Chirp()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool Chirp::OnNewMail(MOOSMSG_LIST &NewMail)
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
    bool handled;
     if(key == "FOO") 
       cout << "great!";
     else if(key == "LOITER")
     {
         m_loiter = msg.GetString();
         handled = true;
     }
     else if(key == "CHIRP")
     {
         m_chirp = msg.GetString();
         handled = true;
     }
     else if(key =="STATION_KEEP")
     {
         m_station = msg.GetString();
         handled = true;
     }
     else if(!handled) // handled by AppCastingMOOSApp
       reportRunWarning("Unhandled Mail: " + key);
   }
	
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool Chirp::OnConnectToServer()
{
   registerVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool Chirp::Iterate()
{
  AppCastingMOOSApp::Iterate();
  // Do your thing here!
  string str= "aplay Chirp.wav";
  const char *filename = str.c_str();

  if(m_loiter=="true" && m_chirp=="true" && m_station=="false"){
      system(filename);
//      sleeptime(1900);
  }
  AppCastingMOOSApp::PostReport();
  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool Chirp::OnStartUp()
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

void Chirp::registerVariables()
{
  AppCastingMOOSApp::RegisterVariables();
  Register("CHIRP", 0);
  Register("LOITER", 0);
  Register("STATION_KEEP", 0);
  // Register("FOOBAR", 0);
}


//------------------------------------------------------------
// Procedure: buildReport()

bool Chirp::buildReport() 
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

//void Chirp::sleeptime(int msec)
//{
//    clock_t time_end;
//    time_end = clock() + CLOCKS_PER_SEC/1000*msec;
//    reportEvent("sleep!!\n");
//    while(clock() < time_end)
//    {
//    }
//}



