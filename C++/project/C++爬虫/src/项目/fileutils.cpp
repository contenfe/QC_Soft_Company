
//#include<iostream>
#include"fileutils.h"
#include<Windows.h>
#include<queue>
using namespace std;


bool CreateDirectorys(string dirName)
{
	if (!CreateDirectory("res", nullptr))
	{
		cout << "fail to create res of directory" << endl;
		return false;
	}
	if (CreateDirectory(("res/"+ dirName).c_str(), NULL))
	{
		//CreateFile("侠肝义胆沈剑心",GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ, CREATE_NEW, FILE_SHARE_READ | FILE_SHARE_WRITE);
		return true;
	}

	else
	{
		cout<<"fail to create target of directory"<<endl;
		return false;
	}

}

bool StartCatchURL(std::string strurl)
{

	string curstr;
	queue<string> q;
	// 插入一条URL
	q.push(strurl);

	// 取出URL
	while (!q.empty())
	{
		curstr = q.front();
		q.pop();

		// 解析URL

	}


	return false;
}
