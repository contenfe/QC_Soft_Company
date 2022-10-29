
/**
 *	用于创建对象。新添加类时，不会影响以前的系统代码。核心思想是用一个工厂来
 *	根据输入的条件产生不同的类，然后根据不同类的 virtual 函数得到不同的结果。
 *	GOOD : 适用于不同情况创建不同的类时
 *	BUG：客户端必须要知道基类和工厂类，耦合性差
 */

#include<iostream>
#include "CCalculatorFactory.h"
using namespace std;

int main_Factory(int argc, char **argv)
{
	COperation* oper1 = CCalculatorFactory::Create('+');
	COperation* oper2 = CCalculatorFactory::Create('-');

	oper1->SetArg(12, 123);

	oper2->SetArg(50, 13);

	cout << "oper1:" << oper1->GetResult() << " oper2:" << oper2->GetResult() << endl;

	return 0;
}