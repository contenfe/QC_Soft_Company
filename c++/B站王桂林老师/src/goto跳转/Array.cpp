#include <stdio.h>
#include "Pre.h"

#pragma DISABLE(4996)

//���� ��Ҫ�ؾ���
//��ʼλ�ã��Ʋ��̶ȣ���ֹλ�ã���Χ����

// ��λ����
int main_array2()
{
	int arr[3][4]; // ===> int[4]  arr[3]; T
	int sie;
	scanf("%d", &sie);
	//int ar[sie];

	return 0;
}

// һά����
int main_array1()
{

	int arry[10]{
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		10,
	};

	printf("%d ", arry[9]);
	return 0;
}