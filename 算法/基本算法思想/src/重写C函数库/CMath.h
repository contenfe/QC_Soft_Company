/***
 * @Author: 秦武胜
 * @Date: 2022-10-27 11:32:10
 * @LastEditTime: 2022-10-27 11:32:10
 * @LastEditors: 秦武胜
 * @Description: 重写 Math函数库
 * @FilePath: \qindao\算法\基本算法思想\src\重写C函数库\CMath.h
 */

#ifndef __CMATH_H__
#define __CMATH_H__

/***
 * @Description: 求绝对值
 * @param {int} num 参数
 * @return {}   返回绝对值
 */
int _abs(int num);

/***
 * @Description: 求函数返回参数arg的反余弦值。参数arg 应当在-1和1之间。
 * @param {double} arg
 * @return {}
 */
double _acos(double arg);

/***
 * @Description: 求函数返回参数arg的反正弦值。参数arg 应当在-1和1之间。
 * @param {double} arg
 * @return {}
 */
double _asin(double arg);

/***
 * @Description: 求函数返回参数arg的反正切值。
 * @param {double} arg
 * @return {}
 */
double _atan(double arg);

/***
 * @Description: 求函数计算y/x的反正切值，按照参数的符号计算所在的象限。
 * @param {double} arg
 * @return {}
 */
double _atan2(double arg);

/***
 * @Description: 函数返回参数arg的余弦值，arg以弧度表示给出。
 * @param {double} arg
 * @return {}
 */
double _cos(double arg);

/***
 * @Description: 函数返回参数arg的正弦值，arg以弧度表示给出。
 * @param {double} arg
 * @return {}
 */
double _sin(double arg);

struct
{
    int quot(); // 商数
    int rem;    // 余数
} _div_t;

/***
 * @Description: 函数返回参数numerator / denominator的商和余数
 * @param {int} numerator
 * @param {int} denominator
 * @return {} _div_t
 */
double _div(int numerator, int denominator);

/***
 * @Description: 函数返回参数不小于num 的最小整数
 * @param {double} num
 * @return {}
 */
double _ceil(double num);

/***
 * @Description: 函数返回参数arg的绝对值。
 * @param {double} arg
 * @return {}
 */
double _fabs(double arg);

/***
 * @Description: 函数返回参数不大于arg的最大整数
 * @param {double} arg
 * @return {}
 */
double _floor(double arg);

/***
 * @Description: 函数返回参数x/y的余数。
 * @param {double} arg
 * @return {}
 */
double _fmod(double arg);

/***
 * @Description: 函数将参数num 分割为整数和小数，返回小数部分并将整数部分赋给i。
 * @param {double} num
 * @param {double} *i
 * @return {}
 */
double _modf(double num, double *i);

/***
 * @Description:  函数返回以参数base 为底的exp 次幂。如果base为零或负和exp 小于等于零或非整数时,产生域错误。如果溢出，产生范围错误。
 * @param {double} base
 * @param {double} exp
 * @return {}
 */
double _pow(double base, double exp);

/***
 * @Description: 函数返回参数num的平方根。如果num为负,产生域错误。
 * @param {double} num
 * @return {}
 */
double _sqrt(double num);

/***
 * @Description: 函数返回参数arg的正切值，arg以弧度表示给出。
 * @param {double} arg
 * @return {}
 */
double _tan(double arg);

#endif // ! __CMATH_H__