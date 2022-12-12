#include<iostream>
//#include"fileutils.h"
#include"html.h"
//#include<regex>
using namespace std;

void StartView()
{
	cout << "*********************************************" << endl;
	cout << "*                 catch                      *" << endl;
	cout << "*********************************************" << endl;
}


/**
 * main入口函数.
 * 
 * \return 
 */
int main()
{
	CHttp http;
	
	StartView();
	//string strUrl;
	//cin >> strUrl;
	//CreateDirectorys("image");

	// 开始抓取
	char url[] = "https://www.umei.cc/weimeitupian/keaitupian/31381.htm";
	http.AnalyseURL("https://www.umei.cc/weimeitupian/keaitupian/31381.htm");
	if (false == http.Connect())
	{
		cout << "main? con{nected is fail \n";
	}
	else
	{
		cout << "main? connected is succes \n";

	}


	return 0;
	
}
