/*
题目描述
查找和排序

题目：输入任意（用户，成绩）序列，可以获得成绩从高到低或从低到高的排列,相同成绩
都按先录入排列在前的规则处理。

例示：
jack      70
peter     96
Tom       70
smith     67

从高到低  成绩
peter     96
jack      70
Tom       70
smith     67

从低到高

smith     67

jack      70

Tom       70
peter     96

注：0代表从高到低，1代表从低到高

本题含有多组输入数据！
输入描述:
输入多行，先输入要排序的人的个数，然后分别输入他们的名字和成绩，以一个空格隔开

输出描述:
按照指定方式输出名字和成绩，名字和成绩之间以一个空格隔开

示例1
输入
复制
3
0
fang 90
yang 50
ning 70
输出
复制
fang 90
ning 70
yang 50
*/

//structure, 从大 从小冒泡

#include <stdio.h>

typedef struct{
    int grade;
    char name[20];
}person;

int main()
{
    int num = 0, flag = 0;
    
    while(scanf("%d %d",&num,&flag)!=EOF)
    {
        person arr[num];
        person temp;
        for(int i = 0; i < num; i++)
        {
            scanf("%s %d",&arr[i].name, &arr[i].grade);
        }
        if(flag == 1)//小到大
        {
            for(int i = 0; i< num - 1; i++){
                for(int j = 0; j < num - 1 - i; j++)
                {
                    if(arr[j].grade > arr[j+1].grade)
                    {
                        temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }
        }
        
        if(flag == 0) //大到小
        {
            for(int m = 0; m < num - 1; m++){
                for(int n = 0; n < num - 1 - m; n++)
                {
                    if(arr[n].grade < arr[n+1].grade)
                    {
                        temp = arr[n];
                        arr[n] = arr[n+1];
                        arr[n+1] = temp;
                        
                    }
                }
            }
        }
        for(int k = 0; k < num; k++){
            printf("%s %d\n",arr[k].name, arr[k].grade);
        }       
    }
    return 0;
}
