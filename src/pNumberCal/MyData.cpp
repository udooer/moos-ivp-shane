#include "MyData.h"
#include <iostream>
#include <sstream>

using namespace std;

MyData::MyData()
{
    m_origin_num = 0;
    m_timeuse = 0;

}

MyData::~MyData()
{

}

void MyData::SetOrin(uint64_t input)
{
    m_origin_num = input;
}

bool MyData::CheckIfOdd()
{
    if(m_origin_num%2 == 0)
       m_if_odd = false;
    else
       m_if_odd = true;
   return m_if_odd; 
}

string MyData::Report()
{
    stringstream ss;
    string type;
    string output;

    if(m_if_odd)
        type="odd";
    else
        type="even";

    ss<<"Original_Number:"<<m_origin_num<<","<<type<<",calculate_time:"<<m_timeuse;

    ss>>output;

    return output;
}

void MyData::GetTimeSpend(float time)
{
    m_timeuse = time;
}


