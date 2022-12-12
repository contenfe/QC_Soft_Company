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


string urlRes[]{
				 "https://www.woyaogexing.com/tupian/",
				 "http://ent.ifeng.com/",
				 "http://www.woyaogexing.com/tupian/dongman/2022/210933.html",
				 "https://www.umei.cc/weimeitupian/keaitupian/31381.htm",
				 "https://www.qqlinxiang.cn/books/64/64107/22626274.html",
				 "https://kuwo.cn/",
				 "https://www.doupo321.com/doupocangqiong/1.html",
				};

/**
 * main入口函数.
 *
 * \return
 */
int main_()
{
	FILE* pFile = fopen("../res/html/test.html", "w+");
	CHttp http;
	StartView();
	string url;
	//cin >> url;
	string html;


	// 开始抓取

	http.AnalyseURL(urlRes[2]);
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

	cout << html << endl;

	fwrite(html.c_str(), html.size(), 1, pFile);
	fclose(pFile);

	cout << "***********************************************************************\n";
	//cout << html << endl;
	cout << "***********************************************************************\n";
	return 0;

}


int main2()
{
	char* p = "REGULAR EXPRESSIONS";
	cout<<strlen(p)<<endl;

	return 0;
}
