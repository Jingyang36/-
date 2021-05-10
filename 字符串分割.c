/*
题目描述
•连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。

输入描述:
连续输入字符串(输入多次,每个字符串长度小于100)

输出描述:
输出到长度为8的新字符串数组

示例1
输入
复制
abc
123456789
输出
复制
abc00000
12345678
90000000
*/

#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int len, res;
    while(gets(str))
    {
    len = strlen(str);
    
    for (int i = 0; i<len; i++)
    {
        if ((i + 1) % 8 == 0) //排除0
            printf("%c\n",str[i]);
        else 
            printf("%c",str[i]);
    }
    
    if (len % 8 != 0)
    {
        res = 8 - len%8;
        for (int i = 0;i<res;i++)
        {
            printf("0");
        }
        printf("\n");
    }
    }
    return 0;
}
