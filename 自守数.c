/*
题目描述
自守数是指一个数的平方的尾数等于该数自身的自然数。例如：25^2 = 625，76^2 = 5776，9376^2 = 87909376。请求出n以内的自守数的个数


接口说明


/*
功能: 求出n以内的自守数的个数


输入参数：
int n

返回值：
n以内自守数的数量。

输入描述:
int型整数

输出描述:
n以内自守数的数量。

示例1
输入
复制
2000
输出
复制
8
*/

#include <stdio.h>
#include <math.h>

int main()
{
    long long n;
    while(scanf("%lld",&n)!=EOF)
    {
        int count = 0;
        for(int i = 0; i <= n; i++)
        {
            long long t1 = pow(i, 2);
            long long t2 = i;
            while(t2)
            {
                if(t1%10!=t2%10)
                {
                    break;//最后一位不同
                }
                t1 = t1/10;
                t2 = t2/10; //枚举
            }
            if(t2 == 0)
            {
                count ++;
            }
            
        }
        printf("%d\n",count);
    }
    return 0;
}
