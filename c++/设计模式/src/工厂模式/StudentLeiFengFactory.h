#pragma once
#include "LeiFengFactory.h"
#include "Student.h"


class StudentFactory:public LeiFengFactory
{
public:
	virtual LeiFeng* CreateLeiFeng()
	{
		return new Student;
	}

protected:
private:
};