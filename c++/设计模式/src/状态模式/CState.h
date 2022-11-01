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
			cout << "��������\n";
		else
			cout << "�����ˣ�˯����\n";
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
			cout << "�����޵к�\n";

		}
		else
		{
			//cout << "�����ˣ�˯����\n";
			w->SetState(new NoonState);
			w->WriteProgram(); // ��������
		}
	}
protected:
private:
};


Work::Work()
{
	m_currentstate = new ForenoonState;
}
