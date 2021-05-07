/*
根据输入的日期，计算是这一年的第几天。。

测试用例有多组，注意循环输入

输入描述:
输入多行，每行空格分割，分别是年，月，日

输出描述:
成功:返回outDay输出计算后的第几天;
                                           失败:返回-1

示例1
输入
复制
2012 12 31
输出
复制
366
深色浅色56 ： 并不是所有能被4整除的年份就是闰年，当年份是100的倍数的时候需要能整除400才是闰年

*/

#include <stdio.h>

int isRun(int year)
{
    if((year % 4 == 0) && (year%100!=0)||(year%400==0))
        return 1;
    return 0;
}
int main()
{
    int year, month, day;
    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    while(scanf("%d %d %d",&year,&month,&day)!=EOF)
    {
        int sum = 0;
        for(int i = 0; i < month - 1; i++)
        {
            sum+=days[i];
        }
        sum+=day;
        if(month>2&&(isRun(year)))//此年闰年
            sum= sum+1;//多一天
        printf("%d\n",sum);
    }
    return 0;
}
