#pragma once

#include "Interface.h"
#include "RealClass.h"

class ProxyClass :public Interface
{
public:
	virtual void Request()
	{
		m_realClass = new RealClass;
		m_realClass->Request();
		delete m_realClass;
	}
protected:
private:
	RealClass* m_realClass;
};