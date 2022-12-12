#include<iostream>
#include<thread>

using namespace std;


void test()
{
	cout << "test" << endl;
}


int main(int argc, char** argv)
{

	int a;
	thread t(test);
	cin >> a;
	cout << a << endl;
	t.join();


	return 0;
}
