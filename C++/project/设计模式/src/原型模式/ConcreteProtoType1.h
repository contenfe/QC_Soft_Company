#pragma once
#include "ProtoType.h"

class ConcreteProtoType1:public ProtoType
{
public:
	ConcreteProtoType1(std::string strName) :ProtoType(strName)
	{
		m_strName = strName;
	}

	ConcreteProtoType1() {};

public:
	virtual ProtoType* Clone()
	{
		ConcreteProtoType1 *p = new ConcreteProtoType1();
		*p = *this;
		return p;
	}
protected:
private:
};