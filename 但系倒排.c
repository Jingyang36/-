/*
题目描述
对字符串中的所有单词进行倒排。

说明：

1、构成单词的字符只有26个大写或小写英文字母；

2、非构成单词的字符均视为单词间隔符；

3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；

4、每个单词最长20个字母；

输入描述:
输入一行以空格来分隔的句子

输出描述:
输出句子的逆序

示例1
输入
复制
I am a student
输出
复制
student a am I
示例2
输入
复制
$bo*y gi!r#l
输出
复制
l r gi y bo

二维数组倒序输出
*/


#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100][21], temp[1001];
    int n = 0, len = 0, i, j = 0;
    memset(str,0,sizeof(str));
    
    while(fgets(temp, sizeof(temp), stdin))
    {
        len = strlen(temp);
        for(i = 0; i < len; i++)
        {
            if((temp[i] >= 'a' && temp[i] <= 'z') || (temp[i]>= 'A' && temp[i] <= 'Z'))
            {
                str[n][j] = temp[i]; //入栈
                j++;
            }else if (j > 0){
                j = 0;
                n++;
            }
        }
    }
    for(i = n-1;i>0;i--){
        printf("%s ",str[i]);//空格
    }
    printf("%s\n",str[0]);
    return 0;
}
