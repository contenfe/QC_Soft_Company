#pragma once
#ifndef __CONCRETEBUILDER1_H__
#define __CONCRETEBUILDER1_H__
#include "Builder.h"

class ConcreteBuilder1 : public Builder
{
public:
	ConcreteBuilder1()
	{
		m_product = new Product();
	}

    virtual void BuilderA()
    {
		m_product->Add(" one ");
    }

    virtual void BuilderB()
    {
		m_product->Add(" two ");
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


#endif