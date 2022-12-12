#pragma once


#include<WinSock2.h>

class CHttp
{

private:
	FILE* m_file;

public:
	std::string m_host;												// 域名
	std::string m_object;											// 资源路径
	bool m_bHttps;													//
	SOCKET m_socket;												// 套接字

public:
	CHttp();
	~CHttp();

public:
	bool Init();													// 初始化网络
	bool AnalyseURL(std::string url);												// 解析URL
	bool Connect();													// 链接服务器
	bool GetHtml(std::string& html);								// 下载网页及保存
};
