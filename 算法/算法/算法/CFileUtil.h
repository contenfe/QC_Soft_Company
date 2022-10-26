/**
*
*	�ļ�����: E:\qindao\�㷨\�㷨\�㷨\CFileUtil.h
*	����: �ļ���ȡ������
*	����: qws
*	ʱ��: 2022/10/25
*
*/
#ifndef __CFILEUTIL_H__
#define __CFILEUTIL_H__

#include <stdio.h>


#define DEFAULTSIZE 17

class CFileUtil
{
private:
	static CFileUtil* instance;
	
	int *pArray;
	int **pArr;
	char **t;

	FILE* m_file;
public:
	
	static CFileUtil* getInstance();
	void delFileUtil();
	
	void readFile2Mem(char*** txt, const char *path);
	void writeFile2Men();

															/* Ĭ�ϲ��Է��� */
	void writeArray();	
	bool readArray();
	void PrintArray();
	//int (*getArray())[DEFAULTSIZE];
	int* getArray();

	void Print(int *p, int len);							/* ��ӡ�������� */

private:
	CFileUtil()
	{
		m_file = nullptr;
		pArray = nullptr;
		pArr = nullptr;
	}

	// �ļ�������ر�
	bool FileOpen(const char* filename, const char * mode);
	bool FileClose();
};


class CFile
{
public:


protected:
private:
};
#endif // __CFILEUTIL_H__

