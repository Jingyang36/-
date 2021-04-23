/***************
输入
复制
5
输出
复制
2
*****************/

#include <stdio.h>
int main(void)
{
	int num;
	int count = 0;
	scanf("%d", &num);
	int length = sizeof(int) * 8;
	for (int i = 0; i < length - 1; i++)
	{
		if (num & 1)
			count++;
		num >>= 1;  //右边开始数
	}
	printf("%d\r\n", count);
	return 0;
}
