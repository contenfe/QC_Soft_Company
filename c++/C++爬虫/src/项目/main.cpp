#include<iostream>
#include"main.h"
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


string urlRes[]{ "https://www.umei.cc/weimeitupian/keaitupian/31381.htm",
				 "https://www.baidu.com",
				 "https://www.qqlinxiang.cn/books/64/64107/22626274.html",
				 "https://kuwo.cn/",
				 "https://www.doupo321.com/doupocangqiong/1.html"};

/**
 * main入口函数.
 * 
 * \return 
 */
int main()
{

	FILE* pFile = fopen("../res/html/test.html", "w+");
	CHttp http;
	string html;
	StartView();
	//string strUrl;
	//cin >> strUrl;
	//CreateDirectorys("image");

	// 开始抓取
	
	http.AnalyseURL(urlRes[1]);
	if (false == http.Connect())
	{
		cout << "main? con{nected is fail \n";
		return 0;
	}
	else
	{
		//cout << "main? connected is succes \n";

		// 获取网页
		http.GetHtml(html);

	}

	fwrite(html.c_str(), html.length()+1, 1, pFile);
	fclose(pFile);
	
	cout << "***********************************************************************\n";
	//cout << html << endl;
	cout << "***********************************************************************\n";
	return 0;
	
}
