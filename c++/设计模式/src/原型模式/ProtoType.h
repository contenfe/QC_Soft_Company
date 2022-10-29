#pragma once
#include<iostream>
#include<string>

class ProtoType
{
public:
	ProtoType(std::string strName)
	{
		m_strName = strName;
	}

	ProtoType()
	{
		m_strName = " ";
	}

	void Show()
	{
		std::cout << m_strName << std::endl;
	}

	virtual ProtoType* Clone() = 0;

protected:
	std::string m_strName;

private:
};
