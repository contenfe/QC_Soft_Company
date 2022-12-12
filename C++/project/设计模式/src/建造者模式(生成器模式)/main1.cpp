/*

������ģʽ��������ģʽ��
GOOD�� �ڵ��������Ӷ�����㷨Ӧ�ö����ڸö������ɲ����Լ����ǵ�װ��
��ʽʱ����

*/


#include "Direct.h"
#include <iostream>
#include "ConcreteBuilder1.h"
#include "ConcreteBuilder2.h"

using namespace std;

int main__Builder1(int argc, char **argv)
{

	Direct *p = new Direct();

	Builder *b1 = new ConcreteBuilder1();
	Builder* b2 = new ConcreteBuilder2();

	p->Construct(b1);
	Product* pb1 = b1->GetResult();
	pb1->Show();

	p->Construct(b2);
	Product* pb2 = b2->GetResult();
	pb2->Show();


	delete p;
	delete b1;
	delete b2;

	return 0;
}

