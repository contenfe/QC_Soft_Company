#include "CContext.h"


CContext::CContext(COperation *temp)
{
	op = temp;
}

double CContext::GetResult()
{
	return op->GetResult();
}
