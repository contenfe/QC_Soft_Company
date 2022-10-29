/*

动态地给一个对象添加一些额外的职责（不重要的功能，只是偶然一次要执行） ，就增
加功能来说，装饰模式比生成子类更为灵活。建造过程不稳定，按正确的顺序串联起来进行
控制。

GOOD:当你向旧的类中添加新代码时，一般是为了添加核心职责或主要行为。而当需
要加入的仅仅是一些特定情况下才会执行的特定的功能时（简单点就是不是核心应用的功
能），就会增加类的复杂度。装饰模式就是把要添加的附加功能分别放在单独的类中，并让
这个类包含它要装饰的对象，当需要执行时，客户端就可以有选择地、按顺序地使用装饰功
能包装对象。

*/
#pragma once
#include<iostream>
#include "CPerson.h"
#include "CBigTrouser.h"
#include "TShirts.h"

using namespace std;

int main(int argc, char **argv)
{
	CPerson* person = new CPerson("小李子");
	CBigTrouser* bt = new CBigTrouser();
	TShirts *ts = new TShirts();

	bt->Decorate(person);
	ts->Decorate(bt);

	ts->Show();
	

	return 0;
}