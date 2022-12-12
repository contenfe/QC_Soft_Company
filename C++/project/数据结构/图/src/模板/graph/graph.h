#pragma once

const int MAXVEX = 100;												// ��󶥵���
const int INTFINITY = 65535;										// ���������

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
	char m_vexnums[MAXVEX];											// �����
	int m_arc[MAXVEX][MAXVEX];										// �ڽӾ���,�ɿ����߱�
	int m_numVertexes;												// ��ǰ������
	int m_numEdges;													// ��ǰ����
	
};

