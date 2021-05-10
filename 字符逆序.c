/*
目描述
将一个字符串str的内容颠倒过来，并输出。str的长度不超过100个字符。


输入描述:
输入一个字符串，可以有空格

输出描述:
输出逆序的字符串

示例1
输入
复制
I am a student
输出
复制
tneduts a ma I

*/

#include <stdio.h>
#include <string.h>

int main()
{
    //int n = 100;
    char str[100];
    char reverse[100];
    gets(str);
    int len = strlen(str);
    for(int i = 0; i < len; i++)
    {
        reverse[i] = str[len - 1 - i];
    }
    printf("%s",reverse);
    return 0;
}
