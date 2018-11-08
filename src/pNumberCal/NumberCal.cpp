/************************************************************/
/*    NAME: handsomeshane                                              */
/*    ORGN: MIT                                             */
/*    FILE: NumberCal.cpp                                        */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "ACTable.h"
#include "NumberCal.h"

using namespace std;

//---------------------------------------------------------
// Constructor

NumberCal::NumberCal()
{
    m_input_buf_list.clear();
}

//---------------------------------------------------------
// Destructor

NumberCal::~NumberCal()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool NumberCal::OnNewMail(MOOSMSG_LIST &NewMail)
{
  AppCastingMOOSApp::OnNewMail(NewMail);

  MOOSMSG_LIST::iterator p;
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;
    string key    = msg.GetKey();
    MyData num_cls;
    if(key == "NUM_VALUE")
    {
        stringstream ss;
        uint64_t input;
        ss<<msg.GetString();
        ss>>input;
        num_cls.SetOrin(input);
        m_input_buf_list.push_back(num_cls);    
    }
#if 0 // Keep these around just for template
    string comm  = msg.GetCommunity();
    double dval  = msg.GetDouble();
    string sval  = msg.GetString(); 
    string msrc  = msg.GetSource();
    double mtime = msg.GetTime();
    bool   mdbl  = msg.IsDouble();
    bool   mstr  = msg.IsString();
#endif

     else if(key == "FOO") 
       cout << "great!";

     else if(key != "APPCAST_REQ") // handled by AppCastingMOOSApp
       reportRunWarning("Unhandled Mail: " + key);
   }
	
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool NumberCal::OnConnectToServer()
{
   registerVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool NumberCal::Iterate()
{
  AppCastingMOOSApp::Iterate();
  // Do your thing here!
  double tic,toc;
  if (!m_input_buf_list.empty())
  {
      list<MyData>::iterator p;
      for(p=m_input_buf_list.begin();p!=m_input_buf_list.end();)
      {
          tic = MOOSTime();
          p->CheckIfOdd();
          toc = MOOSTime();
          p->GetTimeSpend(toc-tic);
          string output = p->Report();
          Notify("RESULT",output);
          m_input_buf_list.erase(p++);
      }
  }
  AppCastingMOOSApp::PostReport();
  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool NumberCal::OnStartUp()
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

void NumberCal::registerVariables()
{
  AppCastingMOOSApp::RegisterVariables();
  Register("NUM_VALUE", 0);
  // Register("FOOBAR", 0);
}


//------------------------------------------------------------
// Procedure: buildReport()

bool NumberCal::buildReport() 
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


