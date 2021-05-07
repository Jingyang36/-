/*
题目描述
找出给定字符串中大写字符(即'A'-'Z')的个数。

输入描述:
本题含有多组样例输入
对于每组样例，输入一行，代表待统计的字符串

输出描述:
对于每组样例，输出一个整数，代表字符串中大写字母的个数

示例1
输入
复制
add123#$%#%#O
150175017(&^%&$vabovbao
输出
复制
1
0
*/
#include <stdio.h>
#include <string.h>
int main(){
    char str[10000];
    while(gets(str)){
        int i=0,n=0;
        while(str[i]!='\0'){
            for(i = 0; i< strlen(str);i++){
            if(str[i]>='A'&&str[i]<='Z'){
                n++;
            }
            }
        }
        printf("%d\n",n);
    }
    return 0;
}
