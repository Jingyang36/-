// 题目描述
// 输入n个整数，输出其中最小的k个。

// 本题有多组输入样例，请使用循环读入，比如while(cin>>)等方式处理
// 输入描述:
// 第一行输入两个整数n和k
// 第二行输入一个整数数组

// 输出描述:
// 输出一个从小到大排序的整数数组

// 示例1
// 输入
// 复制
// 5 2
// 1 3 5 7 2
// 输出
// 复制
// 1 2

#include<stdio.h>
#include<string.h>
int main()
{
    int n,k;
    int str[1000]={0};
    int t=0;
    while(scanf("%d %d",&n,&k)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&str[i]);
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(str[j]>str[j+1])  //冒泡排序， 交换相邻 大的往后
                {
                    t=str[j];
                    str[j]=str[j+1];
                    str[j+1]=t;
                }
            }
        }
       for(int i=0;i<k;i++)
       {
           printf("%d ",str[i]);
       }
        printf("\n");
    }  
}
