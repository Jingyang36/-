//C代码
// strtok 分隔字符串 定位
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdbool.h"
 
#define MAX_STRINGLEN 1000
#define MAXLENGTH 3
#define MINLENGTH 2
 
typedef struct Point_ {
    int x;
    int y;
} Point;
 
//是否是合法输入
bool IsValid(char *s) {
    int sLength = strlen(s);
    if (sLength > MAXLENGTH || sLength < MINLENGTH) {
        return false;
    }
    if (s[0] != 'A' && s[0] != 'S' && s[0] != 'W' && s[0] != 'D') {
        return false;
    }
    for (int i = 1; i < sLength; i++) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return true;
}
 
//移动坐标
void MovePoint(Point *point, char *s) {
    int instance = atoi(s + 1);
    if (s[0] == 'A') {
        point->x -= instance;
    } else if (s[0] == 'S') {
        point->y -= instance;
    } else if (s[0] == 'W') {
        point->y += instance;
    } else {
        point->x += instance;
    }
}
 
int main()
{
    Point point = {0,0};
    char *p = (char *)malloc(MAX_STRINGLEN * sizeof(char));
    while (gets(p) != NULL) {
        char *temp = strtok(p, ";"); //temp: A10   W12
        while (temp) {
            if (IsValid(temp)) {
                MovePoint(&point, temp);
            }
            temp = strtok(NULL, ";"); //A10;W12分开
        }
        printf("%d,%d", point.x, point.y);
    }
    return 0;
}
