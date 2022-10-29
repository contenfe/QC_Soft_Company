/***
 * @Author: ����ʤ
 * @Date: 2022-10-27 12:01:08
 * @LastEditTime: 2022-10-27 13:43:08
 * @LastEditors: ����ʤ
 * @Description:
 * @FilePath: \qindao\�㷨\�����㷨˼��\src\��дC������\CMath.cpp
 */

#include "CMath.h"
#include <stdlib.h>
/***
 * @Description: �����ֵ
 * @param {int} num ����
 * @return {}   ���ؾ���ֵ
 */
int _abs(int num)
{
    // �����ô����
    if (num >= 0 && num <= INT_MAX)
    {
        return num;
    }
    else if (num < 0 && num > INT_MIN)
    {
        return -num;
    }
    else
    {
        return (-2) * INT_MIN - num;
    }
}

/***
 * @Description: �������ز���arg�ķ�����ֵ������arg Ӧ����-1��1֮�䡣
 * @param {double} arg
 * @return {}
 */
double _acos(double arg)
{
}

/***
 * @Description: �������ز���arg�ķ�����ֵ������arg Ӧ����-1��1֮�䡣
 * @param {double} arg
 * @return {}
 */
double _asin(double arg)
{
}

/***
 * @Description: �������ز���arg�ķ�����ֵ��
 * @param {double} arg
 * @return {}
 */
double _atan(double arg)
{
}

/***
 * @Description: ��������y/x�ķ�����ֵ�����ղ����ķ��ż������ڵ����ޡ�
 * @param {double} arg
 * @return {}
 */
double _atan2(double arg)
{
}

/***
 * @Description: �������ز���arg������ֵ��arg�Ի��ȱ�ʾ������
 * @param {double} arg
 * @return {}
 */
double _cos(double arg)
{
}

/***
 * @Description: �������ز���arg������ֵ��arg�Ի��ȱ�ʾ������
 * @param {double} arg
 * @return {}
 */
double _sin(double arg)
{
}

/***
 * @Description: �������ز���numerator / denominator���̺�����
 * @param {int} numerator
 * @param {int} denominator
 * @return {} _div_t
 */
double _div(int numerator, int denominator)
{
}

/***
 * @Description: �������ز�����С��num ����С����
 * @param {double} num
 * @return {}
 */
double _ceil(double num)
{
}

/***
 * @Description: �������ز���arg�ľ���ֵ��
 * @param {double} arg
 * @return {}
 */
double _fabs(double arg)
{
}

/***
 * @Description: �������ز���������arg���������
 * @param {double} arg
 * @return {}
 */
double _floor(double arg)
{
}

/***
 * @Description: �������ز���x/y��������
 * @param {double} arg
 * @return {}
 */
double _fmod(double arg)
{
}

/***
 * @Description: ����������num �ָ�Ϊ������С��������С�����ֲ����������ָ���i��
 * @param {double} num
 * @param {double} *i
 * @return {}
 */
double _modf(double num, double *i)
{
}

/***
 * @Description:  ���������Բ���base Ϊ�׵�exp ���ݡ����baseΪ��򸺺�exp С�ڵ�����������ʱ,�����������������������Χ����
 * @param {double} base
 * @param {double} exp
 * @return {}
 */
double _pow(double base, double exp)
{
}

/***
 * @Description: �������ز���num��ƽ���������numΪ��,���������
 * @param {double} num
 * @return {}
 */
double _sqrt(double num)
{
}

/***
 * @Description: �������ز���arg������ֵ��arg�Ի��ȱ�ʾ������
 * @param {double} arg
 * @return {}
 */
double _tan(double arg)
{
}