#include<iostream>

using namespace std;


void result(int s, int b, void (*sum)(int, int))
{
	cout << s * b << endl;

	sum(s, b);
}

int sum(int a, int b);

int main()
{
	int a = [=]()->int{
		return 12;
	}();

	int b = 100;
	result(a, b, [](int a, int b) {cout << a + b << endl; });

	cout << "sum: " << sum(39 , 11) << endl;



	return 0;
}
