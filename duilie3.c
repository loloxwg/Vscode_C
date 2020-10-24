#include "CirculeQueue.h"
#include <stdlib.h>

//队列初始化
void InitialQueue(PQUEUE Q,int QueueMaxsize)
{
	Q->front = Q->rear = 0;	//对头对尾指向同一个存储空间，置队空
	Q->pBase = (int *)malloc(QueueMaxsize * sizeof(QueueElementDataType));//动态申请队列存储空间（对已知队列长度的前提下，用循环队列）
}

//入队
bool Enqueue(PQUEUE Q, int val)  
{  
	if(FullQueue(Q))  
		return false;  
	else  
	{  
		Q->pBase[Q->rear]=val;  
		Q->rear=(Q->rear+1)%Q->QueueMaxsize; 

		return true;  
	}  
} 

//出队
bool Dequeue(PQUEUE Q, int *val)  
{  
	if(EmptyQueue(Q))  
	{  
		return false;  
	}  
	else  
	{  
		*val=Q->pBase[Q->front];  
		Q->front=(Q->front+1)%Q->QueueMaxsize;

		return true;  
	}  
}  

//队列判空
bool EmptyQueue(PQUEUE Q)  
{  
	if(Q->front==Q->rear)    //队空  
		return true;  
	else  
		return false;  
}  

//队列判满
bool FullQueue(PQUEUE Q)  
{  
	if(Q->front==(Q->rear+1)%Q->QueueMaxsize)    //队满，留一个预留空间不用  
		return true;  
	else  
		return false;  
}  


void InitialQueue2(PQUEUE2 Q,int QueueMaxsize)
{
	Q->front = Q->rear;	//对头对尾指向同一个存储空间，置队空
	Q->pBase = (int *)malloc(QueueMaxsize * sizeof(QueueElementDataType));//动态申请队列存储空间（对已知队列长度的前提下，用循环队列）
}

bool EmptyQueue2(PQUEUE2 Q)
{
	if(Q->nCount == 0)	//队空 
		return true;
	else
		return false;
}

bool FullQueue2(PQUEUE2 Q)
{
	if(Q->nCount == Q->QueueMaxsize) //队满
		return true;
	else
		return false;
}

bool Enqueue2(PQUEUE2 Q, int val)
{
	if(EmptyQueue2(Q))  
	{  
		return false;  
	}  
	else  
	{  
		Q->pBase[Q->rear] = val; //新元素插入队尾  每当插入新的队列尾元素时，“尾指针增1”
		Q->rear = (Q->rear + 1)%Q->QueueMaxsize;//队尾指针指向下一个元素
		Q->nCount++; //队列元素个数加1

		return true;  
	} 
}
bool Dequeue2(PQUEUE2 Q, int *val)
{
	if (FullQueue2(Q))
	{
		return false;
	} 
	else
	{
		*val = Q->front;
		Q->front = (Q->front + 1)%Q->QueueMaxsize;//每当删除队列头元素时，“头指针增1”
		Q->nCount--; //队列元素个数减1

		return true;
	}
}

int main()
{
	QUEUE Q;
	Q.QueueMaxsize = 100;//队列长度

	InitialQueue(&Q,100);//初始化队列

	for(int i = 0;i< Q.QueueMaxsize -2;i++)//空一个存储空间
	{
		Enqueue(&Q,i);
	}

	for(int i = 0;i< Q.QueueMaxsize -2;i++)
	{
		Dequeue(&Q,&i);
	}

	//

	QUEUE2 Q2;
	Q2.QueueMaxsize = 100;//队列长度

	InitialQueue2(&Q2,Q2.QueueMaxsize);//初始化队列

	for(int i = 0;i< Q2.QueueMaxsize -1;i++)//装满所有存储空间
	{
		Enqueue2(&Q2,i);
	}

	for(int i = 0;i< Q2.QueueMaxsize -1;i++)
	{
		Dequeue2(&Q2,&i);
	}
	

	return 0;
}