#ifndef __CCONTEXT2_H__
#define __CCONTEXT2_H__

/*

�����빤�����
GOOD:�ͻ���ֻ����� Context �࣬������֪�������κ�����Ϣ��ʵ���˵���ϡ�
�����������ϣ��޸���������

*/

#include "COperation.h"

class CContext2
{
public:
	CContext2(char cType);
	double GetResult();
protected:
private:
	COperation *op;

};

#endif // __CCONTEXT2_H__
