#pragma once
#include "LeiFeng.h"


class Student:public LeiFeng
{
public:
	virtual  void Sweep()
	{
		std::cout << "ѧϰ�׷棬��������" << std::endl;
	}
protected:
private:
};