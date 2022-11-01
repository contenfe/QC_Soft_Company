#pragma once

#include <iostream>
#include <string>

#include <vector>
using namespace std;

class Component
{
public:
	string m_strName;
	Component(string strname)
	{
		m_strName = strname;
	}

	virtual void Add(Component* com) = 0;
	virtual void Display(int nDepth) = 0;
protected:
private:
};


class Left:public Component
{
public:
	Left(string name):Component(name){}

	virtual void Add(Component* com)
	{
		cout << "Left cann't add\n";
	}
	virtual void Display(int nDepth)
	{
		string strtemp;
		for (int i = 0; i < nDepth; i++)
		{
			strtemp += "-";
		}

		strtemp += m_strName;
		cout << strtemp << endl;
	}
protected:
private:
};


class Composite:public Component
{
public:
	Composite(string name):Component(name){}

	virtual void Add(Component* com)
	{
		m_component.push_back(com);
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

		vector<Component*>::iterator p = m_component.begin();
		while (p != m_component.end())
		{
			(*p)->Display(nDepth + 2);
			p++;
		}
	}
protected:
private:
	vector<Component* >m_component;
};