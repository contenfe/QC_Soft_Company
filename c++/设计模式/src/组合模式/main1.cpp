#include<iostream>
#include"model.h"
using namespace std;


int main_11_1()
{
	
	ConcreteCompany* p = new ConcreteCompany("�廪��ѧ");
	p->Add(new HrDepartment("�廪��ѧ�˲Ų�"));

	ConcreteCompany* p1 = new ConcreteCompany("��ѧϵ");
	p1->Add(new HrDepartment("��ѧϵ�˲Ų�"));

	ConcreteCompany* p2 = new ConcreteCompany("����ϵ");
	p2->Add(new HrDepartment("����ϵ�˲Ų�"));

	p->Add(p1);
	p->Add(p2);

	p->Display(1);
	p->LineOfDuty();

	return 0;
}

int main()
{

	cout << "hello worlds" << endl;

	return 0;
}