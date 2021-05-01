/*
假设一个球从任意高度自由落下，每次落地后反跳回原高度的一半; 
再落下, 求它在第5次落地时，共经历多少米?第5次反弹多高？

最后的误差判断是小数点6位

输入起始高度，int型 :1 
分别输出第5次落地时，共经过多少米第5次反弹多高: 2.875 
0.03125


*/

#include <stdio.h>


int main()
{
    int Hight;
    int Times = 5;
    double Total, FinalHight;
    
    while(scanf("%d",&Hight)!=EOF)
    {
        Total = FinalHight = Hight;
        
        for (int i = 1; i < Times; i++)
        {
            FinalHight /= 2;
            Total += FinalHight * 2;
            
        }
        printf("%g\n",Total);
        printf("%g\n",FinalHight/2);
    }
    return 0;
}
