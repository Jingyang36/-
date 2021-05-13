/*
题目描述
1、对输入的字符串进行加解密，并输出。

2、加密方法为：

当内容是英文字母时则用该英文字母的后一个字母替换，同时字母变换大小写,如字母a时则替换为B；字母Z时则替换为a；

当内容是数字时则把该数字加1，如0替换1，1替换2，9替换0；

其他字符不做变化。

3、解密方法为加密的逆过程。


本题含有多组样例输入。
输入描述:
输入说明
输入一串要加密的密码
输入一串加过密的密码

输出描述:
输出说明
输出加密后的字符
输出解密后的字符

示例1
输入
复制
abcdefg
BCDEFGH
输出
复制
BCDEFGH
abcdefg

查找两个数组
*/

#include <string.h>
#include <stdio.h>
#include <ctype.h>

 //密码本
char a[]="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char b[]="1234567890BCDEFGHIJKLMNOPQRSTUVWXYZAbcdefghijklmnopqrstuvwxyza";

int main()
{
    char c[100];
    while(fgets(c,100,stdin))
    {
        for(int i = 0; i < strlen(c) ; i++)
        {
            for(int j = 0; j < strlen(a);j++)
            {
                if(c[i] == a[j])
                {
                    c[i] = b[j];
                    break;
                }
            }            
        }
        printf("%s",c);//加密
        memset(c, '\0', sizeof(c));
        
        fgets(c, 100, stdin);
        for(int i = 0; i < strlen(c) ; i++)
        {
            for(int j = 0; j < strlen(a); j++)
            {
                if(c[i] == b[j])
                {
                    c[i] = a[j];
                    break;
                }
            }
        }
        printf("%s",c);
    }
    return 0;
}
