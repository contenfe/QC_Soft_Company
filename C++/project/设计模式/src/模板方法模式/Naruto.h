#pragma once
#include "AbstractClass.h"


class Naruto:public AbstractClass
{
public:
	
protected:
	virtual string GetName()
	{
		return "火影史上最帅的是四代目火影 - 波风水门 naruto";
	}
private:
};
