#include "CFileUtil.h"
#include<malloc.h>
#include <string.h>
#pragma warning(disable:4996)

CFileUtil* CFileUtil::instance = nullptr;

CFileUtil* CFileUtil::getInstance()
{
	if (instance == nullptr)
	{
		instance = new CFileUtil;
	}
	return instance;
}

void CFileUtil::writeArray()
{
	int arr[] = { 20,34,23,33,12,8,9,10,50,80,201,3,2,94,49,37,25 };
	
	
	if (FileOpen("插入排序一维数组", "wb+"))
	{
		fwrite(arr, sizeof arr , 1, m_file);

		FileClose();
	}
}

bool CFileUtil::readArray()
{
	
	if (!FileOpen("插入排序一维数组", "rb"))
	{
		printf("文件不存在");
		return false;
	}

	pArray = new int[DEFAULTSIZE];
	fread(pArray, DEFAULTSIZE*sizeof(int), 1, m_file);

	FileClose();
	return true;
}

void CFileUtil::PrintArray()
{
	if (pArray == nullptr)
		return;

	for (int i = 0; i < DEFAULTSIZE; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf("%d  ", *(pArray + i));
	}
	printf("\n");
}

//int (*CFileUtil::getArray())[DEFAULTSIZE]
int *CFileUtil::getArray()
{
	int arr[DEFAULTSIZE] = { 0 };
	if (pArray != nullptr)
	{
		for (int i = 0; i < DEFAULTSIZE; i++)
		{
			arr[i] = *(pArray + i);
		}
		return pArray;
//		return &arr; // & arr = & *parray
	}
	return nullptr;
}

void CFileUtil::Print(int *p, int len)
{
	for (int i = 0; i < DEFAULTSIZE; i++)
	{
		if (i % 10 == 0)
		{
			printf("\t\n");
		}
		printf("%d ", *(p + i));
	}
	printf("\n");
}

void CFileUtil::delFileUtil()
{
	if (instance == nullptr)
		return;
	
	if (pArray != nullptr)
	{
		delete[] pArray;
		pArray = nullptr;
	}

	if (pArr != nullptr)
	{
		delete[] pArr;
		pArr = nullptr;
	}

	// 今后释放内存的的地方写这里



	delete instance;
}

void CFileUtil::readFile2Mem(char*** txt, const char *path)
{
	int lineCount = 0;
	m_file = fopen(path, "r+");
	
	char buf[1024];
	while (fgets(buf, 1024, m_file))
	{
		lineCount++;
	}
	printf("lineCount: %d", lineCount);
	rewind(m_file);
	*txt = (char **)malloc((lineCount + 1) * sizeof(char *));
	t = (*txt);

	while (fgets(buf, 1024, m_file))
	{
		int n = strlen(buf);
		*t = (char *)malloc(n + 1);
		strcpy(*t, buf);
		t++;
	}
	*t = nullptr;

	//rename("文件.txt", "测试.txt");

	fclose(m_file);
}

/**
 * 文件写入
 */
void CFileUtil::writeFile2Men()
{
#if 1

	FILE* pf = fopen("文件.txt", "w+");

	while (*t)
	{
		fwrite(t, sizeof(**t), 1, pf);
	}
	

	fclose(pf);

#endif
}

bool CFileUtil::FileOpen(const char* filename, const char * mode)
{
	m_file = fopen(filename, mode);
	if (m_file == nullptr)
	{
		return false;
	}

	// 获取行数
	int lineCount = 0;
	char buf[1024];
	while (fgets(buf, 1024, m_file))
		lineCount++;
	rewind(m_file);
	
	return true;
}

bool CFileUtil::FileClose()
{
	if (m_file != nullptr)
	{
		fclose(m_file);
	}
	m_file = nullptr;
	return true;
}

