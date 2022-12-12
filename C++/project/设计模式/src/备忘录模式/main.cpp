/*

备忘录模式
GOOD：在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个
状态，这样就可以将以后的对象状态恢复到先前保存的状态。

适用于功能比较复杂的，但需要记录或维护属性历史的类；或者需要保存的属性只是众
多属性中的一小部分时 Originator 可以根据保存的 Memo 还原到前一状态


*/


#include <iostream>
#include "BackUp.h"
using namespace std;

int main(int argc, char **argv)
{
	Originator * on = new Originator;
	on->state = "on";
	on->Show();

	Caretaker * c = new Caretaker;
	c->memo = on->CreateMemo();
	on->state = "off";
	on->Show();

	on->SetMemo(c->memo);
	on->Show();

	return 0;
}