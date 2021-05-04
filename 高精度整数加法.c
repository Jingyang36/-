/*
输入两个用字符串表示的整数，求它们所表示的数之和。
字符串的长度不超过10000。
本题含有多组样例输入。
输入
复制
9876543210
1234567890
输出
复制
11111111100

*/

#include <stdio.h>
#include <string.h>
#define MAXNUMS 10000

int main()
{
    char str1[MAXNUMS];
    char str2[MAXNUMS];
    while(scanf("%s%s",str1,str2)!=EOF)
    {
        int length1 = strlen(str1);
        int length2 = strlen(str2);
        int i = 0, carry = 0, j = 0;
        int num1[MAXNUMS] = {0};
        int num2[MAXNUMS] = {0};
        int result[MAXNUMS] = {0};
        
        for(i = 0; i < length1; i++)
        {
            num1[i] = str1[length1 - 1 - i] - '0';
        }
        for(i = 0; i < length2; i++)
        {
            num2[i] = str2[length2 - 1 - i] - '0';
        }
        
        int length = length1 > length2 ? length1 : length2;
        for(i = 0; i < length + 1; i++)
        {
            result[i] = (num1[i] + num2[i] + carry)%10;
            carry = (num1[i] + num2[i] + carry) > 9? 1 : 0; //迭代
        }
        for(j = i - 1; j >= 0; j--) //从最高位加
        {
            if((j==i-1)&&(result[j]==0))
                continue;
            else
                printf("%d",result[j]);
        }
                printf("\n");
    }
    return 0;
}
