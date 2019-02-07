#ifndef MYDATA_HEADER
#define MYDATA_HEADER

#include "MBUtils.h"
#include <string>

class MyData
{
    public:
        MyData();
        ~MyData();
    
    public:
        void SetOrin(std::string);
        std::string GetOrin();
        void decode();
        void SetDist(double);
        double GetDist();
        double GetX();
        double GetY();
        void SetID(std::string);
        void SetVisited(std::string);
        std::string GetID();
        std::string Report();
    
    private:
        std::string m_origin_string;
        double m_x;
        double m_y;
        double m_distance;
        std::string m_visited;
        std::string m_id;    
};
#endif

