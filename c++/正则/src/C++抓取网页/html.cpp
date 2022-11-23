#include<iostream>
#include"html.h"
#include<WinSock2.h>  //ʹ���׽��ֵ�ͷ�ļ�
#include <fstream>    //�����ļ�����ͷ�ļ�
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable:4996)

CHttp::CHttp()
{
	m_bHttps = false;												// Ĭ�Ͽ�ʼ����httpsЭ��
	m_socket = NULL;												//
	m_file = fopen("../res/log.text", "aw+");
}

CHttp::~CHttp()
{
	if (nullptr != m_file)
	{
		fclose(m_file);
		m_file = nullptr;
	}
}

//DONE ��ʼ������
bool CHttp::Init()
{
	WSADATA wd;

	if (0 != WSAStartup(MAKEWORD(2, 2), &wd))
	{
		return false;
	}

	if (2 != LOBYTE(wd.wVersion) || 2 != HIBYTE(wd.wVersion))		// �ж�������ǲ���2.2�汾
	{
		return false;
	}

	// �����׽���
	m_socket = socket(AF_INET, SOCK_STREAM, 0);

	return true;
}

// ����URL��Դ
bool CHttp::AnalyseURL(std::string url)
{
	std::string str = url.substr(0, 8);
	if ("https://" == str)
	{
		m_bHttps = true;
	}
	else if (str.find("http://") != std::string::npos)
	{
		m_bHttps = false;
	}
	else
		return false;

	//��������ַ�ķ�б��λ��
	int nPos = url.find('/', m_bHttps ? 8 : 7);  //���m_bHttpsΪ�棬��ô�ӵ�8��֮���λ�ÿ�ʼ�ң�����ӵ��߸�λ��֮��ʼ��
	if (nPos == std::string::npos)  //��仰����˼����˵��������һ��λ�ö������ˣ���û�ҵ���   npos��ʾstring�Ľ���λ�ã�
	{
		//http://www.163.com
		m_host = url.substr(m_bHttps ? 8 : 7);  //�����������֣������������û��/����ôֱ�Ӵ�http://��ʼ��ȡ���ص����  
		m_object = "/";  //����������û����Դ·���������Ǿ͸�����һ��б��
	}
	else
	{
		//������������https://www.microsoft.com/zh-cn/download/confirmation.aspx?id=40770
		m_host = url.substr(m_bHttps ? 8 : 7, nPos - (m_bHttps ? 8 : 7));
		m_object = url.substr(nPos);
	}

	if (m_host.empty())  //�����������Ϊ�գ���ζ�Ž�ȡ����
		return false;

	return true;
}

//DONE ���ӷ�����
bool CHttp::Connect()
{
	HOSTENT* p = gethostbyname(m_host.c_str());						// p��ŵ����ݾ������������������ú��ip��ַ

	if (nullptr == p)
	{
		return false;												// ����ʧ��
	}

	// ���ӷ�����
	sockaddr_in sa;
	sa.sin_family = AF_INET;										// Э��
	sa.sin_port = htons(80);										// �˿�

	memcpy(&sa.sin_addr, p->h_addr, 4);
	if (SOCKET_ERROR == connect(m_socket, (sockaddr*)&sa,
		sizeof(sockaddr)))
	{
		return false;
	}

	return true;
}

bool CHttp::GetHtml(std::string& html)
{

	std::string get;
	get += "GET" + m_object + " HTTP/1.1\r\n";
	get += "Host: " + m_host + "\r\n";
	get += "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.77 Safari/537.36 Edg/91.0.864.37";
	get += "Connection: Close\r\n";
	get += "\r\n";
	
	// ����get����
	if (SOCKET_ERROR == send(m_socket, get.c_str(), get.length(),	//�׽��֡����͵����ݡ����Ͷ೤��flag
		0))
	{
		if(nullptr == m_file)
			fputs("ʧ��_Position_GetHtml\n",m_file);
		return false;
	}

	// ��������
	char ch;
	std::fstream dataFile;											// ���html�ļ�
	dataFile.open("../res/html/res.html",std::ios::out);
	if (!dataFile)
	{
		fputs("ʧ��_Position_GetHtml_��res.html�ļ�\n", m_file);
		return false;
	}

	while (recv(m_socket, &ch, sizeof(ch), 0))
	{
		html += ch;
		dataFile << ch;
	}
	dataFile.close();
	return true;
}