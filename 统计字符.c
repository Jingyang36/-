/*
输入一行字符，分别统计出包含英文字母、空格、数字和其它字符的个数。

本题包含多组输入。

1qazxsw23 edcvfr45tgbn hy67uj m,ki89ol.\\/;p0-=\\][
26
3
10
12

*/

#include <stdio.h>
#include <string.h>


int main()
{
    char String[1000];
    
    while(gets(String)!=NULL) //gets 可以接收空格 scanf遇到空格认为输入 不能用
    {
        int Length = strlen(String);
        int CountEN = 0;
        int CountEmpty = 0;
        int CountNumber = 0;
        int CountOther = 0;
        
        for (int i = 0; i < Length; i++)
        {
            if (String[i] >= 'a' && String[i] <= 'z' || String[i] >='A' && String[i] <= 'Z'){
                CountEN ++;
            }
            else if (String[i] == ' '){
                CountEmpty ++;
            }
            else if (String[i] >= '0' && String[i] <='9'){
                CountNumber ++;
            }
            else 
                CountOther ++;
            
        }
        printf("%d\n",CountEN);
        printf("%d\n",CountEmpty);
        printf("%d\n",CountNumber);
        printf("%d\n",CountOther);
    }
    return 0;
}
