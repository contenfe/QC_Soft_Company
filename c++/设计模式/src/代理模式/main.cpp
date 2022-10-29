/*

远程代理，可以隐藏一个对象在不同地址空间的事实
虚拟代理：通过代理来存放需要很长时间实例化的对象
安全代理：用来控制真实对象的访问权限
智能引用：当调用真实对象时，代理处理另外一些事


*/


#include<iostream>
#include "ProxyClass.h"

using namespace std;


int main(int argc, char **argv)
{
	ProxyClass* proxy = new ProxyClass;
	proxy->Request();


	return 0;
}