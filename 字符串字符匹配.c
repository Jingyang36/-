/*
题目描述
判断短字符串中的所有字符是否在长字符串中全部出现。
请注意本题有多组样例输入。



输入描述:
输入两个字符串。第一个为短字符串，第二个为长字符串。两个字符串均由小写字母组成。

输出描述:
如果短字符串的所有字符均在长字符串中出现过，则输出true。否则输出false。

示例1
输入
复制
bc
abc
输出
复制
true
*/
//多定义一个字符串flag，第一个字符串中有与第二个字符串相同的字符时，
//将flag中相应的字符置为‘a’或其他都可以，最后判断flag与第一个字符串长度是否相同

#include <string.h>
#include <stdio.h>

int main()
{
    char Short[100];
    while(scanf("%s",Short)!=EOF)
    {
        char Long[100];
        char Flag[100] = {0};
        scanf("%s",Long);
        for(int i = 0; i < strlen(Short);i++){
            for(int j = 0; j < strlen(Long);j++)
            {
                if(Short[i] == Long[j])
                    Flag[i] = 'a';
            }
        }
        if(strlen(Short)==strlen(Flag))
            printf("true\n");
        else
            printf("false\n");
    }
    return 0;
}
