/*
输入描述:
输入一个字符串。

输出描述:
输出字符串中最长的数字字符串和它的长度，中间用逗号间隔。如果有相同长度的串，则要一块儿输出（中间不要输出空格）。

示例1
输入
复制
abcd12345ed125ss123058789
a8a72a6a5yy98y65ee1r2
输出
复制
123058789,9
729865,2
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];
    while(scanf("%s",str)!=EOF){
        int count = 0;
        int cur;
        int Max = 0;
        int len = strlen(str);
        
        for(int i = 0; i < len; i++)
        {
            if(str[i] >= '0' && str[i] <= '9')
                count ++;
            else
                count = 0; //中断 清零 连续才计数
            if(Max < count)
                Max = count;
        }
        
        count = 0;
        for(int i = 0; i < len; i++)
        {
            if(str[i] >= '0' && str[i] <= '9')
                count ++;
            else
                count = 0;
            if(Max == count) //最大长度时
            {
                cur = i - Max;
                for(int i = cur + 1; i < cur + Max + 1; i++)
                    printf("%c",str[i]);
            }               
        }
        printf(",%d\n",Max);
    }
    return 0;
}
