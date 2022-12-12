/*****************************************************************//**
 * \file   main.cpp
 * \brief  ��ں������ο���վ��http://b23.tv/515oDKe
 * 
 * \author Administrator
 * \date   November 2022
 *********************************************************************/
/**
 * todo.
 * 1.c++����ʹ��
 */




#include<iostream>
#include<cstdio>
#include<fstream>
#include<regex>
#include<vector>
#include<queue>
#include<WinSock2.h>
#include<map>
#include<string>
#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable:4996)
//using namespace std;


char g_host[500];														// ���������ַ
int g_num = 1;														// 
char g_othPath[800];
std::string g_allHtml;
std::vector<std::string> g_photoUrl;
std::vector<std::string> g_comUrl;
std::map<std::string, int> g_mp;
SOCKET g_sock;

// ��ʼ�����绷��
bool InitNet()
{
	WSADATA ws;
	if (0 != WSAStartup(MAKEWORD(2, 2), &ws))
	{
		std::cout << "init net fail\n";
		return false;
	}

	

	return true;
}


// ����URL
bool AnalyURL(char* url)
{
	char* pos = strstr(url, "http://");
	if (NULL == pos)
	{
		return false;
	}
	else
	{
		pos += 7;
	}

	sscanf(pos, "%[^/]%s", g_host, g_othPath);						// http:// ��һֱ��/֮ǰ����������
	std::cout << "host: " << g_host << "   repath: " << g_othPath << std::endl;

	return true;
}


bool ConnetNet()
{
	InitNet();
	// �����׽���
	g_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (g_sock == INVALID_SOCKET)
	{
		std::cout << "create Socket fail\n";
		return false;
	}

	hostent* p = gethostbyname(g_host);
	if (nullptr == p)
	{
		std::cout << "gethostbyname fail\n";
		return false;
	}
	in_addr in;
	memcpy(&in, p->h_addr, 4);
	std::cout << "host's IP: " << inet_ntoa(in) << std::endl;
	sockaddr_in sk_in;
	sk_in.sin_family = AF_INET;
	sk_in.sin_port = htons(80);
	memcpy(&sk_in.sin_addr, p->h_addr, 4);

	// ��
	int n = bind(g_sock, (sockaddr*)&sk_in, sizeof(sk_in));
	if (SOCKET_ERROR == n)
	{
		std::cout << "bind fail "<< WSAGetLastError()<<"\n";
		return false;
	}


	// ������������
	n = connect(g_sock, (sockaddr*)&sk_in, sizeof(sk_in));
	if (n == SOCKET_ERROR)
	{
		std::cout << "connect fail" << WSAGetLastError() << std::endl;
		return false;
	}

	// ģ�����������������Ϣ
	std::string reqInfo = "Get " + (std::string)g_othPath + " HTTP/1.1\r\nHost: " +
		(std::string)g_host + "\r\nConnect:Close\r\n\r\n";
	if (SOCKET_ERROR == send(g_sock, reqInfo.c_str(), reqInfo.size(), 0))
	{
		std::cout << "send fail" << WSAGetLastError() << std::endl;
		closesocket(g_sock);
		return false;
	}




}

// C++11 ������ʽ��ȡͼƬURL��Ԥ�����������еĲ������������γɸ���ƥ��Ԫ�ص�������ʽ
void RegexGetImage(std::string& allHtml)
{
	std::smatch mat;
	std::regex pattern("src=\"(.*?\\.jpg)\"");
	std::string::const_iterator start = allHtml.begin();
	std::string::const_iterator end = allHtml.end();

	// ����������ʽ
	while (regex_search(start, end, mat,pattern))
	{
		std::string msg(mat[1].first, mat[1].second);
		g_photoUrl.push_back(msg);
		start = mat[0].second;
	}
}

// ��ȡ��ҳ�е�http:// ��URL
void RegexGetCom(std::string& allHtml)
{
	std::smatch mat;
	std::regex pattern("href=\"(http://[^\s'\"]+)\"");
	std::string::const_iterator start = allHtml.begin();
	std::string::const_iterator end = allHtml.end();

	// ����������ʽ
	while (regex_search(start, end, mat, pattern))
	{
		std::string msg(mat[1].first, mat[1].second);
		g_photoUrl.push_back(msg);
		start = mat[0].second;
	}
}


// ��ͼƬ������������Ŀ¼��
void OutImage(std::string imageUrl)
{
	int n;
	char temp[800];
	strcpy(temp, imageUrl.c_str());
	AnalyURL(temp);													// ��֧��http
	ConnetNet();
	std::string photoname;
	photoname.resize(imageUrl.size());
	int k = 0;
	for (int i = 0; i < imageUrl.length(); i++)
	{
		char ch = imageUrl[i];
		if (ch != '\\' && ch != '*' && ch != '?' && ch != ':' && ch != '/' && ch != '"' &&
			ch != '<' && ch != '>' && ch != '|')
		{
			photoname[k++] = ch;
		}
	}

	photoname = "./imgData/" + photoname.substr(0, k) + ".jpg";
	std::fstream file;

	file.open(photoname, std::ios::out | std::ios::binary);
	if (!file.is_open())
	{
		std::cout << "file open fail\n";
		return;
	}

	char buf[1024];
	memset(buf, 0, sizeof(buf));
	n = recv(g_sock, buf, sizeof(buf) - 1, 0);
	char* cpos = strstr(buf, "\r\n\r\n");
	file.write(cpos + strlen("\r\n\r\n"), n - (cpos - buf) - strlen("\r\n\r\n"));
	while ((n = recv(g_sock, buf, sizeof(buf) - 1, 0)) > 0)
	{
		file.write(buf, n);
	}
	file.close();

}


// ��������html����
void PutImagetoSet()
{
	int n;
	char buf[1024];
	while ((n = recv(g_sock, buf, sizeof(buf) - 1, 0)))
	{
		buf[n] = '\0';
		g_allHtml += std::string(buf);
	}
	RegexGetImage(g_allHtml);
	RegexGetCom(g_allHtml);
}

// �����������������������ҳ
void BFS(std::string beginUrl)
{
	std::queue<std::string>q;
	q.push(beginUrl);
	while (!q.empty())
	{
		std::string cur = q.front();
		g_mp[cur]++;
		q.pop();
		char tmp[800];
		strcpy(tmp, cur.c_str());
		AnalyURL(tmp);
		ConnetNet();
		PutImagetoSet();
		std::vector<std::string>::iterator it = g_photoUrl.begin();
		for (it; it != g_photoUrl.end(); it++)
		{
			OutImage(*it);
		}
		g_photoUrl.clear();

		std::vector<std::string>::iterator ita = g_comUrl.begin();
		for (ita; ita != g_comUrl.end(); ita++)
		{
			if (g_mp[*it] == 0)
			{
				q.push(*it);
			}
		}
		g_comUrl.clear();
	}
}


// �������绷��
bool DestoryNet()
{
	WSACleanup();
	return true;
}


int main(int argc, char** argv)
{
	std::string url = "http://www.baidu.com/";
	//std::cin >> url;
	CreateDirectoryA("./imgData", 0);
	BFS(url);

	return 0;
}
