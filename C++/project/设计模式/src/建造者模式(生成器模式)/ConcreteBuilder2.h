#pragma once
#ifndef __CONCRETEBUILDER2_H__	
#define __CONCRETEBUILDER2_H__
#include "Product.h"

class ConcreteBuilder2:public Builder
{
public:
	ConcreteBuilder2()
	{
		m_product = new Product();
	}

	virtual void BuilderA()
	{
		m_product->Add(" A ");
	}

	virtual void BuilderB()
	{
		m_product->Add(" B ");
	}

	virtual Product *GetResult()
	{
		if (nullptr != m_product)
		{
			return m_product;
		}
		else
		{
			return NULL;
		}
	}

protected:
private:
	Product* m_product;
};



#endif // __CONCRETEBUILDER2_H__
