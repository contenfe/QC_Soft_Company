/*

状态模式
GOOD：当一个对象的行为取决于它的状态，并且它必须在运行时刻根据状态改
变它的行为时，可考虑用到状态模式。


*/

#include <iostream>
#include "CState.h"
using namespace std;

int main(int argc, char **argv)
{
	Work* mywork = new Work;
	mywork->hour = 9;
	mywork->WriteProgram();
	mywork->hour = 14;
	mywork->WriteProgram();
	return 0;
}