#include "CCalculatorFactory.h"
#include "CAddOperation.h"
#include "CSubOperation.h"

COperation * CCalculatorFactory::Create(char cOperation)
{
	COperation *oper = nullptr;

	switch (cOperation)
	{
	case '+':
		oper = new CAddOperation();
		break;
	case '-':
		oper = new CSubOperation();
		break;
	}
	return oper;
}
