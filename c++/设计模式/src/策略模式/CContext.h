#ifndef __CCONTEXT_H__
#define __CCONTEXT_H__
#include "COperation.h"


class CContext
{
public:
	CContext(COperation *temp);
	double GetResult();
protected:
private:
	COperation *op;
};

#endif
