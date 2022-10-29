#pragma once
#include "LeiFeng.h"

class LeiFengFactory
{
public:
	virtual LeiFeng * CreateLeiFeng()
	{
		return new LeiFeng;
	}
protected:
private:
};