/*

GOOD�� ��һ�������ٴ�������һ���ɶ��ƵĶ��� ������֪���κδ�����ϸ�ڡ�
������ߴ��������ܡ� ˵���˾� COPY ��������һ������������ COPY ��һ�ݡ�

���

*/


#include<iostream>
#include "ProtoType.h"
#include "ConcreteProtoType1.h"
using namespace std;

int main(int argc, char **argv)
{

	ProtoType* p1 = new ConcreteProtoType1("С��");
	ProtoType* p2 = p1->Clone();

	p1->Show();
	p2->Show();

	return 0;
}