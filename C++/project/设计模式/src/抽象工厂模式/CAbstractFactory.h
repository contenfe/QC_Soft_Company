#pragma once
#include <iostream>
#include<vector>
#include <string>

using namespace std;

// 用户接口
class IUser
{
public:
	virtual void GetUser() = 0;
	virtual void InsertUser() = 0;
protected:
private:
};

// 部门抽象接口
class IDepartment
{
public:
	virtual void GetDepartment() = 0;
	virtual void InsertDepartment() = 0;
protected:
private:
};

// ACCESS 部门
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


// Access 用户
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

// sql 用户类
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

// sql 部门类
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


// 抽象工厂类
class IFactory
{
public:
	virtual IUser* CreateUser() = 0;
	virtual IDepartment* CreateDepartment() = 0;
protected:
private:
};

// ACCESS 工厂
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

// SQL 工厂
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
