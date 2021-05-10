/*
题目描述
计算一个数字的立方根，不使用库函数。
保留一位小数。


输入描述:
待求解参数，为double类型（一个实数）

输出描述:
输入参数的立方根。保留一位小数。

示例1
输入
复制
216
输出
复制
6.0

命f(x) = x^3 - a，求解f(x) = x^3 - a = 0。
利用泰勒公式展开，即f(x)在xo处的函数值为：
f(x) = f(xo) +f'(xo)(x-xo) = xo^3-a+3xo^2(x-x0) = 0，
解之得：x = xo - (xo^3 - a) / (3xo^2)。

求平方根用一个套路@_@：
命f(x) = x^2 - a，求解f(x) = x^2 - a = 0。

利用泰勒公式展开，即f(x)在xo处的函数值为：
f(x) = f(xo) +f'(xo)(x-xo) = xo^2-a+2xo(x-x0) = 0，
解之得：x = (x+a/xo) / 2。
*/

#include <stdio.h>

const double err = 0.01; //精确两位
double fun(double n)
{
    double x0 = 1, y = x0 * x0 * x0;
    while(y - n > err || y - n < -err)
    {
        x0 = x0 - (x0 * x0 * x0 - n) / (3 * x0 * x0);
        y = x0 * x0 * x0;
    }
    return x0;
}

int main()
{
    double n;
    scanf("%lf",&n);
    double result;
    result = fun(n);
    printf("%.1lf\n",result);
    return 0;
}
