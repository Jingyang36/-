/*
动态规划 -- 穷举 

是否匹配 查找

问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。
要求：
实现如下2个通配符：
*：匹配0个或以上的字符（字符由英文字母和数字0-9组成，不区分大小写。下同）
？：匹配1个字符


输入：
通配符表达式；
一组字符串。


输出：

返回匹配的结果，正确输出true，错误输出false

本题含有多组样例输入！
输入描述:
先输入一个带有通配符的字符串，再输入一个需要匹配的字符串

输出描述:
返回匹配的结果，正确输出true，错误输出false

示例1
输入

te?t*.*
txt12.xls
输出

false

输入:
s = "adceb"
p = "*a*b"
输出: true
解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".

。
*/
#include<stdio.h>
#include<stdbool.h>

bool Match(const char* pattern, const char* str) {
    //两个字符串同时结束返回true，否则返回false
    if (*pattern == '\0' && *str == '\0')
        return true;
    if (*pattern == '\0' || *str == '\0')
        return false;

    if (*pattern == '?') {
        // ? 匹配一个字符，直接跳过一个位置
        return Match(pattern + 1, str + 1);
    } else if (*pattern == '*') {
        // * 匹配0个字符，或者匹配一个字符，或者匹配大于一个字符，一个为真即为真
        return Match(pattern+1, str) || Match(pattern+1, str+1) || Match(pattern, str+1);
    } else if (*pattern == *str) {
        // 当前字符相等，匹配下一个字符
        return Match(pattern + 1, str + 1);
    }
    return false;
}

int main() {
    char pattern[1000];
    char str[1000];
    while (scanf("%s", pattern) != EOF) {
        scanf("%s", str);
        if (Match(pattern, str))
            printf("true\n");
        else
            printf("false\n");
    }
    return 0;
}
