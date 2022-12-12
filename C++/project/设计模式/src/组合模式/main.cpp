/*

组合模式
GOOD：整体和部分可以被一致对待（如 WORD 中复制一个文字、一段文字、
一篇文章都是一样的操作）


*/


#include<iostream>
#include "composite.h"
using namespace std;

int m__composite__(int argc, char **argv)
{
	Composite* p = new Composite("小王");

	p->Add(new Left("小李"));
	p->Add(new Left("小赵"));

	Composite* p1 = new Composite("小小五");
	p1->Add(new Left("大三"));

	p->Add(p1);
	p->Display(1);
	return 0;
}