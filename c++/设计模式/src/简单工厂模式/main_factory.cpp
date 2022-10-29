
/**
 *	���ڴ��������������ʱ������Ӱ����ǰ��ϵͳ���롣����˼������һ��������
 *	�������������������ͬ���࣬Ȼ����ݲ�ͬ��� virtual �����õ���ͬ�Ľ����
 *	GOOD : �����ڲ�ͬ���������ͬ����ʱ
 *	BUG���ͻ��˱���Ҫ֪������͹����࣬����Բ�
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