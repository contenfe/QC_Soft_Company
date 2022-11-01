#pragma once
#include "Builder.h"

class Direct
{
public:
	void Construct(Builder *temp)
	{
		temp->BuilderA();
		temp->BuilderB();
	}
protected:
private:
};
