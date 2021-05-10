/*
题目描述
Redraiment是走梅花桩的高手。Redraiment可以选择任意一个起点，从前到后，但只能从低处往高处的桩子走。他希望走的步数最多，你能替Redraiment研究他最多走的步数吗？

本题含有多组样例输入


输入描述:
输入多行，先输入数组的个数，再输入相应个数的整数

输出描述:
输出结果

示例1
输入
复制
6
2 5 1 5 4 5 
3
3 2 1
输出
复制
3
1
说明
6个点的高度各为 2 5 1 5 4 5
如从第1格开始走,最多为3步, 2 4 5
从第2格开始走,最多只有1步,5
而从第3格开始走最多有3步,1 4 5
从第5格开始走最多有2步,4 5
所以这个结果是3。  

最长上升子序列 动态规划
*/

#include <stdio.h>
#include <stdlib.h>


#define max(a,b) ((a)>(b)?(a):(b))

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF) //行
    {
        int arr[100] = {0};
        int dp[100] = {0};
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&arr[i]);
        }
        int maxResult = 0;
       // int maxValue = 0;
        for(int i = 0; i < n; i++)
        {
            dp[i] = 1;//最短
            for(int j = 0; j < i; j++)
            {
                if(arr[i] > arr[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1); //判断当前和之前的
                }
            }
            maxResult = max(maxResult, dp[i]);
        }
        printf("%d\n",maxResult);        
    }
    return 0;
}
