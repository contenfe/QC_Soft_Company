#include <stdio.h>
#include "Pre.h"

#pragma DISABLE(4996)

//数组 三要素就是
//起始位置，移步刻度，终止位置（范围）。

// 二位数组
int main_array2()
{
	int arr[3][4]; // ===> int[4]  arr[3]; T
	int sie;
	scanf("%d", &sie);
	//int ar[sie];

	return 0;
}

// 一维数组
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