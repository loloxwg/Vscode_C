#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int DataType;   /*数据类型*/
typedef int ElemType;   /*元素类型*/

//----------------线性列表存储结构----------------
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

void ListCreate(LinkList L, int n)
//创建含有n个结点的链表
{
    int i;
    LinkList p, q;
    p = L;
    for(i = 0 ; i < n; i++)
    {
        q = (LNode *)malloc(sizeof(LNode));    //生成新结点
        scanf("%d", &q->data);
        q->next = NULL;

        p->next = q;                            //前后结点链接
        p = q;
    }
}

void ListReverse(LinkList L)
{
    LNode *p, *q;
    p = L->next;                 //p为原链表的当前处理节点
    L->next = NULL;              //逆置单链表初始为空

    while(p != NULL)
    {
        q = p->next;            //q指针保留原链表当前处理节点的下一个节点

        p->next = L->next;      //头插法
        L->next = p;
        p = q;
    }
}


void ListReverse2(LinkList L)
{
    LNode *real = L->next;          //带头结点的链表，real指向第一个实结点
    //real为NULL，则链表为只含头结点的空表
    //real->nexxt为NULL，则链表只含有一个结点
    if(real == NULL || real->next == NULL)          
        return;

    LNode *pre = real;              //先前指针
    LNode *cur = real->next;        //当前指针
    LNode *suc = NULL;              //后继指针

    while(cur != NULL)
    {
        suc = cur->next;
        cur->next = pre;

        pre = cur;
        cur = suc;
    }
    real->next = NULL;              //while执行后第一个结点和第二个结点互指

    L->next = pre;                  //记录新的头结点
}

//cur为第一个结点，L为头指针
// void ListReverse3(LNode *cur, LinkList L)
// {
//     //是空表或含有一个结点或者递归到边界
//     if(cur == NULL|| cur->next == NULL)
//     {
//         L->next = cur;
//     }
//     else
//     {
//         LNode *suc = cur->next;         //suc指针指向cur->next
//         ListReverse3(suc, L);
//         suc->next = cur;
//         cur->next = NULL;
//     }
// }
void ListTraverse(LinkList L)
{
    LNode* p = L;
    while(p->next)
    {
        p = p->next;
        printf("%d\n", p->data);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    LNode L;
    ListCreate(&L, n);
    ListReverse2(&L);
    ListTraverse(&L);

    return 0;
}
