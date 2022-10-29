#ifndef __CFINERY_H__
#define __CFINERY_H__
#include "CPerson.h"

// finery ·þ×°
class CFinery:public CPerson
{
public:

	CFinery()
	{
		m_component = NULL;
	}

	virtual void Decorate(CPerson* component)
	{
		m_component = component;
	}

	virtual void Show()
	{
		m_component->Show();
	}
protected:
	CPerson * m_component;
private:
};

#endif
