/*
动态规划
https://blog.csdn.net/Young824/article/details/111285944?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-0&spm=1001.2101.3001.4242
Levenshtein 距离，又称编辑距离，指的是两个字符串之间，由一个转换成另一个所需的最少编辑操作次数。许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。编辑距离的算法是首先由俄国科学家Levenshtein提出的，故又叫Levenshtein Distance。

Ex：

字符串A:abcdefg

字符串B: abcdef

通过增加或是删掉字符”g”的方式达到目的。这两种方案都需要一次操作。把这个操作所需要的次数定义为两个字符串的距离。

要求：

给定任意两个字符串，写出一个算法计算它们的编辑距离。



本题含有多组输入数据。
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 300
#define min(x,y) (x < y ? x : y)

int main()
{
    //dp[i][j]:str1前i 到 str22前j
    char str1[MAXSIZE] = {'\0'}, str2[MAXSIZE] = {'\0'};
    while(scanf("%s%s",str1,str2)!= EOF)
    {
        int i, j, len1 = strlen(str1), len2 = strlen(str2);
        int **dp = (int**)calloc(len1+1, sizeof(int*)); //二维数组 **dp
        for (i = 0; i < len1 + 1; i++)
        {
            dp[i] = (int*)calloc(len2 + 1, sizeof(int));
            dp[i][0] = i;
        }
        for (i = 0; i < len2 + 1; i++)
        {
            dp[0][i] = i;
        }
        for (i = 1; i < len1 + 1; i ++)
        {
            for (j = 1; j < len2 + 1; j++)
            {
                int temp = min(dp[i][j-1],dp[i-1][j])+1;
                dp[i][j] = min((str1[i-1] == str2[j-1] ? 0 : 1) + dp[i-1][j-1],temp);
                    
            }
        }
        printf("%d\n",dp[len1][len2]);
        free(dp);
        
    }
     return 0;  
}
