/*

���ģʽ
GOOD������Ͳ��ֿ��Ա�һ�¶Դ����� WORD �и���һ�����֡�һ�����֡�
һƪ���¶���һ���Ĳ�����


*/


#include<iostream>
#include "composite.h"
using namespace std;

int m__composite__(int argc, char **argv)
{
	Composite* p = new Composite("С��");

	p->Add(new Left("С��"));
	p->Add(new Left("С��"));

	Composite* p1 = new Composite("СС��");
	p1->Add(new Left("����"));

	p->Add(p1);
	p->Display(1);
	return 0;
}