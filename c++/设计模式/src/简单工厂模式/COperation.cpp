#include "COperation.h"
#include<iostream>
COperation::COperation()
{

	std::cout << "base Construct" << std::endl;

}

double COperation::GetResult() const
{
	return m_nFirst+m_nSecond;
}

void COperation::SetArg(int first, int second)
{
	m_nFirst = first;
	m_nSecond = second;
}
