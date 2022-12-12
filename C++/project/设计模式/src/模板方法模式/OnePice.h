#pragma once
#include "AbstractClass.h"


class OnePice:public AbstractClass
{
public:
protected:
	virtual string GetName()
	{
		return "我是要成为海贼王的男人";
	}
private:
};
