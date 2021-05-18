/*
题目描述
从输入任意个整型数，统计其中的负数个数并求所有非负数的平均值，结果保留一位小数，如果没有非负数，则平均值为0
本题有多组输入数据，输入到文件末尾，请使用while(cin>>)读入
数据范围小于1e6
输入描述:
输入任意个整数，每行输入一个。

输出描述:
输出负数个数以及所有非负数的平均值

示例1
输入
复制
-13
-4
-7
输出
复制
3
0.0
*/

#include <stdio.h>
int num;
int main()
{
    int count1 = 0;
    int count2 = 0;

    int sum = 0;
    
    while(scanf("%d",&num)!=EOF)
    {
        if(num<0){
            count1++;
        }else{
            count2++;
            sum+=num;
        }
    }
    float mean = 0.0;
    //if(count1 == 0) mean = 0;
    if(count2!=0) 
        mean = (float)sum/(float)count2;
    
    printf("%d\n%.1f\n",count1,mean);
    return 0;
}
