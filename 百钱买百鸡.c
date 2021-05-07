/*
公元前五世纪，我国古代数学家张丘建在《算经》一书中提出了“百鸡问题”
：鸡翁一值钱五，鸡母一值钱三，鸡雏三值钱一。百钱买百鸡，问鸡翁、鸡母、鸡雏各几何？
x y z

x + y + z = 100
5x+3y+z/3 = 100
15x+9y+z=300
14x+8y=200
y=
*/

#include <stdio.h>
//鸡公最多20
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int x = 0; x <= 20; x ++)
        {
            double y = (200 - 14*x)/8.0;
            double z = 100 - y - x;
            
            //解方程
            if(y == (int)y && y>=0 && z>=0)
                printf("%d %d %d\n",x,(int)y,(int)z);
        }
    }
    return 0;
}
