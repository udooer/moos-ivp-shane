#include "MyData.h"
#include <cmath>
#include <sstream>
using namespace std;

MyData::MyData()
{

    m_origin_num = 0;
    m_temp_num = 0;
    m_pre_primes = 2;
    m_limit = 0;
    m_received_num = 0;
    m_calcul_num = 0;
    m_timeuse = 0;
    primes.clear();
    m_if_done = false;
}

MyData::~MyData()
{

}

void MyData::SetOrin(uint64_t num)
{
    m_origin_num = num;
    m_temp_num = num;
    m_limit = int(sqrt(num));
}

void MyData::SetRece(int count)
{
    m_received_num = count;
}

void MyData::SetCalcul(int count)
{
    m_calcul_num = count;
}

void MyData::SetUseTime(float time)
{
    m_timeuse += time;
}

bool MyData::CheckPrime()
{
    
    uint64_t count=0;

    
    for(uint64_t i=m_pre_primes;i<=m_limit;)
    {
        if(m_temp_num%i==0)
        {
            primes.push_back(i);
            m_temp_num /= i;
        }
        else
            i++;
        count++;
        if(count>100000)
        {
            m_pre_primes = i;
            return false;
        }
    }
    if(m_temp_num!=1)
        primes.push_back(m_temp_num);
    m_if_done = true;
    return true;
}

string MyData::Report()
{
    stringstream ss;
    ss<<"primes=";
    for(int i=0;i<primes.size();i++)
    {
        ss<<primes.at(i);
        if(i!=primes.size()-1)
            ss<<":";
    }
    string str_primes;
    ss>>str_primes;
    stringstream ss_ans;
    ss_ans<<"orig="<<m_origin_num<<",received="<<m_received_num<<",calculated="<<m_calcul_num<<",solve_time="<<m_timeuse<<","<<str_primes<<",username=handsomeshane";
    string ans;
    ss_ans>>ans;
    return ans;
}
