#ifndef XY_POINTV2_HEADER
#define XY_POINTV2_HEADER

#include <string>

class XYPointV2{
    public:
        XYPointV2(){m_x=0;m_y=0;}
        XYPointV2(double x,double y){m_x=x;m_y=y;}
        ~XYPointV2(){}

        void set_vx(double v){m_x=v;}
        void set_vy(double v){m_y=v;}
        void set_label(std::string s){m_label=s;}

        std::string get_spec(std::string s=""); 
    
    
    private:
        double m_x;
        double m_y;
        std::string m_label;
};

#endif
