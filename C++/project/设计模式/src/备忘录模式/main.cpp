/*

����¼ģʽ
GOOD���ڲ��ƻ���װ�Ե�ǰ���£�����һ��������ڲ�״̬�����ڸö���֮�Ᵽ�����
״̬�������Ϳ��Խ��Ժ�Ķ���״̬�ָ�����ǰ�����״̬��

�����ڹ��ܱȽϸ��ӵģ�����Ҫ��¼��ά��������ʷ���ࣻ������Ҫ���������ֻ����
�������е�һС����ʱ Originator ���Ը��ݱ���� Memo ��ԭ��ǰһ״̬


*/


#include <iostream>
#include "BackUp.h"
using namespace std;

int main(int argc, char **argv)
{
	Originator * on = new Originator;
	on->state = "on";
	on->Show();

	Caretaker * c = new Caretaker;
	c->memo = on->CreateMemo();
	on->state = "off";
	on->Show();

	on->SetMemo(c->memo);
	on->Show();

	return 0;
}