#pragma once
#include "Person.h"

class ThickPerson :public Person
{
public:
	virtual void CreateHead()
	{
		cout << " head of Thick Person" << endl;
	}

	virtual void CreateHand()
	{
		cout << " Hand of Thick Person" << endl;
	}

	virtual void CreateBody()
	{
		cout << " Body of Thick Person" << endl;
	}

	virtual void CreateFoot()
	{
		cout << " foot of Thick Person" << endl;
	}

protected:
private:
};
