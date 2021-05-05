/*
查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
注：子串的定义：将一个字符串删去前缀和后缀（也可以不删）形成的字符串。请和“子序列”的概念分开！

abcdefghijklmnop
abcsafjklmnopqrstuvw

jklmnop

动态规划

思路：

最大公共子串与最长公共子序列不同

str1 = “12345”   str2 = “123abc45”

最长公共子串：123
最长公共子序列：12345

这两个都可以用动态规划，只是状态转移方程有区别

首先两者都要创建一个二维数组dp[m][n]，并且初始化二维数组的内容为0：
然后，i 和j 分别从1开始，i++，j++循环：
  如果str1[i-1] == str2[j-1]，则dp[i][j] = dp[i-1][j-1] + 1；
  如果str1[i-1] != str2[j-1]，则
    dp[i][j] = 0（最长公共子串）
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])（最长公共子序列）

现在我们要打印出最长公共子串，由于已知最长公共子串的长度，因此可以在str1中截取等长的字符串，然后和str2匹配。

当寻找最长公共子序列时，
i和j分别从m，n开始，递减循环直到i = 0，j = 0。其中，m和n分别为两个串的长度。

如果str1[i] == str2[j]，则将str[i]字符插入到子序列内，i–，j–；
如果str1[i] != str[j]，则比较dp[i,j-1]与dp[i-1,j]，dp[i,j-1]大，则j–，否则i–；（如果相等，则任选一个）

*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 1500

int main()
{
    int dp[MAX][MAX] = {0};
    char str1[MAX] = {'\0'}, str2[MAX] = {'\0'};
    while(scanf("%s%s",str1,str2)!=EOF)
    {
       // gets(str2);
        int i, j, len1 = strlen(str1), len2 = strlen(str2);
        
        //str1短字符
        if(len1 > len2) //swap
        {
            char temp[MAX] = {'\0'};
            strcpy(temp, str1);
            strcpy(str1, str2);
            strcpy(str2, temp);
            //长度
            len1 += len2;
            len2 = len1 - len2;
            len1 = len1 - len2;
        }
        //maxlen记录最长公共子串长度，index记录第一个最长子串最后有个字符位置
        int maxlen = 0,index;
        for (i = 0; i < len1; i++)
        {
            for (j = 0; j < len2; j++)
            {
                if(str1[i] == str2[j])//相同字符
                {
                    dp[i+1][j+1] = dp[i][j] + 1;
                    if(maxlen < dp[i+1][j+1])
                    {
                        maxlen = dp[i+1][j+1];
                        index = i;
                    }
                }
                else{
                    dp[i+1][j+1] = 0;//无相同
                }
            }
        }
        char out[MAX] = {'\0'};
        strncpy(&out, &str1[index - maxlen + 1], maxlen);//copy n 个
      //  strcpy(out, &str1[index - maxlen + 1]);
        printf("%s\n",out);
    }
    return 0;

}
