/*

GOOD��������һ��һ�Զ�Ĺ�ϵ���ö���۲���󣨹�˾Ա����ͬʱ����һ��
����������飩 ���������״̬�����仯ʱ����֪ͨ���еĹ۲��ߣ�ʹ�����ܹ�������
����

*/

#include <iostream>
#include "Secretary.h"
using namespace std;

int main__Secretary(int argc, char **argv)
{

	Secretary * p = new Secretary();

	// �۲���
	StockObserver *s1 = new StockObserver("С��", p);
	StockObserver *s2 = new StockObserver("С��", p);

	// ����֪ͨ����
	p->Add(*s1);
	p->Add(*s2);

	// �¼�
	p->action = "�ϰ�����";

	// ֪ͨ
	p->Notify();

	// �¼�
	p->action = "�ϰ�������";

	// ֪ͨ
	p->Notify();

	delete p;
	delete s1;
	delete s2;

	return 0;
}