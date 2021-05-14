/*
原理：ip地址的每段可以看成是一个0-255的整数，把每段拆分成一个二进制形式组合起来，然后把这个二进制数转变成
一个长整数。
举例：一个ip地址为10.0.3.193
每段数字             相对应的二进制数
10                   00001010
0                    00000000
3                    00000011
193                  11000001

组合起来即为：00001010 00000000 00000011 11000001,转换为10进制数就是：167773121，即该IP地址转换后的数字就是它了。

本题含有多组输入用例，每组用例需要你将一个ip地址转换为整数、将一个整数转换为ip地址。



输入描述:
输入 
1 输入IP地址
2 输入10进制型的IP地址

输出描述:
输出
1 输出转换成10进制的IP地址
2 输出转换后的IP地址

示例1
输入
复制
10.0.3.193
167969729
输出
复制
167773121
10.3.3.193


*/

#include <stdio.h>
 
int main()
{
    int a, b, c, d;
    unsigned int n1, n2;
    
    while(scanf("%d.%d.%d.%d",&a,&b,&c,&d)!=EOF)
    {
        scanf("%u",&n1);
        n2 = (a<<24)+(b<<16)+(c<<8) + d;
        printf("%u\n",n2);
        
        a = (n1>>24);
        b = (n1>>16)&255;
        c = (n1>>8)&255;
        d = n1&255;
        printf("%d.%d.%d.%d\n",a,b,c,d);
    }
    return 0;
}
