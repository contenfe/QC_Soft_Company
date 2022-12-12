#include <iostream>
#include "CSecretaryBase.h"
using namespace std;


int main(int argc, char **argv)
{
	SecretaryBase *p = new Secretary();
	
	CObserverBase *cb1 = new StockObserver("С��", p);
	CObserverBase *cb2 = new NBAObserver("С��", p);

	// ��ӵ���Ϣ����
	p->Attach(cb1);
	p->Attach(cb2);

	// �¼�
	(*p).action = "�ϰ�����";

	// ֪ͨ
	(*p).Notify();

	delete p;
	delete cb1;
	delete cb2;

	return 0;
}
