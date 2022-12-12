#pragma once


#include<WinSock2.h>

class CHttp
{

private:
	FILE* m_file;

public:
	std::string m_host;												// ����
	std::string m_object;											// ��Դ·��
	bool m_bHttps;													//
	SOCKET m_socket;												// �׽���

public:
	CHttp();
	~CHttp();

public:
	bool Init();													// ��ʼ������
	bool AnalyseURL(std::string url);												// ����URL
	bool Connect();													// ���ӷ�����
	bool GetHtml(std::string& html);								// ������ҳ������
};
