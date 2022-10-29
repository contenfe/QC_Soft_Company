
/*

工厂方法模式
GOOD：修正了简单工厂模式中不遵守开放－封闭原则。工厂方法模式把选择判
断移到了客户端去实现，如果想添加新功能就不用修改原来的类，直接修改客户端即可。

*/


#include<iostream>
#include "LeiFengFactory.h"
#include "StudentLeiFengFactory.h"
#include "VolenterFactory.h"

using namespace std;


int main(int argc, char **argv)
{
	LeiFengFactory * lfFactory = new VolenterFactory();
	LeiFengFactory * lfFactory2 = new StudentFactory();
	LeiFeng* lf = lfFactory->CreateLeiFeng();
	lf->Sweep();
	delete lf;

	lf = lfFactory2->CreateLeiFeng();
	lf->Sweep();

	delete lf;
	delete lfFactory;
	delete lfFactory2;

	system("pause");
	return 0;
}