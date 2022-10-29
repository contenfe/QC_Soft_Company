#include "CSubOperation.h"

double CSubOperation::GetResult() const
{
	return m_nFirst-m_nSecond;
}

void CSubOperation::SetArg(int first, int second)
{

	m_nFirst = first;
	m_nSecond = second;;
}
