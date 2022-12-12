#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#define MAX 100

struct ENode
{

    int nVindex;    // �ñ���ָ�Ķ����λ��
    ENode *pNext;   // ָ����һ���ߵ�ָ��
};

struct VNode
{
    char data;      // ������Ϣ
    ENode* pFirstEdge;  // ָ���һ�������ö���ı�
};

// ������ӱ�
class listUDG
{
public:
    listUDG(){}
    listUDG(char *vexs,int vlen,char edges[][2],int elen);
    ~listUDG();
    void PrintUDG();

private:
    // ���ض��������
    int GetVIndex(char ch);

    void LinkLast(ENode *pFirstNode,ENode *pNode);

private:
    int m_nVexNum;      // ������Ŀ
    int m_nEdgNum;      // ����Ŀ
    VNode m_mVexs[MAX];

};

#endif // GRAPH_H_INCLUDED
