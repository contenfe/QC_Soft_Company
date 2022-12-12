#pragma once

const int MAXVEX = 100;												// 最大顶点数
const int INTFINITY = 65535;										// 代表无穷大

class CGraph
{
public:
	CGraph();
	~CGraph();
public:
	void CreateGraph();
	void DestroyGraph();
	void LocateVex();
	void GetVex();
	void PutVex();
	void FirstAdjVex();
	void NextAdjVex();
	void InsertVex();
	void DeleteVex();
	void InsertArc();
	void DeleteArc();
	void DFSTraverse();
	void BFSTraverse();

private:
	char m_vexnums[MAXVEX];											// 顶点表
	int m_arc[MAXVEX][MAXVEX];										// 邻接矩阵,可看做边表
	int m_numVertexes;												// 当前顶点数
	int m_numEdges;													// 当前边数
	
};

