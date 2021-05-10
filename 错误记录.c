/*
目描述
开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。


处理：


1、 记录最多8条错误记录，循环记录，最后只用输出最后出现的八条错误记录。对相同的错误记录只记录一条，但是错误计数增加。最后一个斜杠后面的带后缀名的部分（保留最后16位）和行号完全匹配的记录才做算是”相同“的错误记录。
2、 超过16个字符的文件名称，只记录文件的最后有效16个字符；
3、 输入的文件可能带路径，记录文件名称不能带路径。
4、循环记录时，只以第一次出现的顺序为准，后面重复的不会更新它的出现时间，仍以第一次为准

输入描述:
每组只包含一个测试用例。一个测试用例包含一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。

输出描述:
将所有的记录统计并将结果输出，格式：文件名 代码行数 数目，一个空格隔开，如：

示例1
输入
复制
D:\zwtymj\xccb\ljj\cqzlyaszjvlsjmkwoqijggmybr 645
E:\je\rzuwnjvnuz 633
C:\km\tgjwpb\gy\atl 637
F:\weioj\hadd\connsh\rwyfvzsopsuiqjnr 647
E:\ns\mfwj\wqkoki\eez 648
D:\cfmwafhhgeyawnool 649
E:\czt\opwip\osnll\c 637
G:\nt\f 633
F:\fop\ywzqaop 631
F:\yay\jc\ywzqaop 631
输出
复制
rzuwnjvnuz 633 1
atl 637 1
rwyfvzsopsuiqjnr 647 1
eez 648 1
fmwafhhgeyawnool 649 1
c 637 1
f 633 1
ywzqaop 631 2
*/
#include <stdio.h>
#include <string.h>

struct list{
    char name[200];
    int number;
    int times;
};
//structure 记录保存

int main()
{
    char str[200];
    int num, head = 0;
    struct list lists[100];
    while(scanf("%s %d",str,&num)!=EOF)
    {
        //查找分隔符
        char *p = strrchr(str, '\\');
        p++;
        //保留16
        if(strlen(p) > 16)
        {
            p = p + (strlen(p) - 16);
        }
        //查重
        int flag = 0;//是否重复
        for(int i = 0; i < head; i++)
        {
            if((strcmp(lists[i].name, p) == 0) && num == lists[i].number )
            {
                lists[i].times++;
                flag = 1;
                break;
            }
        }
        if(!flag)//无重复
        {
            strcpy(lists[head].name, p);
            lists[head].number = num;
            lists[head].times = 1;
            head++;
        }
    }
    
    //最后八条
    int k = head-8>0 ? head - 8 : 0;
    for (int i = k; i < head; i++)
    {
        printf("%s %d %d\n",lists[i].name, lists[i].number, lists[i].times);
    }
    return 0;
    
}
