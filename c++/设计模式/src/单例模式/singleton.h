#pragma once
#include <iostream>
using namespace std;

class Singleton
{
public:
	static Singleton* getInstance()
	{
		if (nullptr != instance)
		{
			instance = new Singleton;
		}
		return instance;
	}

	void Say()
	{
		std::cout << "hello " << std::endl;
	}
protected:
private:
	Singleton() {

	}

	static Singleton* instance;
};


Singleton* Singleton::instance = nullptr;


