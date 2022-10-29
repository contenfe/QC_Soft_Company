/***
 * @Author: ����ʤ
 * @Date: 2022-10-28 09:02:14
 * @LastEditTime: 2022-10-28 09:02:14
 * @LastEditors: ����ʤ
 * @Description:
 * @FilePath: \qindao\�㷨\�����㷨˼��\src\ReWriteSTL\alloc.cpp
 */

#include "alloc.h"
#include <malloc.h>
namespace STL
{
    char *alloc::start_free = 0;
    char *alloc::end_free = 0;
    size_t alloc::heap_size = 0;

    alloc::obj *alloc::free_list[alloc::__NFREELISTS] =
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    void *alloc::allocate(size_t n)
    {
        if (n > (size_t)__MAX_BYTES)
        {
            return (malloc(n));
        }

        // Ѱ��16�� free_list ���ʵ���С��һ��ȥȡ�ռ�
        }

} // namespace STL
