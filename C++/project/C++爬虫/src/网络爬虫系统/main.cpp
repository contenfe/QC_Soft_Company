#include<iostream>
#include<Windows.h>
#include<queue>

using namespace std;


bool StartCatch(string url)
{

	queue<string> q;
	q.push(url);

	while (!q.empty())
	{
		string currentUrl = q.front();
		q.pop();

	}
	
	return false;
}



int main_()
{
	
	string url;
	// ´´½¨Ä¿Â¼
	CreateDirectoryA("./res/image", 0);



	return 0;
}
