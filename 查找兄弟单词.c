/*
题目描述
定义一个单词的“兄弟单词”为：交换该单词字母顺序，而不添加、删除、修改原有的字母就能生成的单词。
兄弟单词要求和原来的单词不同。例如：ab和ba是兄弟单词。ab和ab则不是兄弟单词。
现在给定你n个单词，另外再给你一个单词str，让你寻找str的兄弟单词里，字典序第k大的那个单词是什么？
注意：字典中可能有重复单词。本题含有多组输入数据。
输入描述:
先输入单词的个数n，再输入n个单词。
再输入一个单词，为待查找的单词x
最后输入数字k
输出描述:
输出查找到x的兄弟单词的个数m
然后输出查找到的按照字典顺序排序后的第k个兄弟单词，没有符合第k个的话则不用输出。

输入描述:

先输入字典中单词的个数n，再输入n个单词作为字典单词。

再输入一个单词，查找其在字典中兄弟单词的个数m

再输入数字k



输出描述:

根据输入，输出查找到的兄弟单词的个数m


然后输出查找到的兄弟单词的第k个单词。
示例1
输入
复制
3 abc bca cab abc 1
输出
复制
2
bca

需要排序在输出
*/

#include <stdio.h>
#include <string.h>

int Judge(char *a, char *b)
{
    if(!strcmp(a, b))
        return 0; //相等 不是
    //长度不等不是
    int aLen = strlen(a);
    int bLen = strlen(b);
    if(aLen != bLen)
        return 0;
    
    char c['z' - 'A'] = {0}, d['z' - 'A'] = {0};
    for (int i = 0; i < aLen; i++)
    {
        c[a[i] - 'A']++;
        d[b[i] - 'A']++;
    }
    for(int i = 0; i < 'z' - 'A'; i++)
    {
        if(c[i]!=d[i])
            return 0;
    }
    return 1;
}

int main(void)
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        char str[n][1000], bro[n][1000],x[1000] = {0};
        int k, key = 0;
        for(int i = 0; i < n; i++) //数字
        {
            scanf("%s",str[i]);
        }
        scanf("%s",x);//输入数组
        scanf("%d",&k);
        //获取兄弟单词 排序
        for(int i = 0; i < n; i++)
        {
            if(Judge(x, str[i]))
            {
                strcpy(&bro[key], str[i]);
                //兄弟单词排序
                for(int j = key - 1; j>=0;j--)
                {
                    if(strcmp(str[i], bro[j])<0)
                    {
                        strcpy(&bro[j+1], bro[j]);
                        strcpy(&bro[j], str[i]);
                    }
                }
                key++;
            }
        }
        printf("%d\n",key);
        if(k <= key && k > 0)
        {
            printf("%s\n",bro[k-1]);
        }
    }
    return 0;
}
