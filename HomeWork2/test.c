#include "stdio.h"
#define QUEUE_MAX_NUM 5

typedef struct
{
	int queue[QUEUE_MAX_NUM];
	int front; //ͷָ��
	int rear;  //βָ�룬�����в��գ���ָ���βԪ����һλ
	int s;	   //��־
} Queue_Type;  //����ṹ��

void InitQueue(Queue_Type *p); // ��ʼ������

void InQueue(Queue_Type *p, int m, int x); //��Ӻ���

int OutQueue(Queue_Type *p, int m); //���Ӻ���

int main() //������
{
	int i, x, flag;
	Queue_Type p;
	while (1)//ʵ������������
	{
		InitQueue(&p);
		printf("�����뻺������:\n");
		for (i = 1; i <= QUEUE_MAX_NUM; i++)
		{
			scanf("%d", &x);
			InQueue(&p, i, x);
		}

		printf("\n���������������:\n\n");

		for (i = 1; i <= QUEUE_MAX_NUM; i++)
		{
			flag = OutQueue(&p, i);
			printf("%d  ", flag);
		}
		printf("\n\n");
	}
	return 0;
}


void InitQueue(Queue_Type *p)//��ʼ��һ���ն���
{
	p->front = 0;//ͷָ��Ϊ0
	p->rear = 0;//βָ��Ϊ0
	p->s = 0;//����һ��s��־����Ϊѭ�����ж����ӿյı�־
}

void InQueue(Queue_Type *p, int m, int x)
{
	p->rear += 1;			   //���βָ�����һλ��
	if (p->rear == m + 1)	   //�ж϶����Ƿ�Ϊ��������������βָ��ָ������Ԫ�ص���һλ
		p->rear = 1;		   //ת��ͷ��
	p->queue[p->rear - 1] = x; //ÿ�ε���Ӷ�Ԫ��x����Ԫ��x��ֵ����β
	p->s = 1;				   //s=1���������
}


//�ж϶�������ͷָ����ڵ���βָ��λ�ö�5ȡ������1

//���ͷָ�����βָ����
//��־λ��Ϊ0
int OutQueue(Queue_Type *p, int m)
{
	int y;
	p->front = p->front % m + 1;//βָ������ƶ�һ��λ��
	y = p->queue[p->front - 1];//��ͷԪ�ظ�ֵ��y
	if (p->front == p->rear)//���пյ��ж�
		p->s = 0;//s=0ʱ������п�
	return y;
}