#include<iostream>
#include"math.h"
using namespace std;


#define add(a) a + a

int main()
{

	//int a = 10;
	//int b = ++a + ++a;//add(++a); // ++a+++a
	//int c = a+++b;

	int a = 1;
	int b = 2;
	(a = b) = 4;
	cout << a << " " << b << endl;
	cout << sum(2, 3) << endl;
	cout << detal(15, 5) << endl;
	return 0;
}