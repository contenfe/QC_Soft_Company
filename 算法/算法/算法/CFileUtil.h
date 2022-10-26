/**
*
*	文件名称: E:\qindao\算法\算法\算法\CFileUtil.h
*	描述: 文件读取工具类
*	作者: qws
*	时间: 2022/10/25
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

															/* 默认测试方法 */
	void writeArray();	
	bool readArray();
	void PrintArray();
	//int (*getArray())[DEFAULTSIZE];
	int* getArray();

	void Print(int *p, int len);							/* 打印辅助方法 */

private:
	CFileUtil()
	{
		m_file = nullptr;
		pArray = nullptr;
		pArr = nullptr;
	}

	// 文件开启或关闭
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

