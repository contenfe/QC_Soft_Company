
/*

模板方法模式
GOOD： 把不变的代码部分都转移到父类中， 将可变的代码用 virtual 留到子类重写

*/


#include<iostream>
#include "Naruto.h"
#include "OnePice.h"
using namespace std;

int main(int argc, char **argv)
{

	Naruto* man = new Naruto();
	man->Show();

	OnePice* sea = new OnePice();
	sea->Show();
	
	//cout << man.GetName() << endl;

	return 0;

}