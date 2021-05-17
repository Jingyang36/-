/*
题目描述
首先输入要输入的整数个数n，然后输入n个整数。输出为n个整数中负数的个数，和所有正整数的平均值，结果保留一位小数。
本题有多组输入用例。
输入描述:
首先输入一个正整数n，
然后输入n个整数。

输出描述:
输出负数的个数，和所有正整数的平均值。

示例1
输入
复制
5
1 2 3 4 5
输出
复制
0 3.0
*/

#include <stdio.h>

int main()
{
    int n,num;

    while(scanf("%d",&n)!=EOF)
    {
        int count1 = 0,count2 = 0;
        float mean,sum = 0; //循环内
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&num);
            if(num < 0)
            {
                count1 ++;
            }
            else if(num > 0)
            {
                sum += num;
                count2 ++;
            }

        }
        mean = (float)sum/count2;

        printf("%d %.1f\n",count1, mean);
        
    }
    return 0;
}
