#include <iostream>
#include<thread>
#include"graph.h"
using namespace std;

class CCar
{
private:
    string m_carnumber;                                             // 车牌号
    unsigned int m_carId;                                                    // 车主人身份证号
public:
    string getCarNumber()const
    {
        if("" == m_carnumber)
        {
            return "暂未录入该车辆信息";
        }
    }
    unsigned int getCarID()const
    {
        if(0 == m_carId)
            return -1;
    }

    void setCarNumber(string str)
    {
        this.m_carnumber = str;
    }

    void setCarID(unsigned int id)
    {

        this.m_carId=id;
    }

};


void test()
{

    cout<<"hello"<<endl;
}

int main()
{
    listUDG d;

    thread t(test);
//    t.j

    return 0;
}
