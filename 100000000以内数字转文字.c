/*
说明：

数字为正整数，长度不超过九位，不考虑小数，转化结果为英文小写；

输出格式为twenty two；

非法数据请返回“error”；

关键字提示：and，billion，million，thousand，hundred。


输入描述:
输入一个long型整数

输出描述:
输出相应的英文写法

示例1
输入
复制
2356
输出
复制
two thousand three hundred and fifty six

递归
*/

#include <stdio.h>
#include <string.h>

const char *dgt[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "forteen", "fifteen",
    "sixteen", "seventeen", "eighteen", "nineteen"
    };
const char *dgt1[] = {"", "", "twenty", "thirty", "forty", "fifty",
                      "sixty", "seventy", "eighty", "ninety"};

void English(long n)
{
    if(n<20) printf("%s ", dgt[n]);
    else if(n<100){
        if(n%10){
            printf("%s ",dgt1[n/10]);
            English(n%10);//下一个数
        }//整除10
        else printf("%s ",dgt1[n/10]);
    }
    else if (n < 1000){
        if(n % 100){
            printf("%s hundred and ",dgt[n/100]);
            English(n%100);
        }
        else printf("%s ",dgt1[n/100]);
    }
    else if (n < 1000000){
        English(n / 1000);
        printf("thousand ");//分离
        English(n % 1000);
    }
    else if(n < 100000000){
        English(n / 1000000);
        printf("million ");
        English(n % 1000000);
    }
}

int main()
{
    long int n;
    while(scanf("%ld",&n)!=EOF)
    {
        English(n);
        printf("\n");
    }
    return 0;
}
