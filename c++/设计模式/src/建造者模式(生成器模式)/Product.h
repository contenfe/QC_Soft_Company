#pragma once

#include<iostream>
#include<string>
#include<vector>
using namespace std;

// ���ղ�Ʒ��
class Product
{
public:
	void Add(string strtemp)
	{
		m_prodout.push_back(strtemp);
	}

	void Show()
	{
		vector<string>::iterator p = m_prodout.begin();

		while (p != m_prodout.end())
		{
			cout << *p << endl;
			p++;
		}
	}
protected:
private:
	vector<string> m_prodout;
};
