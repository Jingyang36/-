/*

题目描述
给定一个仅包含小写字母的字符串，求它的最长回文子串的长度。
所谓回文串，指左右对称的字符串。
所谓子串，指一个字符串删掉其部分前缀和后缀（也可以不删）的字符串
（注意：记得加上while处理多个测试用例）

输入描述:
输入一个仅包含小写字母的字符串

输出描述:
返回最长回文子串的长度

示例1
输入
复制
cdabbacc
输出
复制
4
说明
abba为最长的回文子串 

动态规划

思想：
        对于一个回文字符串，其正反都是一样的，利用这一点，对于带有干扰项的回文字符串str1，将其逆序得到str2，其中的回文字符串部分还是和逆序前一样，但是干扰项却与之前不同。
动态规划过程：
        dp含义：建立一个二维数组dp，dp[i][j]代表str2中第i个元素和str1中第j个元素相等时，两者有几个字符是连续相同的
        状态转移方程：dp[i][j] = dp[i-1][j-1] + 1;  即如果当前str2中第i个字符和str1中第j个字符相等，则此时连续相等的字符个数为str2中前i-1个和str1中前j-1个中相等的个数加1。如下图所示。
        初始化条件：为了防止越界，dp数组长度比字符串长度大1，初始值为0。
        
        递归翻转字符串
*/

/*

题目描述
给定一个仅包含小写字母的字符串，求它的最长回文子串的长度。
所谓回文串，指左右对称的字符串。
所谓子串，指一个字符串删掉其部分前缀和后缀（也可以不删）的字符串
（注意：记得加上while处理多个测试用例）

输入描述:
输入一个仅包含小写字母的字符串

输出描述:
返回最长回文子串的长度

示例1
输入
复制
cdabbacc
输出
复制
4
说明
abba为最长的回文子串

动态规划

思想：
        对于一个回文字符串，其正反都是一样的，利用这一点，对于带有干扰项的回文字符串str1，将其逆序得到str2，其中的回文字符串部分还是和逆序前一样，但是干扰项却与之前不同。
动态规划过程：
        dp含义：建立一个二维数组dp，dp[i][j]代表str2中第i个元素和str1中第j个元素相等时，两者有几个字符是连续相同的
        状态转移方程：dp[i][j] = dp[i-1][j-1] + 1;  即如果当前str2中第i个字符和str1中第j个字符相等，则此时连续相等的字符个数为str2中前i-1个和str1中前j-1个中相等的个数加1。如下图所示。
        初始化条件：为了防止越界，dp数组长度比字符串长度大1，初始值为0。

        递归翻转字符串
*/

#include <stdio.h>
#include <string.h>


int main(void)
{
    char pFirstStr[10000];    // 行
    char pSecondStr[10000];   // 列
    while (scanf("%s", pFirstStr) != EOF)
    {
        const int len = strlen(pFirstStr);
        int m[len][len];
        int max_sub_len = 0;
        for (int i = 0; i < len - 1; i++)
        {
            pSecondStr[len - 1 - i] = pFirstStr[i];
        }
         
        for (int i = 0; i < len; i++)
        {
            if (pFirstStr[0] == pSecondStr[i]) 
            { 
                m[i][0] = 1; 
            }
            else 
            {
                m[i][0] = 0;
            }
             
            if (pFirstStr[i] == pSecondStr[0]) 
            { 
                m[0][i] = 1; 
            }
            else
            {
                m[0][i] = 0;
            }
        }
         
        for (int i = 1; i < len; i++)
        {
            for (int j = 1; j < len; j++)
            {
                if (pFirstStr[j] == pSecondStr[i])
                {
                    m[i][j] = 1 + m[i - 1][j - 1];
                    if (max_sub_len < m[i][j])
                    {
                        max_sub_len = m[i][j];
                    }
                }
                else 
                {
                    m[i][j] = 0;
                }
            }
        }
         
        printf("%d\n", max_sub_len);
    }
     
    return 0;
}
