#include <sstream>
#include "XYPointV2.h"
using namespace std;

string XYPointV2::get_spec(string cmd)
{
    stringstream ss;
    string s;
    ss<<"x="<<m_x<<",y="<<m_y<<",label="<<m_label<<","<<cmd;
    ss>>s;ss.clear();
    return s;
}
