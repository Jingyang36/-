/*
给出一个名字，该名字有26个字符串组成，定义这个字符串的“漂亮度”是其所有字母“漂亮度”的总和。
每个字母都有一个“漂亮度”，范围在1到26之间。没有任何两个字母拥有相同的“漂亮度”。字母忽略大小写。

给出多个名字，计算每个名字最大可能的“漂亮度”。

整数N，后续N个名字
每个名称可能的最大漂亮程度

2
zhangsan
lisi

192
101

最多出现的字母最大（26）  后面递减乘25.。24.。 

快速排列 C stdlib.h :qsort

qsort(a, 1000, sizeof(int), cmp);
//其中cmp函数应写为：
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b; //由小到大排序
    //return *(int *)b - *(int *)a; 由大到小排序
}

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int cmp(const void* a, const void* b){
    return *(int*)b - *(int*)a;
}

int main()
{
    int n;
    while (scanf("%d",&n) != EOF){
        getchar();
        char str[10000000];
        while(n--){
            gets(str);
            int length = strlen(str);
            int word[26] = {0};
            for (int i = 0; i < length; i++)
            {
                word[tolower(str[i]) - 'a']++;
            }
            qsort(word, 26, sizeof(int), cmp);
            int beauty = 0;
            for (int i = 0; i<26;i++){
                beauty += word[i]*(26 - i); //字母 * 26.。25.。1
                if(word[i] == 0) break;
            }
            printf("%d\n",beauty);
        }
    }
    return 0;
}
