/*

桥接模式
GOOD：将抽象部分与实现部分分离，使它们可以独立变化。
这里说的意思不是让抽象基类与具体类分离，而是现实系统可能有多角度分类，
每一种分类都有可能变化，那么把这种多角度分离出来让它们独立变化，减少它们之间的耦
合性，即如果继承不能实现“开放－封闭原则”的话，就应该考虑用桥接模式。

*/

#include<iostream>
#include "bridge.h"
using namespace std;

/**
 * .
 * 
 * \param num
 */
void test(int num)
{

}

int main()
{
	HandsetBrand *brand;
	brand = new HandsetBrandM();
	brand-> SetHandsetSoft(new HandsetGame());
	brand-> Run();
	brand-> SetHandsetSoft(new HandSetAddressList());
	brand-> Run();
	return 0;
}