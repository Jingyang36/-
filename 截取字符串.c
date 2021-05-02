/*
输入一个字符串和一个整数k，截取字符串的前k个字符并输出
本题输入含有多组数据
abABCcDEF
6

abABCc

汉字占两个字节，每个字节的ASCII码最高位均为1，由于char默认为带符号类型，
所以汉字的ASCII码小于0，而英文数字等其他字符占一个字节，ASCII码最高位为0，值在0~127之间。
因此，只需要判断该字节是否小于0就能推断出是否为半个汉字。再向前推算有连续几个半个汉字，若有偶数个，
则输出最后半个汉字，否则不输出。

*/

#include <stdio.h>

int main()
{
    char str[100];
    while(scanf("%s", str) != EOF)
    {
        int k;
        scanf("%d", &k);
        str[k] = '\0';
        printf("%s\n", str);
    }
}
