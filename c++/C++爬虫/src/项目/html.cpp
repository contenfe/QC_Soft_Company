#include<iostream>
#include"html.h"
#include<WinSock2.h>  //使用套接字的头文件
#include <fstream>    //包含文件流的头文件
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable:4996)

CHttp::CHttp()
{
	m_bHttps = false;												// 默认开始不是https协议
	m_socket = NULL;												//
	m_file = fopen("../res/html/error.txt", "w+");
}

CHttp::~CHttp()
{
	if (nullptr != m_file)
	{
		fclose(m_file);
		m_file = nullptr;
	}
}

//DONE 初始化网络
bool CHttp::Init()
{
	// 实际网络
	WSADATA wd;

	// 
	if (0 != WSAStartup(MAKEWORD(2, 2), &wd))
	{
		return false;
	}

	if (2 != LOBYTE(wd.wVersion) || 2 != HIBYTE(wd.wVersion))		// 判断请求的是不是2.2版本
	{
		std::cout << " this is not 2.2 version " << std::endl;
		return false;
	}

	// 创建套接字 | 管道
	// Http协议底层是通过TCP协议实现的
	m_socket = socket(AF_INET, SOCK_STREAM, 0); // 协议，tcp协议 

	return true;
}

// 解析URL资源
bool CHttp::AnalyseURL(std::string url)
{
	// 默认使用正则验证过url
	if (std::string::npos == url.find("http://"))
	{
		m_bHttps = true;
	}
	else
	{
		m_bHttps = false;
	}

	int pos;
	int subpos;
	if (!m_bHttps)
	{
		pos = url.find('/', 7);
		subpos = 7;
	}
	else
	{
		pos = url.find('/', 8);
		subpos = 8;
	}

	if (std::string::npos == pos)
	{
		m_host = url.substr(subpos);
		m_object = "/";
	}
	else
	{
		m_host = url.substr(subpos, pos - subpos);
		m_object = url.substr(pos);
	}

	std::cout << " host: " << m_host << std::endl;
	std::cout << " object: " << m_object << std::endl;
	return true;
}


//DONE 连接服务器
bool CHttp::Connect()
{
	// 初始化网络环境
	Init();


	hostent* p = nullptr;
	p = gethostbyname(m_host.c_str());						// p存放的内容就是由主机域名解析好后的ip地址

	if (nullptr == p)
	{
		std::cout << "CHttp? Connected is fail\n";
		return false;												// 解析失败
	}

	// 连接服务器
	// 保存IP地址
	sockaddr_in sa;
	sa.sin_family = AF_INET;										// 协议
	sa.sin_port = htons(80);										// 端口，服务器默认端口80，将主机字节顺序转化为网络字节顺序
	memcpy(&sa.sin_addr, p->h_addr, 4);

	if (SOCKET_ERROR == connect(m_socket, (sockaddr*)&sa,			// 联网
		sizeof(sockaddr)))
	{
		std::cout << "connect net is error in line 148\n";
		return false;
	}

	return true;
}

// 获取网页
bool CHttp::GetHtml(std::string& html)
{
	// 先请求和服务器要需要那个网页
	std::string info;
	info += "GET " + m_object + " HTTP/1.1\r\n";
	info += "Host: " + m_host + "\r\n";
	info += "Connection: Close\r\n";								// 联网完后关闭
	//info += "User-Agent: Mozilla/5.0 (Windows NT 10.0; \
		Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) \
		Chrome/107.0.0.0 \
		Safari/537.36 Edg/107.0.1418.52\r\n";						// 用户代理
	info += "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/107.0.0.0 Safari/537.36 Edg/107.0.1418.52 \r\n";
	info += "\r\n";

	// 发送请求
	if (SOCKET_ERROR == send(m_socket, info.c_str(), info.length(), 0))
	{
		std::cout << "get html Fail\n";
		return false;
	}

	// 接收
	char ch = 0;
	while (recv(m_socket, &ch, sizeof(ch), 0))
	{
		html += ch;
	}


}
