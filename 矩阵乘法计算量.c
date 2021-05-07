/*
题目描述
矩阵乘法的运算量与矩阵乘法的顺序强相关。
例如：

A是一个50×10的矩阵，B是10×20的矩阵，C是20×5的矩阵

计算A*B*C有两种顺序：（（AB）C）或者（A（BC）），前者需要计算15000次乘法，后者只需要3500次。


编写程序计算不同的计算顺序需要进行的乘法次数。

本题含有多组样例输入！



输入描述:
输入多行，先输入要计算乘法的矩阵个数n，每个矩阵的行数，列数，总共2n的数，最后输入要计算的法则
计算的法则为一个字符串，仅由左右括号和大写字母（'A'~'Z'）组成，保证括号是匹配的且输入合法！

输出描述:
输出需要进行的乘法次数

示例1
输入
复制
3
50 10
10 20
20 5
(A(BC))
输出
复制
3500

字符串 括号出入栈
*/

// #include<stdio.h>
// int a[20],b[20];            //分别存每组行列
// int pos;                //指向字符串当前位置
// int top;                //指向最新参与计算的一组行列
// int calcu(char s[]){                 //计算括号内的全部
//     int num=0,len=strlen(s),row=0,col=0;     //row，col存入完成连乘后的行列，其实每次只会改变列值
//     while(pos<len&&s[pos]!=')'){
//         if(s[pos]=='('){       //遇到正括号，再次调用calcu
//             pos++;
//             num+=calcu(s);
//         }
//         else top++;            //遇到字符，top后移指向当前要参与计算的行列
//         if(row){              //已有行列值，可计算
//             num+=row*col*b[top];    //top指向最新行列，出括号后也恰好指向括号内最后一个行列，只需用到其列值
//             col=b[top];         //更新连乘后新矩阵的列，行不变只会是该括号内数据的第一个行
//         }
//         else{                 //该括号内还一组行列都没处理
//             row=a[top];
//             col=b[top];
//         }
//         pos++;
//     }
//     return num;   //返回该括号内计算值，或字符串遍历完成返回最终计算值
// }
// int main(int argc,char *argv[]){
//     int n;
//     while(scanf("%d",&n)!=EOF){
//         top=-1;
//         for(int i=0;i<n;i++)
//             scanf("%d%d",&a[i],&b[i]);
//         char str[40];
//         scanf("%s",str);
//         pos=0;
//         printf("%d\n",calcu(str));
//     }
//     return 0;
// }

#include <stdio.h>
#include <string.h>
#define MAXSIZE 500

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int i, j = 0, res = 0;
        int row[MAXSIZE] = {0}, col[MAXSIZE] = {0};
        char type[MAXSIZE] = {'\0'}, temp[MAXSIZE] = {'\0'};
        for(i=0; i<n; i++)
            scanf("%d%d", &row[i], &col[i]);
        scanf("%s", type);
        for(i=0; i<strlen(type); i++){
            if(type[i] == '(')
                continue;
            else
                temp[j++] = type[i];
        }
        for(i=0; i<strlen(temp); i++){
            if(temp[i] == ')'){
                res += row[temp[i-2]-'A'] * col[temp[i-2]-'A'] * col[temp[i-1]-'A'];
                col[temp[i-2]-'A'] = col[temp[i-1]-'A'];
                strcpy(&temp[i-1], &temp[i+1]);
                i -= 2;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
