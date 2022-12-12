#pragma once
#include <iostream>
#include<vector>
#include <string>

using namespace std;

// �û��ӿ�
class IUser
{
public:
	virtual void GetUser() = 0;
	virtual void InsertUser() = 0;
protected:
private:
};

// ���ų���ӿ�
class IDepartment
{
public:
	virtual void GetDepartment() = 0;
	virtual void InsertDepartment() = 0;
protected:
private:
};

// ACCESS ����
class CAcessDepartment:public IDepartment
{
public:
	virtual void GetDepartment()
	{
		cout << "Access GetDepartment\n";
	}
	virtual void InsertDepartment()
	{
		cout << "Access Insert Department\n";
	}
protected:
private:
};


// Access �û�
class CAcessUser:public IUser
{
public:
	virtual void GetUser()
	{
		cout << "Access GetUser\n";
	}
	virtual void InsertUser()
	{
		cout << "Access Insert User\n";
	}
protected:
private:
};

// sql �û���
class CSqlUser:public IUser
{
public:
	virtual void GetUser()
	{
		cout << "SQL GetUser\n";
	}
	virtual void InsertUser()
	{
		cout << "SQL InsetUser\n";
	}
protected:
private:
};

// sql ������
class CSqlDepartment:public IDepartment
{
public:
	virtual void GetDepartment()
	{
		cout << "sql getDepartment" << endl;
	}
	virtual void InsertDepartment()
	{
		cout << "sql insertDepartment" << endl;
	}

protected:
private:
};


// ���󹤳���
class IFactory
{
public:
	virtual IUser* CreateUser() = 0;
	virtual IDepartment* CreateDepartment() = 0;
protected:
private:
};

// ACCESS ����
class AccessFactory:public IFactory
{
public:
	virtual IUser* CreateUser()
	{
		return new CAcessUser;
	}
	virtual IDepartment* CreateDepartment()
	{
		return new CAcessDepartment;
	}
protected:
private:
};

// SQL ����
class SqlFactory :public IFactory
{
public:
	virtual IUser* CreateUser()
	{
		return new CSqlUser;
	}
	virtual IDepartment* CreateDepartment()
	{
		return new CSqlDepartment;
	}
protected:
private:
};
