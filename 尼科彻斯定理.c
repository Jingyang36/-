/*
题目描述
验证尼科彻斯定理，即：任何一个整数m的立方都可以写成m个连续奇数之和。

例如：

1^3=1

2^3=3+5

3^3=7+9+11

4^3=13+15+17+19

输入一个正整数m（m≤100），将m的立方写成m个连续奇数之和的形式输出。
本题含有多组输入数据。
输入描述:
输入一个int整数

输出描述:
输出分解后的string

示例1
输入
复制
6
输出
复制
31+33+35+37+39+41

等差数列， Sn = m^3, d = 2, n = m
Sn = na1 + nd(n-1)/2

m^3 = na1 + n(n-1)

an = a1 + nd = an-1 + 2n
*/

#include <stdio.h>

int main()
{
    //首项m*m+1-m, m项
    int m;
    while (scanf("%d",&m)!=EOF)
    {
        int s = m*m+1 - m;
        printf("%d",s); //首项
        for(int i = 1; i < m; i++)
        {
            printf("+");
            printf("%d",s + 2 * i);
        }
        printf("\n");
    }

    return 0;
}
