#include<iostream>
#include"graph.h"

using namespace std;
void CGraph::CreateGraph()
{
	int i = -1, j = -1, k = -1, w = -1;
	cout << "���붥�����ͱ���:\n";
	cin >> i >> j;
	try
	{
		if (i == -1 || j == -1)
		{
			throw "û���붥�����ͱ���";
		}

	}
	catch (string &e)
	{
		cout << e << endl;
	}
}
