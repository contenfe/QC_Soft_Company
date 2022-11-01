#pragma once
#include <iostream>
using namespace std;

class Target
{
public:
	virtual void Request()
	{
		cout << "普通的请求" << endl;
	}
protected:
private:
};


class Adaptee
{
public:
	virtual void SpecificalRequest()
	{
		cout << "特殊请求" << endl;
	}
protected:
private:
};

class Adapter:public Target
{
public:
	virtual void Request()
	{
		ada->SpecificalRequest();
		Target::Request();
	}

	Adapter()
	{
		ada = new Adaptee;
	}

	~Adapter()
	{
		delete ada;
	}
protected:
private:
	Adaptee* ada;
};