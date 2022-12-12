#include<iostream>
#include"graph.h"

using namespace std;
void CGraph::CreateGraph()
{
	int i = -1, j = -1, k = -1, w = -1;
	cout << "输入顶点数和边数:\n";
	cin >> i >> j;
	try
	{
		if (i == -1 || j == -1)
		{
			throw "没输入顶点数和边数";
		}

	}
	catch (string &e)
	{
		cout << e << endl;
	}
}
