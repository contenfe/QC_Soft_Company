#include <iostream>
using namespace std;

// �˻ʺ�����

// ��������
int getPower(int num, int exp)
{
	if (num <= 0)
	{
		return -1;
	}
	if (exp == 0)
	{
		return 1;
	}
	if (exp == 1)
	{
		return num;
	}

	return num * getPower(num, exp - 1);
}

int main(int argc, char **argv)
{
	cout << getPower(2, 1) << endl;
	return 0;
}