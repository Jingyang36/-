/*********
输入

I am a boy
输出

boy a am I
*************/

#include <stdio.h>
#include <string.h>

int main( void )
{
    char str[1000];
    
    gets( str );
    
    char* sent_index = NULL;
    
    while( (sent_index = strrchr( str, ' ' )) != NULL ) //查找
    {
        *sent_index = '\0';
        printf( "%s ", sent_index + 1 );
        sent_index = NULL;
    }
    
    printf( "%s", str );
    
    return 0;
}

///////////////////////////////////////////////////
字符串反转
题目描述

小C很喜欢倒着写单词，现在给你一行小C写的文本，你能把每个单词都反转并输出它们吗？

输入

输入包含多组测试样例。第一行为一个整数T，代表测试样例的数量，后面跟着T个测试样例。
每个测试样例占一行，包含多个单词。一行最多有1000个字符。

输出

对于每一个测试样例，你应该输出转换后的文本。

样例输入

3
olleh !dlrow
I ekil .bulcmca
I evol .mca
样例输出

hello world!
I like acmclub.
I love acm.
【思路】：大循环中--当遇到空格或者结束的标志--直接令 k 为此时的(i-1)进行逆序输出----由于这样不会输出空格，则紧跟着逆序输出完成后，进行输出空格。
///////////////////////////////

#include<stdio.h>
#include<string.h>
int main()
{
  int N, len;
  int i,j,k;
  char a[1000];
  scanf("%d",&N);
  while (N>=0)
  {
    gets(a); //string
    len = strlen(a);
    
    j = 0;
    for (i = 0;i < len, i++)
    {
      if(a[i]==''||a[i]=='\0')
      {
        for(k = i-1;k>=j;k--)//当遇到是空格或者整个字符结束的时候，直接让k等于前一个数，逆序输出
          printf("%c",a[k]);
        if(a[i]!='\0')
          printf("");
        j = i; //记录遇见空格或者标点符号时，的i

      }  
    }
    printf("\n");
    N--;
  }
  return 0;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
}
