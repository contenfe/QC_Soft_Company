#ifndef __CCALCULATORFACTORY_H__
#define __CCALCULATORFACTORY_H__
#include"COperation.h"

class CCalculatorFactory
{
public:
	static COperation* Create(char cOperation);

protected:
private:
};

#endif // !__CCALCULATORFACTORY_H__
