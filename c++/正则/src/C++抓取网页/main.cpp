//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<queue>
#include"html.h"
using namespace std;

//��ӭ����
void Welcome()
{
	cout << endl;
	cout << endl;
	cout << "\t\t-----------------------------------------" << endl;
	cout << "\t\t-----------------------------------------" << endl;
	cout << "\t\t-\t\t\t\t\t-" << endl;
	cout << "\t\t-\t\t\t\t\t-" << endl;
	cout << "\t\t-\t\t\t\t\t-" << endl;
	cout << "\t\t-\t��ӭʹ��C++��������ϵͳ\t\t-" << endl;
	cout << "\t\t-\t\t\t\t\t-" << endl;
	cout << "\t\t-\t\t\t\t\t-" << endl;
	cout << "\t\t-\t\t\t\t\t-" << endl;
	cout << "\t\t-\t  ĳĳ��ѧĳĳʵ����\t\t-" << endl;
	cout << "\t\t-\t\t\t\t\t-" << endl;
	cout << "\t\t-\t\t\t\t\t-" << endl;
	cout << "\t\t-----------------------------------------" << endl;
	cout << "\t\t-----------------------------------------" << endl;
}
//��ʼץȡ
bool StartCatch(string url)
{
	queue<string> q;  //����url����   ��Ϊurl���Ȼ�ȡ���ȴ���������queue�����ݽṹ
	q.push(url);      //����ȡ����url���з���queue��

	while (!q.empty())  //�ж϶����Ƿ�Ϊ�գ������Ϊ�գ���ô��һֱ�ɼ�
	{
		string currentUrl = q.front();   //����ǰ�����еĵ�һ��urlȡ����
		q.pop();

		//����URL   ----���ǰ�Э�顢��������Դ·�����ָ����
		CHttp http;
		http.Init();
		http.AnalyseURL(currentUrl);
		cout << http.m_host << "\t\t" << http.m_object << endl;

		if (false == http.Connect())
			cout << "���ӷ�����ʧ��" << endl;
		else
			cout << "���ӷ������ɹ�" << endl;

		//��ȡhtml��Ϣ
		string html;
		http.GetHtml(html);
		cout << html << endl;   //��һ�п��п��ޣ�������һ���ܵ�ʱ���������

	}
	return true;
}

int main()
{
	
	cout << "������Ҫץȡ��URL�ĵ�ַ��" << endl;
	string url;
	cin >> url;
	StartCatch(url);
	system("pause");
	return EXIT_SUCCESS;
}