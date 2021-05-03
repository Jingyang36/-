/*
输入一个单向链表和一个节点的值，从单向链表中删除等于该值的节点，删除后如果链表中无节点则返回空指针。

链表的值不能重复。

构造过程，例如输入一行数据为:
6 2 1 2 3 2 5 1 4 5 7 2 2
则第一个参数6表示输入总共6个节点，第二个参数2表示头节点值为2，剩下的2个一组表示第2个节点值后面插入第1个节点值，
为以下表示:
1 2 表示为
2->1
链表为2->1

3 2表示为
2->3
链表为2->3->1

5 1表示为
1->5
链表为2->3->1->5

4 5表示为
5->4
链表为2->3->1->5->4

7 2表示为
2->7
链表为2->7->3->1->5->4

最后的链表的顺序为 2 7 3 1 5 4

最后一个参数为2，表示要删掉节点为2的值
删除 结点 2

则结果为 7 3 1 5 4

链表长度不大于1000，每个节点的值不大于10000。
测试用例保证输入合法

/////////////
5 2 3 2 4 3 5 2 1 4 3  
2 5 4 1

形成的链表为2->5->3->4->1
删掉节点3，返回的就是2->5->4->1
*/

#include <stdio.h>
#include <stdlib.h>

//定义节点
typedef struct Node{
    struct Node *next;
    int value;
}node;

int main()
{
    node *head = NULL, *p = NULL, *ppre = NULL, *node1;
    int delvalue = 0, nodenum = 0, temp = 0, i = 0;
    
    while (scanf("%d",&nodenum) != EOF)
    {
        head = (node *)malloc(sizeof(node)); //分配内存
        scanf("%d",&(head->value)); //节点值
        head->next = NULL; //开始
        p = head;
        for(i = 0; i < nodenum - 1; i++){ //减1
            node1 = (node *)malloc(sizeof(node));
            scanf("%d %d",&(node1->value),&temp);//node1->vale 是temp值后一个1 2 表示为2->1
            while(p->value != temp){
                p = p->next;
            }
            //将node1 插入p节点后
            node1->next = p->next;
            p->next = node1;
            //p回到head
            p = head;
        }
        p = (node *)malloc(sizeof(node));
        scanf("%d",&delvalue);//delete value
        p = head;
        ppre = head;
        while(p)
        {
            if(p->value == delvalue) //删除的节点
            {
                ppre->next = p->next;
                free(p);
            }
            ppre = p;
            p = p->next; //缩进一位
        }
        p = head;
        if(head == NULL)
            printf("NULL");
        else{
            do{
                printf("%d ",p->value);
                p = p->next;
            }while(p);
        }
        printf("\n");
        
    }
    return 0;
}
