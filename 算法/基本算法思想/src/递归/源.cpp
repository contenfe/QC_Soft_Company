#include <iostream>

using namespace std;

unsigned int fac(int n)
{
	if (0 == n)
	{
		return 1;
	}

	// ����ʹ�� ��Ŀ����� ++ --
	return n * fac(n - 1);
}

unsigned int fbi(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}

	return fbi(n - 1) + fbi(n - 2);
}

// test ���Եݹ�
int main1(int argc, char **argv)
{
	unsigned char ch;
	char ch1 = 128;
	cout << (int)ch1 << endl;

	cout << fbi(3) << endl;

	cout << fac(2) << endl;

	//
	return 0;
}