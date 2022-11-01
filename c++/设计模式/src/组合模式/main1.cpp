#include<iostream>
#include"model.h"
using namespace std;


int main_11_1()
{
	
	ConcreteCompany* p = new ConcreteCompany("清华大学");
	p->Add(new HrDepartment("清华大学人才部"));

	ConcreteCompany* p1 = new ConcreteCompany("数学系");
	p1->Add(new HrDepartment("数学系人才部"));

	ConcreteCompany* p2 = new ConcreteCompany("物理系");
	p2->Add(new HrDepartment("物理系人才部"));

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