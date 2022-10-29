/***
 * @Author: 秦武胜
 * @Date: 2022-10-28 09:02:14
 * @LastEditTime: 2022-10-28 09:02:14
 * @LastEditors: 秦武胜
 * @Description:
 * @FilePath: \qindao\算法\基本算法思想\src\ReWriteSTL\alloc.cpp
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

        // 寻找16个 free_list 中适当大小的一个去取空间
        }

} // namespace STL
