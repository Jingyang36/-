// 题目描述
// 输入整型数组和排序标识，对其元素按照升序或降序进行排序（一组测试用例可能会有多组数据）

// 本题有多组输入，请使用while(cin>>)处理

// 输入描述:
// 第一行输入数组元素个数
// 第二行输入待排序的数组，每个数用空格隔开
// 第三行输入一个整数0或1。0代表升序排序，1代表降序排序

// 输出描述:
// 输出排好序的数字

// 示例1
// 输入
// 复制
// 8
// 1 2 4 9 3 55 64 25
// 0
// 5
// 1 2 3 4 5
// 1
// 输出
// 复制
// 1 2 3 4 9 25 55 64
// 5 4 3 2 1

#include <stdio.h>

int main()
{
    //不重新赋值
    int n;
    int flag;
    while(scanf("%d",&n)!=EOF)
    {
        int num[n];
        int temp;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&num[i]);
        }
        scanf("%d",&flag);
        
        //冒泡
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = 0; j < n - 1 - i; j++)
            {
                if(flag?(num[j]<num[j+1]):(num[j]>num[j+1])) //降序 升序
                {
                    temp = num[j];
                    num[j] = num[j+1];
                    num[j+1] = temp;
                }
            }
        }
        for(int k = 0; k < n; k++){
            printf("%d ",num[k]);
        }
        printf("\n");
        
    }
    return 0;
}
