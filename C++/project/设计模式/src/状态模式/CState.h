#pragma once


#include <iostream>
using namespace std;

class Work;
class ForenoonState;
class NoonState;

class State
{
public:
	virtual void WriteProgram(Work* w) = 0;
protected:
private:
};


class Work
{
private:
	State* m_currentstate;
public:
	double hour;
public:
	Work();
	void SetState(State* temp)
	{
		m_currentstate = temp;
	}

	void WriteProgram()
	{
		m_currentstate->WriteProgram(this);
	}
};

class NoonState:public State
{
public:
	virtual void WriteProgram(Work* w)
	{
		cout << "execute" << endl;
		if (w->hour < 13)
			cout << "还不错了\n";
		else
			cout << "不行了，睡觉吧\n";
	}

	
protected:
private:
};

class ForenoonState :public State
{
public:
	virtual void WriteProgram(Work* w)
	{
		if (w->hour < 12)
		{
			cout << "精神无敌好\n";

		}
		else
		{
			//cout << "不行了，睡觉吧\n";
			w->SetState(new NoonState);
			w->WriteProgram(); // 请加上这段
		}
	}
protected:
private:
};


Work::Work()
{
	m_currentstate = new ForenoonState;
}
