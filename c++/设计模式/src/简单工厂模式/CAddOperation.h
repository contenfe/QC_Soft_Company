#ifndef __CADDOPERATION_H__
#define __CADDOPERATION_H__
#include "COperation.h"


// º”∑®¿‡
class CAddOperation:public COperation
{
public:
	virtual double GetRQesult()const;

	virtual void SetArg(int first, int second);

public:
	CAddOperation();

	CAddOperation(int a, int b);
	
protected:
private:
};


#endif // __CADDOPERATION_H__
