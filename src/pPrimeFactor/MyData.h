#ifndef MYDATA_HEADER
#define MYDATA_HEADER

#include <iostream>
#include <stdint.h>
#include <vector>

class MyData 
{
    public:
        MyData();
        ~MyData();

        void SetOrin(uint64_t);
        void SetRece(int);
        void SetCalcul(int);
        void SetUseTime(float);
        bool CheckPrime();
        std::string Report();

    private:
        uint64_t m_origin_num;
        uint64_t m_temp_num;
        uint64_t m_pre_primes;
        uint64_t m_limit;

        int m_received_num;
        int m_calcul_num;
        double m_timeuse;
        bool m_if_prime;
        bool m_if_done;
        std::vector<uint64_t> primes;
};
#endif
