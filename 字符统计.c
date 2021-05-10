/*
题目描述
输入一个只包含小写英文字母和数字的字符串，按照不同字符统计个数由多到少输出统计结果，如果统计的个数相同，则按照ASCII码由小到大排序输出。
本题含有多组样例输入

输入描述:
一个只包含小写英文字母和数字的字符串。

输出描述:
一个字符串，为不同字母出现次数的降序表示。若出现次数相同，则按ASCII码的升序输出。

示例1
输入
复制
aaddccdc
1b1bbbbbbbbb
输出
复制
cda
b1
说明
第一个样例里，c和d出现3次，a出现2次，但c的ASCII码比d小，所以先输出c，再输出d，最后输出a.
*/

/*
    此题使用hash table思想
    首先将字符串中每个字符出现的次数统计一次，并求出出现最多的字符个数
    内循环遍历hash table，当哈希表中的值等于最大值时，打印对应的字符，
    内遍历结束外循环再将max减一
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    while(scanf("%s",s) != EOF)
    {
        int len = strlen(s);
        int a[128] = {0};
        int i,max = 0;
        for(i = 0; i < len; i++)
            a[s[i]]++;
        for(i = 0; i < len; i++)
            if(max < a[s[i]])
                max = a[s[i]];
        while(max)
        {
            for(i = 0; i < 128; i++)
            {
                if(a[i] == max)
                    printf("%c",i);
            }
            max--;
        }
        printf("\n");
    }
    return 0;
}
