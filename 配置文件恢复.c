/*
题目描述
有6条配置命令，它们执行的结果分别是：

命   令	执   行
reset	reset what
reset board	board fault
board add	where to add
board delete	no board at all
reboot backplane	impossible
backplane abort	install first
he he	unknown command
注意：he he不是命令。

为了简化输入，方便用户，以“最短唯一匹配原则”匹配：
1、若只输入一字串，则只匹配一个关键字的命令行。例如输入：r，根据该规则，匹配命令reset，执行结果为：reset what；输入：res，根据该规则，匹配命令reset，执行结果为：reset what；
2、若只输入一字串，但本条命令有两个关键字，则匹配失败。例如输入：reb，可以找到命令reboot backpalne，但是该命令有两个关键词，所有匹配失败，执行结果为：unknown command
3、若输入两字串，则先匹配第一关键字，如果有匹配但不唯一，继续匹配第二关键字，如果仍不唯一，匹配失败。例如输入：r b，找到匹配命令reset board 和 reboot backplane，执行结果为：unknown command。

4、若输入两字串，则先匹配第一关键字，如果有匹配但不唯一，继续匹配第二关键字，如果唯一，匹配成功。例如输入：b a，无法确定是命令board add还是backplane abort，匹配失败。
5、若输入两字串，第一关键字匹配成功，则匹配第二关键字，若无匹配，失败。例如输入：bo a，确定是命令board add，匹配成功。
6、若匹配失败，打印“unknown command”


输入描述:
多行字符串，每行字符串一条命令

输出描述:
执行结果，每条命令输出一行

字符串比较 空格输入字符串
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *cmd1[6] = {"reset", "reset", "board", "board", "reboot", "backplane"};
char *cmd2[6]= {"no use", "board", "add", "delete", "backplane", "abort"};

void cmd_out(int index)
{
    switch(index)
    {
        case 0:
            printf("reset what\n");
            break;
        case 1:
            printf("board fault\n");
            break;
        case 2:
            printf("where to add\n");
            break;
        case 3:
            printf("no board at all\n");
            break;
        case 4:
            printf("impossible\n");
            break;
        case 5:
            printf("install first\n");
            break;
        default:
            printf("unknown command\n");
            break;
    }
}

int main()
{
    char input[28] = {'\0'};
    while(gets(input)) //有空格 重点
    {
        int len = strlen(input);
        if(len > 16)//最长
        {
            printf("unknown command\n");
            continue;
        }
        int blank_flag = 1, pos; //blank_flag 是否有空格 ，pos位置
        for(int i = 0; i < len; i++)
        {
             if(input[i] == ' ')
             {
                 blank_flag = 0;
                 pos = i;
                 break;                    
             }
        }
        //输入字符
        if(blank_flag) //一个 无空格
        {
            if (strncmp(input, cmd1[0], len) == 0)
                printf("reset what\n");
            else
                printf("unknown command\n");
        }
        else //两个 有空格
        {
            int count = 0, index;
            for (int i = 1; i < 6; i++)
            {
                if (strncmp(input, cmd1[i], pos) == 0 && 
                    strncmp(input + pos + 1, cmd2[i], len - pos - 1) == 0)//相同输入
                {
                    count ++;
                    index = i;
                }
            }
            if (count == 1)
                cmd_out(index);
            else 
                printf("unknown command\n");
        }
    }
    return 0;
}
