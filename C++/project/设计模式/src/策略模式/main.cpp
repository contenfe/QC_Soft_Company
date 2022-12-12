

/**
 *	定义算法家族，分别封装起来，让它们之间可以互相替换，让算法变化，不会影响到用户
 *	GOOD:适合类中的成员以方法为主，算法经常变动；简化了单元测试（因为每个算法都有自己的类，可以通过自己的接口单独测试。
 *	策略模式和简单工厂基本相同，但简单工厂模式只能解决对象创建问题，对于经常变动的算法应使用策略模式。
 *	BUG:客户端要做出判断
 */


#include<iostream>
#include "CContext.h"
#include "CAddOperation.h"
#include "CContext2.h"


using namespace std;

int main_Context1(int argc, char **argv)
{
	int a, b;
	char c;
	cin >> a >> b;
	cout << "输入运算符";
	cin >> c;

	switch (c)
	{
	case '+':
		CContext *context = new CContext(new CAddOperation(a,b));
		cout << context->GetResult() << endl;
		break;

	}

	return 0;
}



int main(int argc, char **argv)
{
	int a, b;
	cin >> a >> b;
	CContext2 *contxt = new CContext2('+');
	cout << contxt->GetResult() << endl;

	return 0;
}