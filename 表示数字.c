/*
    题目描述
将一个字符中所有的整数前后加上符号“*”，其他字符保持不变。连续的数字视为一个整数。

注意：本题有多组样例输入。
输入描述:
输入一个字符串

输出描述:
字符中所有出现的数字前后加上符号“*”，其他字符保持不变

示例1
输入
复制
Jkdi234klowe90a3
5151
输出
复制
Jkdi*234*klowe*90*a*3*
*5151*
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000]="";
    
    while(scanf("%s",&str)!=EOF)
    {
        int len = strlen(str);
        for (int i = 0; i < len; i++)
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                printf("*");
                while(str[i] >= '0' && str[i] <= '9')
                {
                    printf("%c",str[i]);
                    i++;
                }
                printf("*");  
                i--;
            }
            else             
                printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}
