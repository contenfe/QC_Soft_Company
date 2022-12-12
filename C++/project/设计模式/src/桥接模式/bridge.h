#pragma once
#include <iostream>
#include<string>
#include<vector>

using namespace std;

// 手机软件
class HandsetSoft
{
public:
	virtual void Run() = 0;
protected:

private:
};

class HandsetGame:public HandsetSoft
{
public:
	virtual void Run()
	{
		cout << "运行手机哦游戏" << endl;
	}
protected:
private:
};



class HandSetAddressList : public HandsetSoft
{
public:
	virtual void Run()
	{
		cout << "手机通讯录" << endl;
	}
};
//手机品牌
class HandsetBrand
{
protected:
	HandsetSoft* m_soft;
public:
	void SetHandsetSoft(HandsetSoft* temp)
	{
		m_soft = temp;
	}
	virtual void Run() = 0;
};


//M 品牌
class HandsetBrandM : public HandsetBrand
	{
	public:
		virtual void Run()
		{
			m_soft-> Run();
		}
};
		//N 品牌
class HandsetBrandN : public HandsetBrand
{
public:
	virtual void Run()
	{
		m_soft -> Run();
	}
};
		//客户