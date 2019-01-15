/************************************************************/
/*    NAME: handsomeshane                                              */
/*    ORGN: MIT                                             */
/*    FILE: Test.cpp                                        */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "Test.h"

using namespace std;

//---------------------------------------------------------
// Constructor

Test::Test()
{
  k = 0.0;
  l = 0.0;
  count = 0;
  count_2 = 0; 
}

//---------------------------------------------------------
// Destructor

Test::~Test()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool Test::OnNewMail(MOOSMSG_LIST &NewMail)
{
  MOOSMSG_LIST::iterator p;
   
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;
    string key = msg.GetKey();
    if(key == "TESTING")
    {
	cout<<"hello:"<<count<<endl;
	k = atof(msg.GetString().c_str());
        count = count + 1;
    }
    if(key == "TESTING_2")
    {
	cout<<"hey bro:"<<count_2<<endl;
//	l = atoi(msg.GetString().c_str());
	l = msg.GetDouble();
        count_2 = count_2 + 1; 
    }
#if 0 // Keep these around just for template
    string key   = msg.GetKey();
    string comm  = msg.GetCommunity();
    double dval  = msg.GetDouble();
    string sval  = msg.GetString(); 
    string msrc  = msg.GetSource();
    double mtime = msg.GetTime();
    bool   mdbl  = msg.IsDouble();
    bool   mstr  = msg.IsString();
#endif
   }
	
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool Test::OnConnectToServer()
{
   // register for variables here
   // possibly look at the mission file?
   // m_MissionReader.GetConfigurationParam("Name", <string>);
   // m_Comms.Register("VARNAME", 0);
	
   RegisterVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool Test::Iterate()
{ 
  Notify("PUB_TEST",k);
  Notify("PUB_TEST_2",l);
  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool Test::OnStartUp()
{
  list<string> sParams;
  m_MissionReader.EnableVerbatimQuoting(false);
  if(m_MissionReader.GetConfiguration(GetAppName(), sParams)) {
    list<string>::iterator p;
    for(p=sParams.begin(); p!=sParams.end(); p++) {
      string line  = *p;
      string param = tolower(biteStringX(line, '='));
      string value = line;
      
      if(param == "foo") {
        //handled
      }
      else if(param == "bar") {
        //handled
      }
    }
  }
  
  RegisterVariables();	
  return(true);
}

//---------------------------------------------------------
// Procedure: RegisterVariables

void Test::RegisterVariables()
{  
  Register("TESTING",0);
  Register("TESTING_2",0);
  // Register("FOOBAR", 0);
}

