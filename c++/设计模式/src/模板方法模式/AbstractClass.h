#pragma once
#include <iostream>
#include<string>
using namespace std;

class AbstractClass
{
public:
	void Show()
	{
		cout << "ÎÒÊÇ" << GetName() << endl;
	}
protected:
	virtual string GetName() = 0;
private:
};