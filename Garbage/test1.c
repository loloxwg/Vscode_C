/* ��ѧģ�Ͳ��ա������ݽṹ�����в���   !!!ȡ������ʵ�ֶ���ѭ��!!! */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


#define OK 1 
#define ERROR 0
#define TURE 1
#define FALSE 0
#define MAXSIZE 6 /* �������ĳ�Ա���� ������ĳ��� */


typedef int Status;
typedef int QElemType;


/* ѭ�����е�˳��洢�ṹ */ /* �ṹ�� ���� ����һ���µ����ݽṹ */
typedef struct
{
QElemType data[MAXSIZE];
int front;/* ͷָ�� ָ��ǰԪ�� ��������һ�� ˵��ָ�룬��ʵ���������±� */
int rear; /* βָ�� ָ��Ԫ�ص���һ��λ�� ����������ڼ�������˼�Ǻ� */
}SqQueue;


/* ��ʼ��һ���յĶ��� */
Status InitQueue(SqQueue *Q)/* �ı� ���������� ������Ԫ�ص���ֵ ���β���ָ�� */
{
Q -> front = 0;
Q -> rear = 0;
return OK;
}


/* ��������� */
Status ClearQueue(SqQueue *Q)
{
Q -> front = 0;
Q -> rear = 0;
return OK;
}


/* �ж϶����Ƿ�Ϊ�� ���򷵻�Ture */
Status QueueEmpty(SqQueue Q)/* ���ı� ���������� ������Ԫ�ص���ֵ����copy�ö��У������Ԫ�ؽ����жϲ��� */
{
if(Q.front == Q.rear)
return TURE;
else 
return FALSE;
}


/* ���ض�����Ԫ�صĸ��� */
Status QueueLength(SqQueue Q)
{
return ( (Q.rear - Q.front + MAXSIZE) % MAXSIZE );
}


/* ���ض���Ԫ�� */
Status FrontQueue(SqQueue Q,QElemType *e)/* *e ���� ��ת����Ԫ�ص���ֵ */
{
if(Q.front == Q.rear)
return ERROR;
*e = Q.data[Q.front];/* ���� ��copy�ж϶���״̬ ������תor�ı����Ԫ��  ǰ���β������ṹ���� ����ָ��  */
return OK;
}


/* ���ض�βԪ�� */
Status RearQueue(SqQueue Q,QElemType *e)
{
if(Q.front == Q.rear)
return ERROR;
*e = Q.data[Q.rear-1];/* �����βԪ����a0 ��ôQ.rearʵ��ָ��a1 */
return OK;
}


/* ����δ�� ��β�������  ����һ��Ԫ�� ��βָ��+1 */
Status InsertQueue(SqQueue *Q,QElemType e)
{
if( (Q -> rear + 1) % MAXSIZE == Q -> front ) 
return ERROR;
Q -> data[Q -> rear] = e;
Q -> rear = (Q -> rear + 1) % MAXSIZE;/* ������������� ��ת��ͷ�� */
return OK;
}


/* ����δ�� ����ɾ������ ������ɾ�����Ǹ�Ԫ�ص���ֵ  ��������ƣ�ÿɾ��һ��������ָ��+1 */
Status DeleteQueue(SqQueue *Q,QElemType *e)
{
if( Q -> rear == Q -> front ) 
return ERROR;
*e = Q -> data[Q -> front];
Q -> front = (Q -> front + 1) % MAXSIZE;/* ������������� ��ת��ͷ�� */
return OK;
}


Status visit(QElemType c)
{
printf("%d ",c);
return OK;
}


/* ������������ ��ͷ��β���ÿһ��Ԫ�ص���ֵ */
Status TraverseQueue(SqQueue Q)
{
int j;
j = QueueEmpty(Q);
if( j == TURE)
printf("�ö���Ϊ�ն���\n");

int i = Q.front;
while(i != Q.rear)
{
visit(Q.data[i]);
i = (i+1) % MAXSIZE;
}
printf("\n");
return OK;
}


int main()
{
int a,b,Qlength;
SqQueue Q;
QElemType e,f;

/* ���г�ʼ�� */
a = InitQueue(&Q);
if(a == OK)
printf("���г�ʼ���ɹ�\n");
else 
return ERROR;
/* �ж϶����Ƿ�Ϊ�� */
a = QueueEmpty(Q);
if(a == TURE)
printf("����Ϊ��\n");
else
return ERROR;


/* ͨ�����빹���¶��� */
int i;
printf("��������������Ԫ�صĸ���:%d ���г���Ϊ:%d ������һ��Ԫ�ش�����Ϊ��\n",MAXSIZE-1,MAXSIZE);
for(i = 1;i <= (MAXSIZE - 1);i++)
{
e = i;
InsertQueue(&Q,e);
}  
/* �����¶��� */
TraverseQueue(Q);


/* ��ȡ���г��� */
Qlength = QueueLength(Q);
printf("���г���Ϊ:%d\n",Qlength);


/* ���ض���Ԫ�� */
a = FrontQueue(Q,&e);
if(a == OK)
printf("���ض���Ԫ�ز����ɹ�\n");
else
return ERROR;
printf("����Ԫ��:%d\n",e);


/* ���ض�βԪ�� */
a = RearQueue(Q,&e);
if(a == OK)
printf("���ض�βԪ�ز����ɹ�\n");
else
return ERROR;
printf("��βԪ��:%d\n",e);

printf("�Ƿ�ִ�н�������ɾ������?yes or no(yes ����1  no ����0)\n");
scanf("%d",&b);
switch(b)
{
case 0:break;
case 1:
/* ɾ�����׵�����Ԫ�� */
DeleteQueue(&Q,&e);
printf("��һ��ɾ���������صĶ���Ԫ��:%d\n",e);
DeleteQueue(&Q,&f);
printf("�ڶ���ɾ���������صĶ���Ԫ��:%d\n",f);
/* ������ʱ�Ķ��� */
TraverseQueue(Q);
break;
}

ClearQueue(&Q);
a = QueueEmpty(Q);
if(a == TURE)
printf("����Ϊ��\n");
else
return ERROR;

printf("\n ���Ѿ���ɶ��еĸ�ϰ :) \n");
return 0;
}
