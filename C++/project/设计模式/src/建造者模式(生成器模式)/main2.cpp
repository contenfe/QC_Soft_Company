#include <iostream>
#include "Direct2.h"
#include "ThinPerson.h"
using namespace std;

int main(int argc, char **argv)
{
	Person* p = new ThinPerson();
	Direct2 *d = new Direct2(p);

	d->Create();
	
	delete p;
	//d->DelPerson();
	delete d;


	return 0;
}