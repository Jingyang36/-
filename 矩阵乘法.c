/*
题目描述
如果A是个x行y列的矩阵，B是个y行z列的矩阵，把A和B相乘，其结果将是另一个x行z列的矩阵C。这个矩阵的每个元素是由下面的公式决定的

矩阵的大小不超过100*100
输入描述:
输入包含多组数据，每组数据包含：

第一行包含一个正整数x，代表第一个矩阵的行数

第二行包含一个正整数y，代表第一个矩阵的列数和第二个矩阵的行数

第三行包含一个正整数z，代表第二个矩阵的列数

之后x行，每行y个整数，代表第一个矩阵的值

之后y行，每行z个整数，代表第二个矩阵的值



输出描述:
对于每组输入数据，输出x行，每行z个整数，代表两个矩阵相乘的结果
*/

#include <stdio.h>
int main()
{
    int x, y, z, c, a[100][100], b[100][100];
    while(scanf("%d %d %d",&x,&y,&z)!=EOF)
    {
        //Axy
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        //Byz
        for(int i = 0; i < y; i++)
        {
            for (int j = 0; j < z; j++)
            {
                scanf("%d",&b[i][j]);
            }
        }
        //Cxz
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < z; j++)
            {
                c = 0;
                for (int k = 0; k < y; k++)
                {
                    c = c + a[i][k] * b[k][j];
                }
                printf("%d ",c);
            }
           printf("\n"); //每个数组
        }
    }
    return 0;
}
