/*
蛇形矩阵是由1开始的自然数依次排列成的一个矩阵上三角形。

例如，当输入5时，应该输出的三角形为：

1 3 6 10 15

2 5 9 14

4 8 13

7 12

11
规律：行递减 列递增
*/

#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100
int main()
{
    int N;
    
    while(scanf("%d",&N)!= EOF)
    {
        int num = 1;
        int a[MAX_SIZE][MAX_SIZE] = { 0 };
        //外循环递增，内循环递减，二维数组下边之和一定
        for(int j = 0; j < N; j++) //外循环控制a[m][n]中n从0递增
            for (int i = j; i>=0; i--)//内循环m+n=q定值，[2][0] [1][1]
                a[i][j-i] = num++;//i递减，j-i递增
        for (int i = 0; i<N;i++)
        {
            for (int j = 0; j < N - i; j++)
            {
                printf("%d ",a[i][j]); //空格
            }
            printf("\n");
        }
    }
    return 0;
}
