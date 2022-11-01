#pragma once
#include <iostream>
#include <string>
using namespace std;

class Player
{
public:
	Player(string strname)
	{
		name = strname;
	}

	virtual void Attack() = 0;
	virtual void Defense() = 0;
protected:
	string name;
private:
};


class Forwards:public Player
{
public:
	Forwards(string name) :Player(name)
	{

	}
	virtual void Attack()
	{
		cout << name << "ǰ����\n";
	}
	virtual void Defense()
	{
		cout << name << "ǰ�����\n";
	}
protected:
private:
};

class Center:public Player
{
public:
	Center(string name) :Player(name)
	{
	}
	virtual void Attack()
	{
		cout << name << "�г����\n";

	}
	virtual void Defense()
	{
		cout << name << "�г�����\n";

	}
protected:
private:
};


// ��Ҫ
// Ϊ�г�����
class TransLater:public Player
{
public:
	TransLater(string name) :Player(name)
	{
		player = new Center(name);
	}

	virtual void Attack()
	{
		player->Attack();
	}
	virtual void Defense()
	{
		player->Defense();
	}
protected:
private:
	Center *player;
};