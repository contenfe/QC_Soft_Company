#include<stdio.h>
#include<iostream>
#include"Pre.h"

#pragma DISABLE(4996)

#define OPENFILE(n,m)\
{\
fopen(n, m)\
}

using namespace std;

void Fgetc(FILE * &p)
{
	char ch;
	
	while ((ch = fgetc(p)) != EOF)
	{
		cout << ch << " ";
	}

	cout << endl;
}

void getLine(FILE * pf)
{
	char ch[1024];
	char *ptr;

	char **pstr;
	// 读取行
	char pch[1024];
	int numline = 0;
	while (fgets(pch, 1024, pf) != 0)
	{
		numline++;
	}
	//for(int /*numline*/=0;;)
	cout << numline << endl;
	rewind(pf);

	pstr = (char **)malloc(numline+1);

	char *pcol;
	int i = 0;
	memset(pch, '\0', 1024);
	while ((pcol = fgets(pch, 1024, pf)) != 0)
	{
		int len = strlen(pch);
		*(pstr + i) = (char*)malloc(len+1);
		i++;
		memcpy(*(pstr + i), pch, len);
		*(pstr + len) = '\0';

	}

	return;

	while ((ptr = fgets(ch, 1024, pf)) != 0)
	{

		cout << ptr << endl;
	}


}

void writeLine(FILE * &pw)
{
	char ch[] = "啊大大是的发送到发萨达是的发送到发送到发送到发大发嘻嘻嘻\n";
	fputs(ch, pw);
	char ch1[] = "阿达的的发送到发送到发送到发大发\n";
	fputs(ch1, pw);
}

void test()
{
	FILE* fss = OPENFILE("22", "r+");
	if (fss == nullptr)
		return;
	//fputs("hello CC", fss);

	char buf[1024];
	cout<<fgets(buf, 3, fss)<<endl;
	cout << fgets(buf, 3, fss) << endl;
	fclose(fss);
}

// 写小说
void writeStory()
{
	FILE *pfr = fopen("123.txt", "r+");
	FILE *pfw = fopen("小说.txt", "w+");

	//char* const ch = '\n';
	char buf[1024];
	int num = 0;
	while (fgets(buf, 1024, pfr) != NULL)
	{
		num++;
		fputs(buf, pfw);
	}

	rewind(pfr);
	rewind(pfw);
	int numline = 0;
	while (fgets(buf, 1024, pfw) != nullptr)
	{
		numline++;
	}

	cout <<num<<"  " <<numline << endl;
	fclose(pfr);
	fclose(pfw);
}

int main(int argc, char **argv)
{
#if 1

	char c = 'a';
	cout << (int)c << endl;
	writeStory();
	return 0;


#endif
	
	
	FILE *pfr = fopen("123.txt", "r+");
	FILE *pfw = fopen("11.txt", "w+");

	//Fgetc(pfr);
	getLine(pfr);

	//writeLine(pfw);
	fclose(pfr);
	fclose(pfw);

	return 0;
}