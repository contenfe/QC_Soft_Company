#pragma once
#include "LeiFengFactory.h"
#include "Volenter.h"
class VolenterFactory:public LeiFengFactory
{
public:
	virtual LeiFeng* CreateLeiFeng()
	{
		return new Votenter;
	}
protected:
private:
};