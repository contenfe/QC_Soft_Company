#pragma once
#include "SubSysOne.h"
#include "SubSysTwo.h"

class Facade
{
public:
	void FacadeMethod()
	{
		sub1->MethodOne();
		sub2->MethodTwo();
	}

public:
	Facade()
	{
		sub1 = new SubSysOne();
		sub2 = new SubSysTwo();
	}

	~Facade()
	{
		delete sub1;
		delete sub2;
	}
protected:
private:
	SubSysOne* sub1;
	SubSysTwo* sub2;

};
