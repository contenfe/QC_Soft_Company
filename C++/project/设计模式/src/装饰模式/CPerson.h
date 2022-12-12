#ifndef __CPERSON_H__
#define __CPERSON_H__

#include<iostream>
#include<string>
class CPerson
{
public:
	CPerson()
	{

	}

	CPerson(std::string strName)
	{
		m_strName = strName;
	}

	virtual ~CPerson()
	{

	}

public:
	virtual void Show()
	{
		std::cout << "×°°çµÄÊÇ " << m_strName << std::endl;
	}

protected:
private:
	std::string m_strName;
};

#endif
