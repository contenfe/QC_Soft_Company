/*

	GOOD��˫�������ʺ��޸ĵ�ʱ�򣬿��Կ���ʹ��������ģʽ 


*/


#include <iostream>
#include "CAdapt.h"
#include "Adapat.h"
using namespace std;

// CAdapte
int main__CAdapte(int argc, char **argv)
{
	Adapter *ada = new Adapter();
	ada->Request();
	delete ada;

	return 0;
}

// Adapat
int main(int argc, char **argv)
{
	Player * p = new TransLater("С��");
	p->Attack();

	return 0;
}