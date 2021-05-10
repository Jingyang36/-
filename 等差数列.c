/*
题目描述
功能:等差数列 2，5，8，11，14。。。。

输入:正整数N >0

输出:求等差数列前N项和

本题为多组输入，请使用while(cin>>)等形式读取数据

输入描述:
输入一个正整数。

输出描述:
输出一个相加后的整数。

示例1
输入
复制
2
输出
复制
7

a1 = 2, d = 3, Sn = na1  + n(n-1)d/2 
*/

#include <stdio.h>

int main()
{
    int a1 = 2;
    int d = 3;
    
    int n;
    int Sn = 0;
    while(scanf("%d",&n)!=EOF)
    {
        if(n>0)
            Sn = n*a1 + (n*(n-1)*d)/2;
        printf("%d\n",Sn);
    }
    return 0;
}

