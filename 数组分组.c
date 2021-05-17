/*
题目描述
输入int型数组，询问该数组能否分成两组，使得两组中各元素加起来的和相等，并且，所有5的倍数必须在其中一个组中，所有3的倍数在另一个组中（不包括5的倍数），能满足以上条件，输出true；不满足时输出false。
本题含有多组样例输入。
输入描述:
第一行是数据个数，第二行是输入的数据

输出描述:
返回true或者false

示例1
输入
复制
4
1 5 -5 1
3
3 5 8
输出
复制
true
说明
第一个样例：
第一组：5 -5 1
第二组：1 
第二个样例：由于3和5不能放在同一组，所以不存在一种分法。
*/

//三个数组， sum1 sum2 sum3 一个 3， 5 倍数 剩下一组 递归加到两个

// //因为sum(a)和sum(b)有差，所以问题成为，如何将一个数组分成两部分，使得两部分的差为一定值。
// 则将数组c分成两部分，c1和c2使得（两部分和分别为sc1，sc2）：sa+sc1 = sb +sc2
// 所以sc1 - sc2 = sb - sa = cha（一个定值）
// 因为c1与c2所有元素和是sc：sc1 + sc2 = x + (x + cha) = sc ；即x = (sc - cha)/2。其实这里做的时候需要注意，sc-cha必须为偶数，如果不是偶数说明拆分不了两部分，直接本题答案就是false，各位可以仔细想想是不是这么回事。
// 最终问题是：从数组c中选若干元素，使得和为x，能找到返回true，否则false。
#include <stdio.h>
#include <math.h>

int main()
{
    int num;
    while(scanf("%d",&num)!=EOF)
    {
        int a[100];
        int i;
        for(i = 0; i< num; i++)
        {
            scanf("%d",&a[i]);
        }
        int sum1 = 0, sum2 = 0, sum3 = 0;
        for(i = 0; i < num; i++)
        {
            if(a[i] > 0 && a[i]%5 == 0)
            {
                sum1 += a[i];
            }
            else if(a[i] > 0 && a[i]%3 == 0)
            {
                sum2 += a[i];
            }
            else sum3 += abs(a[i]);
        }
        int aim = sum3 - abs(sum1 - sum2);
        if(aim > 0 && aim%2 == 0)
        {
            printf("true\n");
        }
        else
        {
            printf("false\n");
        }        
    }
    return 0;         
}
