#include <iostream>
#include "CFileUtil.h"
#pragma warning(disable:4996)
using namespace std;


void InsertSort(int *pArray, int len)
{
	int index = 0;

	int j;
	for (int i = 1; i < len; i++)
	{
		j = i;
		while (j > 0)
		{
			if (*(pArray + j) < *(pArray + j - 1))
			{
				int temp = *(pArray + j);
				*(pArray + j) = *(pArray + j - 1);
				*(pArray + j - 1) = temp;
			}
			j--;
		}
	}
}

void InsertSort2(int *p, int len)
{

	for (int i = 1; i < len; i++)
	{
		int key = *(p + i);
		int j = i-1;
		while (j > 0 && p[j] > key)
		{
			p[j + 1] = p[j];
			j--;
		}
		p[j+1] = key;
	}
}

int main1(int argc, char **argv)
{
	int *p;
	
	//int len
	CFileUtil* instance = CFileUtil::getInstance();

	//instance->writeArray();
	instance->readArray();
	//instance->PrintArray();

	// 方法1
	p = instance->getArray();
	//int a[DEFAULTSIZE] = *instance->getArray();
	InsertSort2(p, DEFAULTSIZE);
	instance->Print(p, DEFAULTSIZE);

	//  TODO: 方法2
	//InsertSort(*instance->getArray(), DEFAULTSIZE);
	//instance->Print(*instance->getArray(), DEFAULTSIZE);
	return 0;
}

void main2()
{
	char ** txt = NULL;
	CFileUtil::getInstance()->readFile2Mem(&txt, "开局夺舍大长老1.txt");
	CFileUtil::getInstance()->writeFile2Men();
	/*while (*txt)
	{
		printf("%s", *txt++);
	}*/

}


void main3()
{
	int s[10][12];

	//int **p = &s[0];
}


#define F_PRINT_ERR(e) \
do\
{\
	if (e == NULL)\
	{\
		printf("open error");\
		exit(-1);\
	}\
} while (0)

void main4()
{

#if 1
	int lineCount = 0;
	char buf[1024];
	char **content;

	FILE* pfr = fopen("文件.txt", "r");
	F_PRINT_ERR(pfr);
	while (fgets(buf, 1024, pfr))
	{
		lineCount++;
	}
	rewind(pfr);
	content = (char **)malloc(sizeof(char *)*(lineCount + 1));
	char ** t = content;
	while (fgets(buf, 1024, pfr))
	{
		int n = strlen(buf);
		*content = (char *)malloc(n + 1);
		strcpy(*content, buf);
		content++;
	}
	*content = nullptr;



	FILE * pfw = fopen("文件", "w+");
	F_PRINT_ERR(pfw);


	while (fputs(*t, pfw) != EOF)
	{
		*t++;
	}

	fclose(pfr);
	fclose(pfw);

#endif

#if 0
	FILE* pf = fopen("xx.txt", "w+");
	F_PRINT_ERR(pf);

#endif

#if 0
	int s[21];
	int sa[3][4]{ 0 };
	int(*p)[4]= &sa[0];
	//p = sa;

	cout << sizeof(*p) << endl;

	char ch[] = { "abc\0def" };// 8
	char *pch = ch;
	cout << sizeof ch / sizeof ch[0] << endl;
	cout << ch << endl;
	cout << strlen(pch) << endl;
	cout << sizeof &pch << endl;
#endif

}