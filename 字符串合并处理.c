/*
题目描述
按照指定规则对输入的字符串进行处理。

详细描述：

将输入的两个字符串合并。




举例：输入str1为"dec"，str2为"fab"，合并为“decfab”，分别对“dca”和“efb”进行排序，排序后为“abcedf”，转换后为“5D37BF”

注意本题含有多组样例输入


输入描述:
本题含有多组样例输入。每组样例输入两个字符串，用空格隔开。

输出描述:
输出转化后的结果。每组样例输出一行。

示例1
输入
复制
dec fab
输出
复制
5D37BF

{}{}
*/

//0123456789abcdefABCDEF
//084C2A6E195D3B7F5D3B7F

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

int main()
{
    char str1[100], str2[100];
    char dict[17] = "084C2A6E195D3B7F";
    int i, j, len;
    char t;

    while (scanf("%s %s", str1, str2) != EOF)
    {
        strcat(str1, str2);
        len = strlen(str1);
        for (i = 0; i < len - 2; i += 2)
        {
            for (j = 0; j < len - 2 - i; j += 2) //按偶数排序
            {
                if (str1[j] > str1[j + 2]) //交换
                {
                    t = str1[j + 2];
                    str1[j + 2] = str1[j];
                    str1[j] = t;
                }
            }   
        }
        for (i = 1; i < len - 1; i += 2) //奇数排序
        {
            for (j = 1; j < len - 1 - i; j += 2)
            {
                if (str1[j] > str1[j + 2])
                {
                    t = str1[j + 2];
                    str1[j + 2] = str1[j];
                    str1[j] = t;
                }
            }   
        }
        for(i = 0;i < len;i++)
        {
            if(str1[i] <= '9' && str1[i] >= '0')
                str1[i] = dict[str1[i] - '0'];
            else if(str1[i] <= 'F' && str1[i] >= 'A')
                str1[i] = dict[str1[i] - 'A' + 10];
            else if(str1[i] <= 'f' && str1[i] >= 'a')
                str1[i] = dict[str1[i] - 'a' + 10];
        }
        puts(str1);
    }
    
         
    return 0;
}
