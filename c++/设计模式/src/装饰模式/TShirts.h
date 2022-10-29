#ifndef __TSHIRTS_H__
#define __TSHIRTS_H__
#include "CFinery.h"

class TShirts:public CFinery
{
public:
	virtual void Show()
	{
		std::cout << " T SHIRTS " << std::endl;
		m_component->Show();
	}
	
protected:
private:
};
#endif
