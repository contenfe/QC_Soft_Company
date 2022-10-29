//#include<iostream>
#include<stdio.h>
#include<stdlib.h>


int main_goto()
{
END:
	//std::cout << "ehll" << std::endl;
	printf("hello\n");
	//sleep(1);
	for (int i = 0; i < 12; i++)
	{
		if (i == 9)
			goto END;
	}

	return 0;
}