#include <iostream>
#include "singleton.h"

using namespace std;


int main(int argc, char **argv)
{
	Singleton* in = Singleton::getInstance();
	in->Say();
	return 0;
}

