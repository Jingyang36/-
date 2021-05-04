/*
任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对。
本题含有多组样例输入。

输入
复制
20
输出
复制
7
13
素数定义：指在大于1的自然数中，除了1和它本身以外不再有其他因数的自然数。
判断一个数n是否为素数通常有2种方式：
根据素数的定义，只需把  [2, n-1] 之间的每一个整数去除n，如果都不能被整除，那么 n 就是一个素数
把[2,√n]之间的每一个整数去除n，如果都不能被整数，那么n就是素数。因为如果一个数n不是素数，即[2,n-1]之间存在2个整数是它的因数，则其中一个必定小于等于√n。证明：反证法，假设存在2个整数a>√n和整数b>√n，使得n=a*b；因为a*b>（√n*√n)=n，与假设不符，则原命题正确。
因为法2的时间复杂度更小，因为可以用法2构造一个判断是否为素数的函数。
因为题目要求离输入最近的两个素数，则很自然的想到从输入的一半开始找。
*/

#include <stdio.h>
#include <math.h>
#include <limits.h>
 
int is_prime(int n){
    for(int i = 2; i <= sqrt(n); ++i){
        if(n % i == 0) return 0;
    }
    return 1;
}
int main(void){
    int n;
    while(scanf("%d", &n) == 1){
        int diff;
        int a, b;
        for(int i = sqrt(n); i <= n; ++i){ //一半开始
            if(is_prime(i) && is_prime(n-i)){
                diff = n-i - i;
                if(diff >= 0){
                 //   diff_m = diff;
                    a = i, b = n-i;
                }
                else break;
            }
        }
        printf("%d\n%d\n", a, b);
    }
    return 0;
}
