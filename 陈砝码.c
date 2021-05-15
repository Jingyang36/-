/*
现有一组砝码，重量互不相等，分别为m1,m2,m3…mn；
每种砝码对应的数量为x1,x2,x3...xn。现在要用这些砝码去称物体的重量(放在同一侧)，问能称出多少种不同的重量。


注：

称重重量包括0

第一行：n --- 砝码数(范围[1,10])

第二行：m1 m2 m3 ... mn --- 每个砝码的重量(范围[1,2000])

第三行：x1 x2 x3 .... xn --- 每个砝码的数量(范围[1,6])
输出描述:
利用给定的砝码可以称出的不同的重量数

2
1 2
2 1
输出
复制
5
*/
//以第一个砝码为基础，在其基础上不断添加，如示例：
//砝码1的数量位2，则三种情况：0，1，2
//砝码2的数量位1，则两种情况：0，2
//3： 0+2 1+2 2+2
//在砝码3种的基础上，添加砝码2的两种情况，分别为：0，1，2；2，3，4；去掉重复情况，则为0，1，2，3，4
//去重
//类似于桶排序的思想

#include <stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i,j,k, max = 0, count = 0, m[n], x[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&m[i]);           
        }
        for(i = 0; i<n;i++)
        {
            scanf("%d",&x[i]);            
        }
        for(i = 0; i <n; i++)
        {
            max += m[i]*x[i];
        }
        
        int *array = (int *)malloc(sizeof(int)*(max+1));
        memset(array,0,sizeof(int)*(max+1));
        array[0] = 1;
        for(i = 0; i < n; i++)
            for(j=0;j<x[i];j++)
                for(k=max;k>=0;k--)
                    if(array[k]==1)
                        array[k+m[i]] = 1;
        for(i = 0; i <=max;i++)
            if(array[i]==1)
                count++;
        printf("%d\n",count);
    }
    return 0;
}
