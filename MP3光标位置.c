#include <stdio.h>
#include <string.h>

void Short(char *str, int n)
{
    int current = 1;
    int len = strlen(str);
    for(int i = 0; i < len; i++)
    {
        if(str[i] == 'U')
        {
            if(current == 1)
                current = n;
            else
                current --;
        }
        else if(str[i] == 'D')
        {
            if(current == n)
                current = 1;
            else 
                current ++;
        }
    }
    for (int i = 1; i < n; i++)
    {
        printf("%d ",i);
    }
    printf("%d\n",n);
    printf("%d\n",current);
    
}

void Long(char *str, int n)
{
    int initial = 1, current = 1;//initial :最开头
    int len = strlen(str);
    for(int i = 0; i < len; i++)
    {
        if(str[i] == 'U')
        {
            if(initial == 1 && current == 1)
            {
                current = n;//直接最后
                initial = n - 3;//4页
            }
            else if (initial == current)//一般在顶
            {
                current --;
                initial --;
            }
            else//不在顶
                current --;
        }
        else if(str[i] == 'D')
        {
            if(current == n && initial == n - 3) //特殊
            {
                current = 1;
                initial = 1;
            }
            else if(initial == current - 3)
            {
                current ++;
                initial ++;                
            }
            else
                current ++;
        }
    }
    for (int i = initial ; i !=initial + 3; i++)
    {
        printf("%d ",i);
    }
    printf("%d\n",initial + 3);
    printf("%d\n",current);
    
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        char str[100];
        scanf("%s",str);
        if(n<=4)
        {
            Short(&str, n);
        }
        else
        {
            Long(&str,n);
        }
    }
    
    
    return 0;
}
