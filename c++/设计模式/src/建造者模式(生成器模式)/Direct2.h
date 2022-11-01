#pragma once
#include "Person.h"



class Direct2
{
public:
	Direct2(Person * p)
	{
		m_person = p;
	}

	void Create()
	{
		m_person->CreateHead();
		m_person->CreateBody();
		m_person->CreateFoot();
		m_person->CreateHand();
	}

	// todo ≤‚ ‘÷∏’Î Õ∑≈
	void DelPerson()
	{
		if (nullptr != m_person)
		{
			delete m_person;
			m_person = nullptr;
		}
		else
		{
			cout << " m_person is nullptr" << endl;
		}
	}
protected:
private:
	Person* m_person;
};