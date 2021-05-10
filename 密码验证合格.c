/*

密码要求:

1.长度超过8位

2.包括大小写字母.数字.其它符号,以上四种至少三种

3.不能有相同长度大于2的子串重复

输入描述:
一组或多组长度超过2的字符串。每组占一行

输出描述:
如果符合要求输出：OK，否则输出NG

示例1
输入
复制
021Abc9000
021Abc9Abc1
021ABC9000
021$bc9000
输出
复制
OK
NG
NG
OK

//思路  1.长度超过8位
// 判断输入字符串的长度
//2.包括大小写字母.数字.其它符号,以上四种至少三种
// 将类型设置为加加法 判断四种情况加起来的值与2的关系
//3.不能有相同长度大于2的子串重复
// 相同子串的判断 设定i 和j 两重循环
*/

#include <stdio.h>
#include <string.h>
int main()
{
    char str[100] = {0};
    while(scanf("%s",str)!=EOF)
    {
        int len, upper = 0, lower = 0, digit = 0, other = 0, flag = 1;
        len = strlen(str);
        if(len<=8)
        {
            printf("NG\n");
            continue;
        }
        for(int i = 0; i < len; i++)
        {
            if((str[i]>='a' && str[i] <='z'))
            {
                lower = 1;
            }
            else if(str[i]>='A' && str[i] <= 'Z')
            {
                upper = 1;
            }
            else if(str[i] >= '0' && str[i] <='9')
            {
                digit = 1;
            }
            else
                other = 1;
            
            //相同子串大于2
            char temp[3];
            temp[0] = str[i];
            temp[1] = str[i+1];
            temp[2] = str[i+2];
            for(int j = i+3; j < len; j++)
            {
                if(str[j]==temp[0] && str[j+1] == temp[1] && str[j+2] == temp[2])
                {
                    flag = 0;
                    printf("NG\n");
                }
            }            
        }
        if(lower+upper+digit+other>=3 && flag == 1)
            printf("OK\n");
        else if(lower + upper + digit + other < 3)
            printf("NG\n");
    }
    return 0;
}
