

/**
 *	�����㷨���壬�ֱ��װ������������֮����Ի����滻�����㷨�仯������Ӱ�쵽�û�
 *	GOOD:�ʺ����еĳ�Ա�Է���Ϊ�����㷨�����䶯�����˵�Ԫ���ԣ���Ϊÿ���㷨�����Լ����࣬����ͨ���Լ��Ľӿڵ������ԡ�
 *	����ģʽ�ͼ򵥹���������ͬ�����򵥹���ģʽֻ�ܽ�����󴴽����⣬���ھ����䶯���㷨Ӧʹ�ò���ģʽ��
 *	BUG:�ͻ���Ҫ�����ж�
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
	cout << "���������";
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