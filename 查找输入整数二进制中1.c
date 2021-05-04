/*
输入一个正整数，计算它在二进制下的1的个数。
输入
复制
5
输出
复制
2
说明
5的二进制表示是101，有2个1 
*/

#include <stdio.h>

int main()
{
    int n = 0;
    while(scanf("%d",&n)!=EOF)
    {
        int count = 0;
        while(n!=0)
        {
            if(n%2 == 1)
            {
                count++;
            }
            n = n/2;
        }
        printf("%d\n",count);
    }
    return 0;
}
