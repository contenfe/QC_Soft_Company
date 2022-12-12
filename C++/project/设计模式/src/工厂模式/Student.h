#pragma once
#include "LeiFeng.h"


class Student:public LeiFeng
{
public:
	virtual  void Sweep()
	{
		std::cout << "Ñ§Ï°À×·æ£¬°ïÖúËûÈË" << std::endl;
	}
protected:
private:
};