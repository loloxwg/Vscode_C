//实现单链表的逆置，不利用额外空间
#include <stdio.h>
#include <stdlib.h>	
typedef int Status;
#define	OK			1	//宏定义，bai就是定义ok=1，当后面du调用ok的时候，ok就相当于1；
#define	ERROR		0	
#define	OVERFLOW	-2
typedef int LElemType_L;//typedef 类型定义标识符，
typedef struct LNode	//将typedef和结构体的定义和结构体指针的定义连在一起写
{
	LElemType_L data;	//数据元素的类型定义
	struct LNode* next; //指向下一个结构体变量的指针，通常用于链表
}LNode;
typedef LNode* LinkList;//结构体定义  

Status InitList_L(LinkList *L);	//函数原型，函数返回一个 int类型的值
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
		p = p->next;	//表示修改指针p的位置，把p指向原来的下一个节点
		++j;			//将j自增一次
	}
	
	if(!p || j>i-1)		//如果j大于i-1则为真,否则为假
		return ERROR;	//终止当前函数，并返回ERROR

	s = (LinkList)malloc(sizeof(LNode));	//sizeof函数计算数据（包括数组、变量、类型、结构体等）所占内存空间，用字节数表示。
    //malloc函数用于在内存开辟了一段地址，而这段地址的首地址存在返回的那个指针变量里
	if(!s)	//s为假，输出0
		exit(OVERFLOW);	//退出函数
	s->data = e;	//将 e 赋值给  结构体s下的data
	s->next = p->next;	// 把p的一下个节点赋值给s的下一个节点上,
	p->next = s;	//把s接到p的下一个节点上

	return OK;	//函数执行到return即结束。
}


Status ListTraverse_L(LinkList L, void(Visit)(LElemType_L))	//
{
	LinkList p;	//创建一个linklist类型的实例

	if(!L)	
		return ERROR;	//则终止当前函数，并返回ERROR
	else
		p = L->next;	//让p = 头结点的后一个节点	

	while(p)	//当p不为空的是指执行后续语句
	{
		Visit(p->data);
		p = p->next;	//修改指针p的位置，把p指向原来的下一个节点。
	}

	return OK;	//函数执行到return即结束。
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
		L->next=p;	//生成一个新的节点,并将其插入到数据链中
		p=r;
	}
	return L;
}

void PrintElem(LElemType_L e)	
{
	printf("%d ",e);	
}

Status InitList_L(LinkList *L)	//函数返回一个 int类型的值
{
	(*L) = (LinkList)malloc(sizeof(LNode));		//申请一个空间
	if(!(*L))
		exit(OVERFLOW);	//直接exit退出 
	(*L)->next = NULL;	//带头节点时等于把链表置空，不带等于在L表中，除第一个元素外删除其他元素
	
	return OK;
}
int main(int argc,char *argv[])	//int 表明函数的返回值类型int arg 和 char *argv[] 是函数的参数。
{
	LinkList L;	//值传递,传的是L的一个副本 ,对副本操作后无法起到修改链表的效果 
	int i;	//定义一个int型变量i
	
	if(InitList_L(&L))	//生成一个1-10的单链表
	{
		for(i=1;i<=10;i++)	//指定次数循环,从i等于1开始每循环一次i的值加1,当i的值不再小于等于10时停止循环
			ListInsert_L(L,i,i);	//向列表第i个位置插入元素i
	}
	
	printf("L=");	//打印L=
	ListTraverse_L(L,PrintElem);
	printf("\n\n");	//换行
	
	printf("逆置单链表...\n");	//输出打印逆单链表
	L=reverse(L);
	printf("此时L=");
	ListTraverse_L(L,PrintElem);
	printf("\n\n");
	
	return 0;	//程序正常退出
}c++c++