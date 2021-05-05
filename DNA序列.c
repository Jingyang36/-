/*
一个DNA序列由A/C/G/T四个字母的排列组合组成。G和C的比例（定义为GC-Ratio）是序列中G和C两个字母的总的出现次数除以总的字母数目（也就是序列长度）。在基因工程中，这个比例非常重要。因为高的GC-Ratio可能是基因的起始点。

给定一个很长的DNA序列，以及要求的最小子序列长度，研究人员经常会需要在其中找出GC-Ratio最高的子序列。

本题含有多组样例输入。

输入描述:
输入一个string型基因序列，和int型子串的长度

输出描述:
找出GC比例最高的子串,如果有多个输出第一个的子串

输入

AACTGTGCACGACCTGA
5
输出

GCACG
*/

#include<stdio.h>
#include<string.h>
int n, i_max, j_max, count, sum;
double tmp, max;
char str[105];
int main() {
    while (scanf("%s", &str) != EOF) {
        scanf("%d", &n);

        //初始化需要的所有值
        i_max = 0, j_max = 0, max = 0, sum = 0;
        //求长度 
        int len = strlen(str);
        //第一层for循环控制子串的起始位置 
        for (int i = 0; i < len; i++) {
            //子串中的CG值先初始化为0 
            count = 0;
            //控制子串的结束位置 
            for (int j = i; j < len; j++) {
                //子串的长度 
                sum = j - i + 1;
                //该串中有C或者G,则计数加一 
                if (str[j] == 'C' || str[j] == 'G') {
                    count++;
                }
                //子串长度大于五才开始计算 
                if (sum == n) {
                    tmp = count * 1.0 / sum;
                    if (tmp > max) {
                        max = tmp;
                        i_max = i;
                        j_max = j;
                    }
                }
            }
        }
        for (int i = i_max; i <= j_max; i++) {
            printf("%c", str[i]);
        }
        printf("\n");
    }
    return 0;
}
