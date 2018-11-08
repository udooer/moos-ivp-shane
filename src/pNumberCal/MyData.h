#ifndef MYDATA_HEADER
#define MYDATA_HEADER
#include <iostream>
#include <stdint.h>

class MyData 
{
    public:

        MyData();
        ~MyData();

        void            SetOrin(uint64_t);
        bool            CheckIfOdd();
        std::string     Report();
        void            GetTimeSpend(float);

    protected:

        uint64_t m_origin_num;
        float m_timeuse;
        bool m_if_odd;
};
#endif
