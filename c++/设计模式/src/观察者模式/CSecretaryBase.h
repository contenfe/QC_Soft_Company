
#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SecretaryBase;

// ����۲�����
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

// ����Ĺ۲��ߣ�����Ʊ
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

// ����۲��ߣ��� NBA ��
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

// ����֪ͨ�� �����������
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

// ����֪ͨ����

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
	cout << name << ":" << sub->action << ",��Ҫ�� ��Ʊ �ˣ��ϰ�����\n";
}

void NBAObserver::Update()
{
	cout << name << ":" << sub->action << ",��Ҫ�� NBA �ˣ��ϰ�����\n";
}