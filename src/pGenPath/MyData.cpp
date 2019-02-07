#include "MyData.h"
#include <iostream>
#include <sstream>
#include <string>

MyData::MyData()
{
    m_origin_string = "";
    m_id = "";
    m_visited = false;
}

MyData::~MyData()
{
}

void MyData::SetOrin(std::string input)
{
    m_origin_string = input;
}

std::string MyData::GetOrin()
{
    return m_origin_string;
}

void MyData::decode()
{
    std::string x;
    std::string y;
    std::string id;
    std::stringstream ss;
    
    std::string tmp;
    tmp = m_origin_string;
    x = tokStringParse(tmp, "x", ',', '=');
    if(x!="")
    {
        ss<<x;
        ss>>m_x;
        ss.clear();
    }
    y = tokStringParse(tmp, "y", ',', '=');
    if(y!="")
    {
        ss<<y;
        ss>>m_y;
        ss.clear();
    }
    id = tokStringParse(tmp, "id", ',', '=');
    if(id!="")
        m_id = id;
}

void MyData::SetDist(double d)
{
    m_distance = d;
}

double MyData::GetDist()
{
    return m_distance;
}

double MyData::GetX()
{
    return m_x;
}

double MyData::GetY()
{
    return m_y;
}

std::string MyData::GetID()
{
    return m_id;
}

void MyData::SetVisited(std::string v)
{
    m_visited = v;
}

std::string MyData::Report()
{
    std::stringstream ss;
    std::string s;
    ss<<"origin_point:"<<m_origin_string<<",visit:"<<m_visited<<",distance:"<<m_distance;
    ss>>s;
    return s;
}
