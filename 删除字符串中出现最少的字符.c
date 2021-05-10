/*
题目描述
实现删除字符串中出现次数最少的字符，若多个字符出现次数一样，则都删除。输出删除这些单词后的字符串，字符串中其它字符保持原来的顺序。
注意每个输入文件有多组输入，即多个字符串用回车隔开
输入描述:
字符串只包含小写英文字母, 不考虑非法输入，输入的字符串长度小于等于20个字节。

输出描述:
删除字符串中出现次数最少的字符后的字符串。

示例1
输入
复制
abcdd
aabcddd
输出
复制
dd
aaddd
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[30];
    while(scanf("%s",str)!=EOF)
    {
        int flag[26] = {0};
       // int min = 20;
        int len = strlen(str);
        
        //每个字符出现次数
        for(int i = 0; i < len;i++)
        {
            flag[str[i]-'a']++; //flag[26] = {1,0,0,0,3,0...} a出现1次， e 三次
        }
        //最小次数
        int min = flag[str[0] - 'a'];
        for(int i = 0; i < len; i++)
        {
            if(flag[str[i] - 'a'] <= min)
                min = flag[str[i] - 'a'];
        }
        //输出次数大于最小的字符
        for(int i = 0; i < len; i++)
        {
            if(flag[str[i] - 'a'] > min)
                printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}
