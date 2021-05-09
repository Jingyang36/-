/*
题目描述
现在IPV4下用一个32位无符号整数来表示，一般用点分方式来显示，点将IP地址分成4个部分，每个部分为8位，表示成一个无符号整数（因此不需要用正号出现），如10.137.17.1，是我们非常熟悉的IP地址，一个IP地址串中没有空格出现（因为要表示成一个32数字）。

现在需要你用程序来判断IP是否合法。

注意本题有多组样例输入。

输入描述:
输入一个ip地址，保证是xx.xx.xx.xx的形式（xx为整数）

输出描述:
返回判断的结果YES or NO

示例1
输入
复制
10.138.15.1
255.0.0.255
255.255.255.1000
输出
复制
YES
YES
NO

*/

#include <stdio.h>

int main(){
    int arr[4] = {0};
    while(scanf("%d.%d.%d.%d", &arr[0], &arr[1], &arr[2], &arr[3]) != EOF){
        int flag = 0;
        for(int i = 0; i < 4; i++){
            if((arr[i] >= 0) && (arr[i] <= 255)) flag++;
        }
        if(flag == 4) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
