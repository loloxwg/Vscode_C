//ʵ�ֵ���������ã������ö���ռ�
#include <stdio.h>
#include <stdlib.h>	
typedef int Status;
#define	OK			1//�궨�壬���Ƕ���ok=1�����������ok��ʱ��,���൱��1��
#define	ERROR		0	
#define	OVERFLOW	-2
typedef int LElemType_L;
typedef struct LNode
{
	LElemType_L data;//����Ԫ�ص����Ͷ���
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
	
	while(p && j<i-1)					//Ѱ�ҵ�i-1����� 
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
    p=L->next; //�ӵ�һ��Ԫ�ؽ�㿪ʼ
    L->next=NULL;//�Ƚ�ͷ���L��next����ΪNULL
    while(p!=NULL)//���ν�Ԫ�ؽ��ժ��
	{
		r=p->next;//�ݴ�p�ĺ��
		p->next=L->next;//��p�����뵽ͷ���֮��
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
	
	printf("���õ�����...\n");
	L=reverse(L);
	printf("��ʱL=");
	ListTraverse_L(L,PrintElem);
	printf("\n\n");
	
	return 0;
}