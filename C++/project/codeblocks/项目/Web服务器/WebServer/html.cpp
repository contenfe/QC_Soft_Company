#include<iostream>
#include"html.h"
#include"WinSock2.h"  //ʹ���׽��ֵ�ͷ�ļ�
#include <fstream>    //�����ļ�����ͷ�ļ�
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable:4996)

CHttp::CHttp()
{
	m_bHttps = false;												// Ĭ�Ͽ�ʼ����httpsЭ��
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

	WSACleanup();
}

//DONE ��ʼ������
bool CHttp::Init()
{
	// ʵ������
	WSADATA wd;

	//
	if (0 != WSAStartup(MAKEWORD(2, 2), &wd))
	{
		return false;
	}

	if (2 != LOBYTE(wd.wVersion) || 2 != HIBYTE(wd.wVersion))		// �ж�������ǲ���2.2�汾
	{
		std::cout << " this is not 2.2 version " << std::endl;
		return false;
	}

	// �����׽��� | �ܵ�
	// HttpЭ��ײ���ͨ��TCPЭ��ʵ�ֵ�
	m_socket = socket(AF_INET, SOCK_STREAM, 0); // IPV4Э�飬tcpЭ��
	if (m_socket == INVALID_SOCKET)
	{
		std::cout << "create m_socket is fail in html.cpp\n";
		return false;
	}

	return true;
}

// ����URL��Դ
bool CHttp::AnalyseURL(std::string url)
{
	// Ĭ��ʹ��������֤��url
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

	std::cout << "host: " << m_host << std::endl;
	std::cout << "object: " << m_object << std::endl;
	return true;
}


//DONE ���ӷ�����
bool CHttp::Connect()
{
	// ��ʼ�����绷��
	Init();

	// ����������ΪIP��ַ
	hostent* p = nullptr;

	p = gethostbyname(m_host.c_str());								// p��ŵ����ݾ������������������ú��ip��ַ

	if (NULL == p)
	{
		std::cout << "CHttp? Connected is fail\n";
		return false;												// ����ʧ��
	}
	in_addr in_addr_string;											// ��ѡһ
	memcpy(&in_addr_string,p->h_addr,4);
	std::cout << inet_ntoa(in_addr_string) << std::endl;				// ��ӡ������IP��ַ


	// ���ӷ�����
	// ����IP��ַ
	sockaddr_in sa;

	sa.sin_family = AF_INET;										// Э��
	sa.sin_port = htons(80);										// �˿ڣ�������Ĭ�϶˿�80���������ֽ�˳��ת��Ϊ�����ֽ�˳��

	memcpy(&sa.sin_addr, p->h_addr, 4);
//	int n = bind(m_socket, (sockaddr*)&sa, sizeof(sa));

	if (SOCKET_ERROR == connect(m_socket, (sockaddr*)&sa,			// ����
		sizeof(sa)))
	{
		std::cout << "connect net is error in line 148\n";
		return false;
	}


	return true;
}

// ��ȡ��ҳ
bool CHttp::GetHtml(std::string& html)
{
	// ������ͷ�����Ҫ��Ҫ�Ǹ���ҳ
	// ƴ�ӷ�����Ϣ
	std::string info;
	info += "GET "+ m_object + " HTTP/1.1\r\n";
	info += "Host: " + m_host + "\r\n";
	info += "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/107.0.0.0 Safari/537.36 Edg/107.0.1418.52 \r\n";
	info += "Connection: Close\r\n";								// �������ر�
	//info += "User-Agent: Mozilla/5.0 (Windows NT 10.0; \
		Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) \
		Chrome/107.0.0.0 \
		Safari/537.36 Edg/107.0.1418.52\r\n";						// �û�����

	info += "\r\n";

	// ��������
	if (SOCKET_ERROR == send(m_socket, info.c_str(), info.length(), 0))
	{
		std::cout << "get html Fail\n";
		return false;
	}



	// ����
	char ch = 0;
	int nrecv = 0;
	while (recv(m_socket, &ch, sizeof(ch), 0))
	{
		html += ch;
	}

	closesocket(m_socket);
}
