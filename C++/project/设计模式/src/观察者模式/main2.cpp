#include <iostream>
#include "CSecretaryBase.h"
using namespace std;
// test
int mai_123n()
{
	Secretary *p = new Secretary();

	if (nullptr == p)
	{

		return 12;
	}

	StockObserver *cb1 = new StockObserver("小李", p);
	NBAObserver *cb2 = new NBAObserver("小王", p);

	cb1->Update();
	cb2->Update();

	p->Attach(cb1);
	p->Attach(cb2);

	p->action = "老板来了";

	p->Notify();

	return 0;
}

int main(int argc, char **argv)
{
	SecretaryBase *p = new Secretary();
	if (nullptr != p)
	{
		cout << "not null" << endl;
	}
	else
	{
		cout << "is null" << endl;
		abort();
	}
	CObserverBase *cb1 = new StockObserver("小李", p);
	CObserverBase *cb2 = new NBAObserver("小王", p);

	if (nullptr != cb1 && nullptr != cb2)
	{
		cout << "not null" << endl;
	}
	else
	{
		cout << "is null" << endl;
		abort();
	}

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
