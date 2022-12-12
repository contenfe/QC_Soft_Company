#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Company
{
private:
protected:
	string m_strName;
public:
	Company(string name)
	{
		m_strName = name;
	}

	virtual void Add(Company* c) = 0;
	virtual void Display(int nDepth) = 0;
	virtual void LineOfDuty() = 0;


};


class ConcreteCompany:public Company
{
public:
	ConcreteCompany(string name):Company(name){}

	virtual void Add(Company* c)
	{
		m_company.push_back(c);
	}

	virtual void Display(int nDepth)
	{
		string strtemp;
		for (int i = 0; i < nDepth; i++)
		{
			strtemp += '-';
		}

		strtemp += m_strName;
		cout << strtemp << endl;

		vector<Company*>::iterator p = m_company.begin();
		while (p != m_company.end())
		{
			(*p)->Display(nDepth + 2);
			p++;
		}
	}

	virtual void LineOfDuty()
	{
		vector<Company*>::iterator p = m_company.begin();
		while (p != m_company.end())
		{
			(**p).LineOfDuty();
			p++;
		}
	}
protected:

private:
	vector<Company*>m_company;
};


class HrDepartment :public Company
{
public:
	HrDepartment(string name) :Company(name) {}

	virtual void Add(Company* c)
	{
		cout << "error" << endl;
	}

	virtual void Display(int nDepth)
	{
		string strtemp;
		for (int i = 0; i < nDepth; i++)
		{
			strtemp += '-';
		}

		strtemp += m_strName;
		cout << strtemp << endl;
	}

	virtual void LineOfDuty()
	{
		cout << m_strName << ":ÕÐÆ¸ÈË²Å" << endl;
	}
protected:

private:
	
};