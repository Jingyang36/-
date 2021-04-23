/*****************
输入描述:
输入第一行为一个正整数n(1≤n≤1000),下面n行为n个字符串(字符串长度≤100),字符串中只含有大小写字母。
输出描述:
数据输出n行，输出结果为按照字典序排列的字符串。
输入
9
cap
to
cat
card
two
too
up
boat
boot
输出
boat
boot
cap
card
cat
to
too
two
up

*****************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char str[101];
} table_t;

int cmp( const void *a, const void *b )
{
    for( int i = 0; i < 101; i ++ )
    {
        if( ((table_t *)a)->str[i] > ((table_t *)b)->str[i] )
            return 1;
        if( ((table_t *)a)->str[i] < ((table_t *)b)->str[i] )
            return -1;
    }
    
    return 0;
}

int main( void )
{
    int num = 0;
    
    scanf( "%d", &num );
    
    table_t* table = (table_t*)malloc( num * sizeof( table_t ) );
    if( table == NULL )
        exit( 1 );
    
    for( int i = 0; i < num; i++ )
        scanf( "%s", table[i].str );
    
    /* 冒泡排序法 */
    table_t my_index = {0};
    for( int i = 0; i < num-1; i++ )
    {
        for( int j = 0; j < num-1-i; j++ )
        {
            if( strcmp( table[j].str, table[j+1].str ) > 0 )
            {
                strcpy( my_index.str, table[j].str );
                strcpy( table[j].str, table[j+1].str );
                strcpy( table[j+1].str, my_index.str );
           }
        }
    }
    
//    qsort( table, num, sizeof( table_t ), cmp ); //快速排序标准库函数
    
    for( int i = 0; i < num; i++ )
        printf( "%s\n", table[i].str );
    
    free( table );
    
    return 0;
    
}
