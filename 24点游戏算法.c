/*
24点

问题描述：给出4个1-10的数字，通过加减乘除，得到数字为24就算胜利
输入：
4个1-10的数字。[数字允许重复，但每个数字仅允许使用一次，测试用例保证无异常数字。
输出：

true or false

dfs 搜索
*/

#include <stdio.h>
#include <string.h>

int input[4] = {0};
int flag[4] = {0};

int Dfs(int num)
{
    if(num == 24)
        return 1;
    for(int i = 0; i < 4; i++)
    {
        if(flag[i]==0)
        {
            flag[i]=1;
            if(Dfs(num+input[i]))
                return 1;
            else if (Dfs(num-input[i]))
                return 1;
            else if (Dfs(num*input[i]))
                return 1;
            else if (Dfs(num/input[i])&&(num%input[i] == 0))
                return 1;
            flag[i] = 0;
        }
    }
    return 0;
}

int main()
{
    while(scanf("%d %d %d %d",&input[0],&input[1],&input[2],&input[3])!=EOF)
    {
        memset(flag,0,sizeof(flag));//填充值
        if(Dfs(0))
            printf("true\n");
        else
            printf("false\n");
               
    }
    return 0;
}
