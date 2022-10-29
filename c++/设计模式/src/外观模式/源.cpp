/*

外观模式
GOOD：为子系统的一组接口提供一个一致的界面。使用户使用起来更加方便

*/

#include<iostream>
#include "Facade.h"

using namespace  std;


int main(int argc, char **argv)
{
	Facade* f = new Facade;
	f->FacadeMethod();

	return 0;
}
