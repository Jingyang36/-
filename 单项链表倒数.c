/*
输入一个单向链表，输出该链表中倒数第k个结点，链表的倒数第1个结点为链表的尾指针。

链表结点定义如下：

struct ListNode

{

int       m_nKey;

ListNode* m_pNext;

};



正常返回倒数第k个结点指针，异常返回空指针

本题有多组样例输入。


输入描述:
输入说明
1 输入链表结点个数
2 输入链表的值
3 输入k的值

输出描述:
输出一个整数

示例1
输入
复制
8
1 2 3 4 5 6 7 8
4
输出
复制
5
*/

#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int n = 0;
    while(scanf("%d", &n) != EOF)
    {
        int a[1000] = {0};
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        int index = 0;
        scanf("%d", &index);
        printf("%d\n", a[n-index]);
    }
    return 0;
}

// #include <stdio.h>
// typedef struct list{
//     int val;
//     struct list* next;
// };

// int main()
// {
//     int num;
//     struct list* head = NULL;
//     while(scanf("%d",&num)!=EOF)
//     {
//         for(int i = 0; i < num; i++)
//         {
//             struct list* p = malloc(sizeof(struct list));
//             scanf("%d",&(p->val)); //list 值
//             if(head == NULL)
//             {
//                 head = p;
//                 p->next = NULL;
//             }
//             else{
//                 p->next = head;
//                 head = p; //反
//             }
//         }    
//         int k;
//         scanf("%d",&k);
//         if(k==0)
//             printf("%d\n",0);
//         else
//         {
//             struct list* key = head;
//             for(int i = 0; i < k-1;i++)
//             {
//                 key = key->next;
//             }
//             printf("%d\n",key->val);
//         }
//     }
//     return 0;
// }

