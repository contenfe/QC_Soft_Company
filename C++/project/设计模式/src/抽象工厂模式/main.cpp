/*

GOOD：定义了一个创建一系列相关或相互依赖的接口，而无需指定它们的具体
类。
用于交换产品系列，如 ACCESS­>SQL SERVER；
产品的具体类名被具体工厂的实现分离


*/

#include <iostream>
#include "CAbstractFactory.h"
using namespace std;

int main(int argc, char **argv)
{
	IFactory *sqlfty = new SqlFactory;
	IUser* sqluser = sqlfty->CreateUser();

	IDepartment* sqlDepart = sqlfty->CreateDepartment();

	sqluser->GetUser();
	sqlDepart->GetDepartment();

	delete sqlDepart;
	delete sqluser;
	delete sqlfty;

	return 0;
}