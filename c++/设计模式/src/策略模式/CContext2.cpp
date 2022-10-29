#include "CContext2.h"
#include "CAddOperation.h"

CContext2::CContext2(char cType)
{

	switch (cType)
	{
	case '+':
		op = new CAddOperation(3, 9);
		break;
	default:
		op = new COperation();
	}
}

double CContext2::GetResult()
{
	return op->GetResult();
}
