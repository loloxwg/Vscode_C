//实现单链表的逆置，不利用额外空间
#include <stdio.h>
#include <stdlib.h>	
typedef int Status;
#define	OK			1//宏定义，就是定义ok=1，当后面调用ok的时候,就相当于1；
#define	ERROR		0	
#define	OVERFLOW	-2
typedef int LElemType_L;
typedef struct LNode
{
	LElemType_L data;//数据元素的类型定义
	struct LNode* next;
}LNode;
typedef LNode* LinkList;

Status InitList_L(LinkList *L);
Status ListTraverse_L(LinkList L, void(Visit)(LElemType_L));
LinkList reverse (LinkList L);
void PrintElem(LElemType_L e);
Status ListInsert_L(LinkList L, int i, LElemType_L e);

Status ListInsert_L(LinkList L, int i, LElemType_L e)
{
	LinkList p, s;
	int j;
	
	p = L;
	j = 0; 
	
	while(p && j<i-1)					//寻找第i-1个结点 
	{
		p = p->next;
		++j;
	}
	
	if(!p || j>i-1)
		return ERROR;

	s = (LinkList)malloc(sizeof(LNode));
	if(!s)
		exit(OVERFLOW);
	s->data = e;
	s->next = p->next;
	p->next = s;

	return OK;
}


Status ListTraverse_L(LinkList L, void(Visit)(LElemType_L))
{
	LinkList p;

	if(!L)
		return ERROR;
	else
		p = L->next;	

	while(p)
	{
		Visit(p->data);
		p = p->next;
	}

	return OK;
}

LinkList reverse (LinkList L)
{
	LNode *p,*r;
    p=L->next; //从第一个元素结点开始
    L->next=NULL;//先将头结点L的next域置为NULL
    while(p!=NULL)//依次将元素结点摘下
	{
		r=p->next;//暂存p的后继
		p->next=L->next;//将p结点插入到头结点之后
		L->next=p;
		p=r;
	}
	return L;
}

void PrintElem(LElemType_L e)
{
	printf("%d ",e);
}

Status InitList_L(LinkList *L)
{
	(*L) = (LinkList)malloc(sizeof(LNode));
	if(!(*L))
		exit(OVERFLOW);
	(*L)->next = NULL;
	
	return OK;
}
int main(int argc,char *argv[])
{
	LinkList L;
	int i;
	
	if(InitList_L(&L))
	{
		for(i=1;i<=10;i++)
			ListInsert_L(L,i,i);
	}
	
	printf("L=");
	ListTraverse_L(L,PrintElem);
	printf("\n\n");
	
	printf("逆置单链表...\n");
	L=reverse(L);
	printf("此时L=");
	ListTraverse_L(L,PrintElem);
	printf("\n\n");
	
	return 0;
}