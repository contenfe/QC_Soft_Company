#include<iostream>
using namespace std;

void test()
{
	cout << "test()" << endl;
}

void test(int i)
{
	cout << "test() - int" << endl;
}

void test(int i,double d=20)
{
	cout << "test() - double" << endl;
}

int main()
{
	int array[]{ 1,2,3,4,5 };
	int a = 0;

	int b = a + 1;
	test();
	//test(1);
	test(1,20);

	cout << b << endl;
	return 0;
}
