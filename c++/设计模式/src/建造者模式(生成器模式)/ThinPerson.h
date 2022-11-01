#pragma once
#include "Person.h"

class ThinPerson :public Person
{
public:
	virtual void CreateHead()
	{
		cout << " head of Thin Person" << endl;
	}

	virtual void CreateHand()
	{
		cout << " Hand of Thin Person" << endl;
	}

	virtual void CreateBody()
	{
		cout << " Body of Thin Person" << endl;
	}

	virtual void CreateFoot()
	{
		cout << " foot of Thin Person" << endl;
	}

protected:
private:
};
