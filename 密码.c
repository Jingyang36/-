/*
他是这么变换的，大家都知道手机上的字母： 1--1， abc--2, def--3, ghi--4, jkl--5, mno--6, pqrs--7, tuv--8 wxyz--9, 0--0,就这么简单，渊子把密码中出现的小写字母都变成对应的数字，数字和其他的符号都不做变换，

 

声明：密码中没有空格，而密码中出现的大写字母则变成小写之后往后移一位，如：X，先变成小写，再往后移一位，不就是y了嘛，简单吧。记住，z往后移是a哦。
*/


#include <stdlib.h>
#include <stdio.h>

int main()
{
    char *str = (char *)malloc(sizeof(char) * 101);
    while(gets(str))
    {
        char *pstr = str;
        while(*pstr != '\0')
        {
            if(*pstr >= 'A' && *pstr <= 'Z')
            {
                if(*pstr == 'Z') *pstr = 'a';
                else *pstr = *pstr + 33;
            }
            else if(*pstr >= 'a' && *pstr <= 'z')
            {
                if(*pstr <= 'c')
                    *pstr = '2';
                else if(*pstr <= 'f')
                    *pstr = '3';
                else if(*pstr <= 'i')
                    *pstr = '4';
                else if(*pstr <= 'l')
                    *pstr = '5';
                else if(*pstr <= 'o')
                    *pstr = '6';
                else if(*pstr <= 's')
                    *pstr = '7';
                else if(*pstr <= 'v')
                    *pstr = '8';
                else
                    *pstr = '9';
            }
            pstr++;
        }
        printf("%s", str);
    }
    free(str);
    return 0;
}
