#include <iostream>
#include<thread>
#include"graph.h"
using namespace std;

class CCar
{
private:
    string m_carnumber;                                             // ���ƺ�
    unsigned int m_carId;                                                    // ���������֤��
public:
    string getCarNumber()const
    {
        if("" == m_carnumber)
        {
            return "��δ¼��ó�����Ϣ";
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
