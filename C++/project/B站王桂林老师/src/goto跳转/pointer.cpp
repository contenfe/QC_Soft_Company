#include<iostream>
#include<malloc.h>
#include<stdlib.h>
using namespace std;

int main_pointer()
{
	int *array;


	array = (int *)calloc(10, sizeof(int));
	memset(array, 1, sizeof(int) * 10);
	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	int *array1 = (int *)realloc(array, sizeof(int) * 20);
	//memcpy(array1, array, 10 * sizeof(int));
	if (array1!=nullptr) 
	{
		for (int i = 0; i < 20; i++)
		{
			cout << *(array1 + i) << " ";
		}
		cout << endl;
		free(array);
	}


	char *pa;
	pa = (char *)malloc(sizeof(char) * 20);
	memset(pa, 'a', 20 * sizeof(char));
	*(pa + 19) = '\0';

	cout << pa << endl;
	
	/*for (int i = 0; i < 4; i++)
	{
		cout << *(pa + i) << " ";
	}*/

	cout << endl;



	const char * pc = "hello world";

	const char *name[] = { "apple","pear" };

	cout << name[1] << endl;

	char ch;
	int a;

	/*cin >> ch;
	a = ch - '0';
	cout << a << endl;*/
	return 0;
}