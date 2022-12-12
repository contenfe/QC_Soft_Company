#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#define MAX 100

struct ENode
{

    int nVindex;    // 该边所指的顶点的位置
    ENode *pNext;   // 指向下一个边的指针
};

struct VNode
{
    char data;      // 顶点信息
    ENode* pFirstEdge;  // 指向第一条依附该顶点的边
};

// 无向领接表
class listUDG
{
public:
    listUDG(){}
    listUDG(char *vexs,int vlen,char edges[][2],int elen);
    ~listUDG();
    void PrintUDG();

private:
    // 返回顶点的索引
    int GetVIndex(char ch);

    void LinkLast(ENode *pFirstNode,ENode *pNode);

private:
    int m_nVexNum;      // 顶点数目
    int m_nEdgNum;      // 边数目
    VNode m_mVexs[MAX];

};

#endif // GRAPH_H_INCLUDED
