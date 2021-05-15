/*
题目描述
问题描述：数独（Sudoku）是一款大众喜爱的数字逻辑游戏。玩家需要根据9X9盘面上的已知数字，推算出所有剩余空格的数字，并且满足每一行、每一列、每一个粗线宫内的数字均含1-9，并且不重复。
输入：
包含已知数字的9X9盘面数组[空缺位以数字0表示]
输出：
完整的9X9盘面数组

输入描述:
包含已知数字的9X9盘面数组[空缺位以数字0表示]

输出描述:
完整的9X9盘面数组

示例1
输入
复制
0 9 2 4 8 1 7 6 3
4 1 3 7 6 2 9 8 5
8 6 7 3 5 9 4 1 2
6 2 4 1 9 5 3 7 8
7 5 9 8 4 3 1 2 6
1 3 8 6 2 7 5 9 4
2 7 1 5 3 8 6 4 9
3 8 6 9 1 4 2 5 7
0 4 5 2 7 6 8 3 1
输出
复制
5 9 2 4 8 1 7 6 3
4 1 3 7 6 2 9 8 5
8 6 7 3 5 9 4 1 2
6 2 4 1 9 5 3 7 8
7 5 9 8 4 3 1 2 6
1 3 8 6 2 7 5 9 4
2 7 1 5 3 8 6 4 9
3 8 6 9 1 4 2 5 7
9 4 5 2 7 6 8 3 1


DFS 回溯
*/


#include <stdio.h>  
#include <stdbool.h>

bool sign = false;    
int num[9][9]; 
     
void Output() 
{   
    for (int i = 0; i < 9; i++){ 
        for (int j = 0; j < 8; j++) 
            printf("%d ",num[i][j]); 
         printf("%d ",num[i][8]); 
        printf("\n"); 
    } 
}
 
/* 判断key填入n格时是否满足条件,n代表第几个格子 */ 
bool Check(int n, int key) 
{ 
    /* 判断n所在横列是否合法 */ 
    for (int i = 0; i < 9; i++){ 
        /* j为n竖坐标 */ 
        int j = n / 9; 
        if (num[j][i] == key)
            return false; 
    } 
    
    /* 判断n所在竖列是否合法 */ 
    for (int i = 0; i < 9; i++){ 
        /* j为n横坐标 */ 
        int j = n % 9; 
        if (num[i][j] == key)
            return false; 
    } 
    
    int y = n / 9 / 3 * 3; 
    int x = n % 9 / 3 * 3;     
    /* 判断n所在的小九宫格是否合法 */ 
    for (int i = y; i < y + 3; i++)  
        for (int j = x; j < x + 3; j++) 
            if (num[i][j] == key)
                return false; 

    return true; 
} 
 
/* 深搜 */ 
int DFS(int n) 
{ 
    /* 所有的都符合，退出搜索,n代表格子数，共81个格子，0~80 */ 
    if (n > 80){ 
        sign = true; 
        return 0; 
    } 

    if (num[n / 9][n % 9] != 0) 
        DFS(n + 1);  
    else{ 
        /* 否则对当前位一次填入1~9进行测试 */ 
        for (int i = 1; i <= 9; i++){ 
            if (Check(n, i)){ 
                num[n / 9][n % 9] = i; 
                /* 继续搜索，后续位也填1~9测试，直到最后一位，通过的话置true */ 
                DFS(n + 1); 
                /* 返回时如果构造成功，则直接退出 */ 
                if (sign)  
                    return 0; 
                /* 如果构造不成功，还原当前位 */ 
                num[n/9][n%9] = 0;
            }
                  
        } 
    }
    return 0;
} 
      
int main() 
{  
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++)
            scanf("%d ",&num[i][j]); 
    }
    DFS(0);     //从第0格开始填 
    Output(); 
}
