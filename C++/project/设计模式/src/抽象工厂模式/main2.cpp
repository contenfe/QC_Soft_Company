#include <iostream>
#include "CSecretaryBase.h"
using namespace std;


int main(int argc, char **argv)
{
	SecretaryBase *p = new Secretary();
	
	CObserverBase *cb1 = new StockObserver("小李", p);
	CObserverBase *cb2 = new NBAObserver("小王", p);

	// 添加到消息队列
	p->Attach(cb1);
	p->Attach(cb2);

	// 事件
	(*p).action = "老板来了";

	// 通知
	(*p).Notify();

	delete p;
	delete cb1;
	delete cb2;

	return 0;
}
