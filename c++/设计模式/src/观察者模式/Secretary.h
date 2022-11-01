#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Secretary;

// 同事类
class StockObserver
{
public:
	StockObserver(string strname, Secretary * strsub)
	{
		name = strname;
		sub = strsub;
	}

	void Update();
	
protected:
private:
	string name;
	Secretary * sub;
};


// 秘书类
class Secretary
{
public:
	string action;

	void Add(StockObserver ob)
	{
		observers.push_back(ob);
	}

	void Notify()
	{
		vector<StockObserver>::iterator p = observers.begin();
		while (p != observers.end())
		{
			(*p).Update();
			p++;
		}
	}
protected:
private:
	vector<StockObserver> observers;
};


void StockObserver::Update()
{
	cout << name << ":" << sub->action << ",不要玩股票了，要开始工作了\n";
}
