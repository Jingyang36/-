/*


最长回文子串 动态规划 mancher
去掉两头仍是回文串 
dp[j][j]=true (j=1)
        str[i] == str[j] i-j=1
        str[i] == str[j]&&dp[j+1][i-1], i-j>1

P(i,j)=P(i+1,j−1)∧(Si==Sj)
*/ 

// #include <stdio.h>
// #include <string.h>
// #include <stdbool.h>

// int main()
// {
//     char str[100] = {0};
//     memset(str,0,sizeof(str));

//     while(scanf("%s",str)!=EOF)
//     {
//         int len = strlen(str);
//         bool dp[len][len];
//         int max = 1; //最长回文初始
//         for(int i = 0; i < len; i ++){
//             for(int j = 0; j < i; j++){
//                 //dp[j][i] 是
//                 if(i == j) 
//                     dp[j][i] = true;
//                 else if(i-j==1) 
//                     dp[j][i] = (str[i]==str[j]);
//                 else dp[j][i] = (str[j]==str[i]&&dp[j+1][i-1]);
//                 //若s.substr(j,i-j+1)是回文子串，更新当前最长回文子串的长度*/
//                 if(dp[j][i]&& max<i-j+1)
//                     max = i - j + 1;       
//                //continue;
                
//             }
//         }
//         printf("%d\n",max);
//     }
//     return 0;
// }

/*
解题思路 中心扩散发
三个指针，一个左移的指针，一个右移指针，一个中心指针一直右移
1、初始化 r = l = index
2、把index和r+1的位置进行比较如果相等，则把r++，同时中心指针也右移 //如abbbbc的情况
3、无法再右移了，则进行由中心像两侧扩展，l-1,r+1进行对比判断，知道不成立为止。
4、记录最大值对应的起始地址和大小。

*/

#include <stdio.h>
#include <string.h>

#include <stdio.h>
/*
思路：常规的暴力解法，O(n^2)，16ms

遍历字符串
对于每个字母，向两侧扩散，判断是否回文子串
若为回文子串，保存最长的子串信息
子串长度为奇数或偶数，需分别判断


*/
int process(char str[])
{
    int len = strlen(str);
    int left, right, max1 = 0, max2 = 0;
    for (int i = 0; i < len; i++)
    {
        left = i; right = i + 1;
        int temp = 0; //以 i 为中心，向两侧延伸，直到不再满足回文
        while (left >= 0 && right < len && (str[left] == str[right]))
        {
            left--;
            right++;
        }
        temp = right - left - 1; //重复包含i 减去
        if (temp > max2)
            max2 = temp;

        left = i; right = i + 2;
        while (left >= 0 && right < len && (str[left] == str[right]))
        {
            left--;
            right++;
        }
        temp = right - left - 1;
        if (temp > max2)
            max2 = temp;
    }
    if (max2 > max1)
        return max2;
    return max1;
}

int main()
{
    char word[10000];
    while (gets(word))
    {
        printf("%d\n", process(word));
    }
    return 0;
}
