/*

��̬�ظ�һ���������һЩ�����ְ�𣨲���Ҫ�Ĺ��ܣ�ֻ��żȻһ��Ҫִ�У� ������
�ӹ�����˵��װ��ģʽ�����������Ϊ��������̲��ȶ�������ȷ��˳������������
���ơ�

GOOD:������ɵ���������´���ʱ��һ����Ϊ����Ӻ���ְ�����Ҫ��Ϊ��������
Ҫ����Ľ�����һЩ�ض�����²Ż�ִ�е��ض��Ĺ���ʱ���򵥵���ǲ��Ǻ���Ӧ�õĹ�
�ܣ����ͻ�������ĸ��Ӷȡ�װ��ģʽ���ǰ�Ҫ��ӵĸ��ӹ��ֱܷ���ڵ��������У�����
����������Ҫװ�εĶ��󣬵���Ҫִ��ʱ���ͻ��˾Ϳ�����ѡ��ء���˳���ʹ��װ�ι�
�ܰ�װ����

*/
#pragma once
#include<iostream>
#include "CPerson.h"
#include "CBigTrouser.h"
#include "TShirts.h"

using namespace std;

int main(int argc, char **argv)
{
	CPerson* person = new CPerson("С����");
	CBigTrouser* bt = new CBigTrouser();
	TShirts *ts = new TShirts();

	bt->Decorate(person);
	ts->Decorate(bt);

	ts->Show();
	

	return 0;
}