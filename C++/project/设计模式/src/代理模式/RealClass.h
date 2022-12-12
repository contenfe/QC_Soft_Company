#pragma once
#include<iostream>
#include "Interface.h"

class RealClass:public Interface
{
public:
	virtual void Request()
	{
		std::cout << "ÕæÊµÇëÇó" << std::endl;
	}
protected:
private:
};