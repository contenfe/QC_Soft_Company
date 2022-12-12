#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<WinSock2.h>
#include<iostream>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
int main() {
	WSADATA data;
	int ret = WSAStartup(MAKEWORD(2, 2), &data);
	if (ret)
	{
		cout << "初始化网络错误！" << endl;
		WSACleanup();
		return -1;
	}
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9999);
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	int ret = connect(sock, (sockaddr*)&addr, sizeof(addr));
	if (ret == -1)
	{
		WSACleanup();
		cout << "连接服务器失败" << endl;
		return -1;
	}
	char buf[0xFF];
	ret = recv(sock, buf, sizeof(buf), 0);
	if (ret <= 0)
	{
		WSACleanup();
		cout << "接收服务器数据失败" << endl;
		return -1;
	}
	cout << "服务器：" << buf << endl;

	ret = send(sock, buf, ret, 0); //将接收到的数据发回服务器
	if (ret <= 0)
	{
		WSACleanup();
		cout << "发送服务器数据失败" << endl;
		return -1;
	}
	WSACleanup();
}

