#pragma once
#include "Product.h"

class Builder
{
public:
	virtual void BuilderA() = 0;
	virtual void BuilderB() = 0;
	virtual Product* GetResult() = 0;
protected:
private:
};
