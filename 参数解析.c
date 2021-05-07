/*
题目描述
在命令行输入如下命令：

xcopy /s c:\ d:\，

各个参数如下：

参数1：命令字xcopy

参数2：字符串/s

参数3：字符串c:\

参数4: 字符串d:\

请编写一个参数解析程序，实现将命令行各个参数解析出来。


解析规则：

1.参数分隔符为空格
2.对于用""包含起来的参数，如果中间有空格，不能解析为多个参数。比如在命令行输入xcopy /s "C:\program files" "d:\"时，参数仍然是4个，第3个参数应该是字符串C:\program files，而不是C:\program，注意输出参数时，需要将""去掉，引号不存在嵌套情况。
3.参数不定长
4.输入由用例保证，不会出现不符合要求的输入


输入描述:
输入一行字符串，可以有空格

输出描述:
输出参数个数，分解后的参数，每个参数都独占一行

示例1
输入
复制
xcopy /s c:\\ d:\\
输出
复制
4
xcopy
/s
c:\\
d:\\
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    char str1[100][100] = {0};
    while(gets(str))
    {
        int len = strlen(str);
        int flag = 0, num = 0;
        int i = 0, k = 0;
        while(i < len)
        {
            if(str[i]!=' '){
                k = 0; //完整字符
                while(i < len){
                    if(str[i] == '"' && flag == 0)//第一个引号
                    {
                        i++;
                        flag = 1;
                    }
                    if(str[i] == ' ' && flag == 0)//遇到不带引号字符串内空格
                    {
                        i++;
                        break;
                    }
                    if(str[i] == '"' && flag == 1)//结尾引号
                    {
                        flag = 0;
                        i++;
                        break;
                    }
                    str1[num][k++] = str[i];
                    i++;
                }
                num ++;
            }else{
                i++;
            }
        }
        
        printf("%d\n",num);
        for(i = 0; i < num; i++)
        {
            printf("%s\n",str1[i]);
        }
    }
    return 0;
}

