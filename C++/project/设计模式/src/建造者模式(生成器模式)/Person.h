#pragma once
#include <iostream>
#include<vector>
#include<string>

using namespace std;

class Person
{
public:
	
	virtual void CreateHead() = 0;
	virtual void CreateHand() = 0;
	virtual void CreateBody() = 0;
	virtual void CreateFoot() = 0;
protected:
private:
};
