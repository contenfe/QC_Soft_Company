
#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SecretaryBase;

// 抽象观察者类
class CObserverBase
{
public:
	CObserverBase(string strname, SecretaryBase *strsub)
	{
		name = strname;
		sub = strsub;
	}

	virtual void Update() = 0;
	string name;

protected:
	SecretaryBase *sub;

private:
};

// 具体的观察者，看股票
class StockObserver : public CObserverBase
{
public:
	StockObserver(string strname, SecretaryBase *strsub) : CObserverBase(strname, strsub)
	{
		name = strname;
		sub = strsub;
	}

	virtual void Update();

protected:
private:
};

// 具体观察者，看 NBA 的
class NBAObserver : public CObserverBase
{
public:
	NBAObserver(string strname, SecretaryBase *strsub) : CObserverBase(strname, strsub)
	{
		name = strname;
		sub = strsub;
	}
	virtual void Update();
};

// 抽象通知者 抽象主题对象
class SecretaryBase
{
public:
	string action;
	virtual void Attach(CObserverBase *observer) = 0;
	virtual void Notify() = 0;

	vector<CObserverBase *> observers;

protected:
private:
};

// 具体通知对象

class Secretary : public SecretaryBase
{
public:
	virtual void Attach(CObserverBase *observer)
	{
		observers.push_back(observer);
	}

	virtual void Notify()
	{
		vector<CObserverBase *>::iterator p = observers.begin();
		while (p != observers.end())
		{
			(**p).Update();
			p++;
		}
	}

protected:
private:
};

void StockObserver::Update()
{
	cout << name << ":" << sub->action << ",不要看 股票 了，老板来了\n";
}

void NBAObserver::Update()
{
	cout << name << ":" << sub->action << ",不要看 NBA 了，老板来了\n";
}