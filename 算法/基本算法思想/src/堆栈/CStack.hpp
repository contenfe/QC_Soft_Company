#ifndef __CSTACK_H__
#define __CSTACK_H__

#define INITCAPACITY 30     // ��ʼ����Ϊ30
#define INCREASECAPACITY 20 // ��������Ϊ20

template <typename T>
class CStack
{
private:
    T m_Stack[INITCAPACITY];

public:
    CStack();
    CStack(CStack &S);
    CStack(T *array);

protected:
};

#endif // __CSTACK_H__
