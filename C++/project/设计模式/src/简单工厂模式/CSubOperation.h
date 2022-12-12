#ifndef __CSUBOPERATION_H__
#define __CSUBOPERATION_H__

#include "COperation.h"
class CSubOperation:public COperation
{
public:
	virtual double GetResult()const;

	virtual void SetArg(int first, int second);
protected:
private:
};


#endif // __CSUBOPERATION_H__
