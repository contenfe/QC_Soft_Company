#pragma once
#include <iostream>
#include <string>
using namespace std;

class Memo;

// 发起人类
class Originator
{
public:
	string state;
	Memo* CreateMemo();
	void SetMemo(Memo* memo);

	void Show()
	{
		cout << "状态：" << state << endl;
	}
protected:
private:
};

// 备忘录类
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

// 管理者类
class Caretaker
{
public:
	Memo* memo;
protected:
private:
};