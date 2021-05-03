/*
 字符串 数学 栈
 
 输入一个表达式（用字符串表示），求这个表达式的值。
保证字符串中的有效字符包括[‘0’-‘9’],‘+’,‘-’, ‘*’,‘/’ ,‘(’， ‘)’,‘[’, ‘]’,‘{’ ,‘}’。且表达式一定合法。

3+2*{1+2*[-4/(8-6)+7]}
25

//用栈的方法来计算；
//碰到括号可以递归调用；
 
//分析：
//1.先编写没有括号的表达式计算；
//    先编写简单的计算：比如-35+6*3-2*6；
//    相当于0-35+6*3-2*6；
//    用栈来存储最后可以相加的数 来得到结果；
//    自己想法是每个操作数都入栈，再计算；
//        这样不好，可以在碰到乘除时，在已经入栈的数上，直接计算修改，这样才方便；
//2.分析括号的情况；
//    碰到括号直接递归调用就好；
//    注意括号的结尾处理的位置；
 
 
//注意点：
//1.获取操作数：注意多位的情况；
//2.自己的思考是，每个操作数都压栈，这样很麻烦；在的时候，直接在旧的数上改值就很方便了；
//3.递归调用时，不用传新的指针，因为用的是全局变量pos来计算已经处理的字符；
*/

#include <stdio.h>
#include <string.h>
//#include <ctype.h>

int pos = 0;

int count(char *data)
{
    int result = 0; 
    int num_top = 0; //操作数栈顶
    int num = 0; //操作数
    int stack_num[200]; //存放结果
    char flag = '+'; //flag初始值 +
    
    while(data[pos]!='\0')
    {
        if((data[pos] == '{')||(data[pos] == '[') || (data[pos] == '('))
        {
            //碰到括号 递归使用
            pos ++;
            num = count(data); //执行计算
        }
        while(isdigit(data[pos])) //获取操作数
        {
            num = num*10 + data[pos] - '0';
            pos++;
        }
        
        //运算符
        switch(flag)
        {
            case '+':
                stack_num[num_top++] = num;    break;
            case '-':
                stack_num[num_top++] = -num;    break;
            case '*': //乘除直接在旧数字
                stack_num[num_top-1] *= num;    break;
            case '/':
                stack_num[num_top-1] /= num;    break;
            default: break;
                
        }
        
        if((data[pos] == '}') || (data[pos] == ']') || (data[pos] == ')'))
        {//括号结尾 跳出循环
            pos++;
            break;
        }
        
        flag = data[pos]; //当前操作符
        num = 0;
        pos++;
    }
    for(int i = 0; i < num_top; i++)
    {
        result += stack_num[i];
    }
    return result;
}

int main(void)
{
    char data[200];
    int Result = 0;
    
    while(scanf("%s",data)!=EOF)
    {
        Result = count(data);
    }
    printf("%d",Result);
    
    return 0;
}
