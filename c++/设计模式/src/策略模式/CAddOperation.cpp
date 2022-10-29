#include "CAddOperation.h"

double CAddOperation::GetRQesult() const
{
	return m_nFirst + m_nSecond;
}

void CAddOperation::SetArg(int first, int second)
{
	m_nFirst = first;
	m_nSecond = second;
}

CAddOperation::CAddOperation()
{
	m_nFirst = 0;
	m_nSecond = 0;
}

CAddOperation::CAddOperation(int a, int b)
{
	m_nFirst = a;
	m_nSecond = b;
}
