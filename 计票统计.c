/*
题目描述
请实现一个计票统计系统。你会收到很多投票，其中有合法的也有不合法的，请统计每个候选人得票的数量以及不合法的票数。
本题有多组样例输入。
输入描述:
输入候选人的人数n，第二行输入n个候选人的名字（均为大写字母的字符串），第三行输入投票人的人数，第四行输入投票。

输出描述:
按照输入的顺序，每行输出候选人的名字和得票数量，最后一行输出不合法的票数。

示例1
输入
复制
4
A B C D
8
A D E CF A GG A B
输出
复制
A : 3
B : 1
C : 0
D : 1
Invalid : 3
*/

#include"stdio.h"
int main(void)
{
    int n;
    while(scanf("%d", &n) != EOF)    //第一行输入候选人数
    {
        char name[50][20] = {0}, buf[20];  //定义二位数组用来存放候选人的名字
        int cnt[50] = {0}, Invalid =0;
        //memset(buf, 0, sizeof(name));   //数组清零
        int  m;
        for(int i = 0; i < n; i++)
        {
            scanf("%s", name[i]);  //第二行输入n个候选人的名字
        }
        scanf("%d", &m);     //第三行输入投票的人数
        for(int i = 0; i < m; i++)
        {
            //memset(buf, 0, 20);
            scanf("%s", buf);    //第四行输入投票
            for(int j = 0; j<n; j++)
            {
                if(0==strcmp(buf,name[j]))   //投票与名字相匹配
                {
                    cnt[j]++;   //记录票数
                    break;
                }
                if(j==n-1)       //因为每当到输入一个投票都要进行n次比较，到n-1次都没有跳出if语句说明不合法
                    Invalid ++;
            }
        }
        for(int i = 0; i < n; i++)
        {
            printf("%s : %d\n", name[i],cnt[i]);    //打印出名字以及相印的票数
        }
        printf("Invalid : %d\n", Invalid);   //打印出无效票数
    }
}
