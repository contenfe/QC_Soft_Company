/*

GOOD：定义了一种一对多的关系，让多个观察对象（公司员工）同时监听一个
主题对象（秘书） ，主题对象状态发生变化时，会通知所有的观察者，使它们能够更新自
己。

*/

#include <iostream>
#include "Secretary.h"
using namespace std;

int main__Secretary(int argc, char **argv)
{

	Secretary * p = new Secretary();

	// 观察者
	StockObserver *s1 = new StockObserver("小李", p);
	StockObserver *s2 = new StockObserver("小王", p);

	// 加入通知队列
	p->Add(*s1);
	p->Add(*s2);

	// 事件
	p->action = "老板来了";

	// 通知
	p->Notify();

	// 事件
	p->action = "老板娘来了";

	// 通知
	p->Notify();

	delete p;
	delete s1;
	delete s2;

	return 0;
}