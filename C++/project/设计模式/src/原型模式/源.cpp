/*

GOOD： 从一个对象再创建另外一个可定制的对象， 而无需知道任何创建的细节。
并能提高创建的性能。 说白了就 COPY 技术，把一个对象完整的 COPY 出一份。

深拷贝

*/


#include<iostream>
#include "ProtoType.h"
#include "ConcreteProtoType1.h"
using namespace std;

int main(int argc, char **argv)
{

	ProtoType* p1 = new ConcreteProtoType1("小张");
	ProtoType* p2 = p1->Clone();

	p1->Show();
	p2->Show();

	return 0;
}