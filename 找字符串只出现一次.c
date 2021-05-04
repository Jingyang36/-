/*
题目描述
找出字符串中第一个只出现一次的字符

asdfasdfo
aabb

o
-1
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000] = {0};
    int length, count;
    while(scanf("%s",str)!=EOF)
    {
        length = strlen(str);
        for(int i = 0; i < length; i++)
        {
            count = 0;
            for (int j = 0; j < length; j++)
            {
                if (str[i] == str[j])
                {
                    count ++;
                }
            }
            if(count == 1)
            {
                printf("%c\n",str[i]);
                break;
            }
        }
        if(count!=1){
            printf("%d",-1);
        }
    }
    return 0;
}
