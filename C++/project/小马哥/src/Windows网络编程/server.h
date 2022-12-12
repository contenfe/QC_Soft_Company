#ifndef __SERVER_H__
#define __SERVER_H__

// https://blog.csdn.net/weixin_50964512/article/details/123743421#WSAStartup_30




/**
 *@brind: 
 * 网络环境初始化：WSAStartup
 * 创建服务器套接字：socket
 * 绑定本机IP和端口：bind
 * 监听客户端：listen
 * 等待客户端连接：accept
 * 发送消息：send
 * 接收消息：recv
 * 关闭socket：closesocket
 * 清除网络环境：WSACleanup.
 */



/*

int WSAStartup(
WORD wVersionRequested, //版本号，使用MAKEWORD宏生成
LPWSADATA lpWSAData //数据
);
//返回值：0代表成功，否则失败


*/


class CServer
{
private:
	SOCKET m_socket;
	SOCKET m_socketCli;
public:
	CServer();
	~CServer();

public:
/**
 *
 * int WSAStartup(
 * WORD wVersionRequested, //版本号，使用MAKEWORD宏生成
 * LPWSADATA lpWSAData //数据
 * );
 * //返回值：0代表成功，否则失败
 * .
 */
	bool Init();													// 初始化网络环境
	bool openSocket();												// 打开Socket
	bool bindSocket();												// 绑定
	bool listenSocket();											// 监听
	bool accpetSocket();											// 接收用户
	bool SendAndRecv();												// 接收和发送
};



#endif


