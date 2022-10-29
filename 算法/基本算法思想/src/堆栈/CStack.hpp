#ifndef __CSTACK_H__
#define __CSTACK_H__

#define INITCAPACITY 30     // 初始容量为30
#define INCREASECAPACITY 20 // 增长容量为20

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
