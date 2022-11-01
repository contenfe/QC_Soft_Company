/*

	GOOD：双方都不适合修改的时候，可以考虑使用适配器模式 


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
	Player * p = new TransLater("小王");
	p->Attack();

	return 0;
}