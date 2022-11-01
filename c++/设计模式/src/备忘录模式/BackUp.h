#pragma once
#include <iostream>
#include <string>
using namespace std;

class Memo;

// ��������
class Originator
{
public:
	string state;
	Memo* CreateMemo();
	void SetMemo(Memo* memo);

	void Show()
	{
		cout << "״̬��" << state << endl;
	}
protected:
private:
};

// ����¼��
class Memo
{
public:
	string state;
	Memo(string strSate)
	{
		state = strSate;
	}
protected:
private:
};

Memo* Originator::CreateMemo()
{
	return new Memo(state);
}

void Originator::SetMemo(Memo* memo)
{
	state = memo->state;
}

// ��������
class Caretaker
{
public:
	Memo* memo;
protected:
private:
};