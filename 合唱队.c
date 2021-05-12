/*
题目描述
计算最少出列多少位同学，使得剩下的同学排成合唱队形

说明：

N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学排成合唱队形。
合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1，2…，K，他们的身高分别为T1，T2，…，TK，   则他们的身高满足存在i（1<=i<=K）使得T1<T2<......<Ti-1<Ti>Ti+1>......>TK。

你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。


注意不允许改变队列元素的先后顺序
请注意处理多组输入输出！

输入描述:
整数N

输出描述:
最少需要几位同学出列

示例1
输入
复制
8
186 186 150 200 160 130 197 200
输出


4
189 186 197 200

最长上升子序列
思路：
1、查找每一个数的左边的最大递增子字符串长度，放入数组incNum中。
2、查找每个数的右边最大递增子字符串长度，放入数组decNum中
3、两者相加，减去重复计算的1，即为将此数放中间组成合唱队所需要的人数，取最大值max
4、总人数减去第三步所得，就可以得出需要出列的最少人数
注意：身高是递增的，不能等于
*/

#include<stdio.h>

int main()
    {
    int n=0;
    while(scanf("%d",&n)!=EOF)
        {
        if(n<=0)
            printf("0\n");
        int tall[n];
        int left_queue[n];            //左排队
        int right_queue[n];           //右排队 
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tall[i]);
            left_queue[i]=1;
            right_queue[i]=1;
        }
            
        for(int i=0;i<n;i++)        
            {
            for(int j=0;j<i;j++)
                {
                if(tall[i]>tall[j]&&left_queue[j]+1>left_queue[i])  //一种分治思想，只要i比前面的高，最大长度就是前面那个最大长度+1
                    left_queue[i]=left_queue[j]+1;     
            }
        }
        for(int i=n-1;i>=0;i--)        
            {
            for(int j=n-1;j>i;j--)
                {
                if(tall[i]>tall[j]&&right_queue[j]+1>right_queue[i])
                    right_queue[i]=right_queue[j]+1;     
            }
        }

        int max=0;
        for(int i=0;i<n;i++)
            {
            if(left_queue[i]+right_queue[i]>max)
                max=left_queue[i]+right_queue[i];
        }
        printf("%d\n",n-max+1);             //中间点减了2次，最后需要+1
    }
}
