/*

״̬ģʽ
GOOD����һ���������Ϊȡ��������״̬������������������ʱ�̸���״̬��
��������Ϊʱ���ɿ����õ�״̬ģʽ��


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