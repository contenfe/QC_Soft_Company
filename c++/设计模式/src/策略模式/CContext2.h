#ifndef __CCONTEXT2_H__
#define __CCONTEXT2_H__

/*

策略与工厂结合
GOOD:客户端只需访问 Context 类，而不用知道其它任何类信息，实现了低耦合。
在上例基础上，修改下面内容

*/

#include "COperation.h"

class CContext2
{
public:
	CContext2(char cType);
	double GetResult();
protected:
private:
	COperation *op;

};

#endif // __CCONTEXT2_H__
