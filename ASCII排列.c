/*
ASCII码值从小到大）排列收好。
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[1024]; //数组存放字符
    while (scanf("%s", s) != EOF) {
        int a[1025] = { 0 }; //记录字符存放个数
        int len = strlen(s);
        for (int i = 0; i < len; i++) //遍历整个字符串
        {
            a[s[i]]++; //对应ASCII码+1
        }
        for (int i = 0; i < 1025; i++) //遍历数组a
        {
            while (a[i] != 0) //如果a里面的字符还有
            {
                printf("%c", i);//从大到小
                a[i]--;
            }
        }
        printf("\n");
    }
}
