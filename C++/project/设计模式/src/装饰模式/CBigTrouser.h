#ifndef __CBIGTROUSER_H__
#define __CBIGTROUSER_H__
#include "CFinery.h"

class CBigTrouser:public CFinery
{
public:
	virtual void Show()
	{
		std::cout << " Big Trouser " << std::endl;
		m_component->Show();
	}
protected:
private:
};

#endif
