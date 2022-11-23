#include"server.h"
#include<WinSock2.h>
#include<iostream>

#pragma comment(lib,"ws2_32.lib")
using namespace std;

CServer::CServer()
{
}

CServer::~CServer()
{

	WSACleanup();
}

bool CServer::Init()
{
	WSAData data;				
	if (0 == WSAStartup(MAKEWORD(2, 2), &data))
	{
		cout << "初始化網絡環境失敗" << endl;
		return false;
	}
	

	return true;
}

bool CServer::openSocket()
{
	if (Init())
	{
		m_socket = socket(AF_INET, SOCK_STREAM, 0);
		return true;
	}
	else 
	{

		cout << "失败" << endl;
		return false;
	}
}

bool CServer::bindSocket()
{
	sockaddr_in addr;
	addr.sin_family = AF_INET;										// IP协议为IPV4
	addr.sin_port = htons(9900);									// 端口
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");				// 绑定本机具体的IP
	bind(m_socket, (sockaddr*)&addr, sizeof(addr));


	return true;
}

bool CServer::listenSocket()
{
	if(-1 == listen(m_socket,10))
		return false;

	return true;

}

bool CServer::accpetSocket()
{

	sockaddr addr;
	int len = sizeof(addr);

	if (-1 == (m_socketCli = accept(m_socket, &addr, &len)))
	{
		cout<<"接收失败"<<endl;

		return false;
	}

	return true;
}

bool CServer::SendAndRecv()
{
	char buf[1024] = "我是服务器";
	if (-1 == (send(m_socketCli, buf, strlen(buf), 0)))
	{
		cout << "失败" << endl;
		return false;
	}

	if (0 >= recv(m_socketCli, buf, 1024, 0))
	{
		cout << "失败" << endl;
		return false;
	}

	return true;
}


