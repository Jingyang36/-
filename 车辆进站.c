/*
题目描述
给定一个正整数N代表火车数量，0<N<10，接下来输入火车入站的序列，一共N辆火车，每辆火车以数字1-9编号，火车站只有一个方向进出，同时停靠在火车站的列车中，只有后进站的出站了，先进站的才能出站。
要求输出所有火车出站的方案，以字典序排序输出。
输入描述:
有多组测试用例，每一组第一行输入一个正整数N（0

输出描述:
输出以字典序从小到大排序的火车出站序列号，每个编号以空格隔开，每个输出序列换行，具体见sample。

示例1
输入
复制
3
1 2 3
输出
复制
1 2 3
1 3 2
2 1 3
2 3 1
3 2 1
说明
第一种方案：1进、1出、2进、2出、3进、3出
第二种方案：1进、1出、2进、3进、3出、2出
第三种方案：1进、2进、2出、1出、3进、3出
第四种方案：1进、2进、2出、3进、3出、1出
第五种方案：1进、2进、3进、3出、2出、1出
请注意，[3,1,2]这个序列是不可能实现的。 

栈 字典排序
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
int state1[10];         //存出站火车
int index1;
int state2[10];        //存站内火车
int index2;
int state3[10];       //存待进站火车
int index3;
char res[5000][10];
int resNum;
      
int CMP( const void *a, const void *b )
{
    return strcmp((char *)a, (char *)b);
//strcmp(str1,str2)，str1=str2，返回零；str1<str2，返回负数；str1>str2，返回正数。
}
void dfs()
{
    if( index1 == n ){           //出站任务完成
        int i;
        for( i = 0; i < index1; i++ )
        res[resNum][i] = state1[i] + '0';
        res[resNum][i] = '\0';
        resNum++;
        return;
    }
    if( index2 != -1 ){         //站内存在车辆
        state1[index1++] = state2[index2--];//当前车辆出站
        dfs();                                //输出当前车辆出站的结果
        state2[++index2] = state1[--index1]; //将上一次输出的出站车辆退到站内，让站内继续进车看下一次结果
    }
    if( index3 < n ){             //车辆未全部进站
        state2[++index2] = state3[index3];//车辆进站
        index3++;
        dfs();                     //输出当前车辆进站的结果
        index3--;                 //恢复现场
        index2--;
    }
}
int main()
{
    while( ~scanf("%d",&n ) ){
        index1 = 0;
        index2 = -1;
        index3 = 0;
        resNum = 0;
        int i,j;
        for( i = 0; i < n; i++ )
            scanf("%d",&state3[i]);
        dfs();
        qsort( res, resNum, sizeof(res[0]), CMP );
//qsort() 比较函数 res数组名，resNum数组个数，sizeof（）长度，CMP升序或降序函数；
//把输出结果按从小到大排
        for( i = 0; i < resNum; i++ ){
            for( j = 0; j < n; j++ )
                printf("%c ", res[i][j] );
            printf("\n");
        }
    }
    return 0;
}
