/*
题目描述
输出7有关数字的个数，包括7的倍数，还有包含7的数字（如17，27，37...70，71，72，73...）的个数（一组测试用例里可能有多组数据，请注意处理）

输入描述:
一个正整数N。(N不大于30000)

输出描述:
不大于N的与7有关的数字个数，例如输入20，与7有关的数字包括7,14,17.

20

3
*/

#include<stdio.h>
 
int main(){
    int n = 0;
    while(scanf("%d", &n) != EOF){
        int res = 0;
        int tmp = 0;
        for(int i = 7; i <= n; i++){
            if(i%7 == 0)//7的倍数
                res ++;
            else{//包含7
                tmp = i;
                while(tmp > 0){
                    if(tmp%10 == 7){ //一个一个位数判断
                        res++;
                        break;
                    }else
                        tmp /= 10;
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
