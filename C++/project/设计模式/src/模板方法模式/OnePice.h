#pragma once
#include "AbstractClass.h"


class OnePice:public AbstractClass
{
public:
protected:
	virtual string GetName()
	{
		return "����Ҫ��Ϊ������������";
	}
private:
};
