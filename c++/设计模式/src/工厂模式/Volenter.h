#pragma once
#include "LeiFeng.h"

class Votenter:public LeiFeng
{
public:
	virtual void Sweep()
	{
		std::cout << "学习雷锋，服务社会" << std::endl;
	}
protected:
private:
};
