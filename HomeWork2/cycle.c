#include "stdio.h"

#define QUEUE_MAX_NUM 5 


typedef struct{
    int queue[QUEUE_MAX_NUM];
    int front;
    int rear;
    int s;
}Queue_Type;

void InitQueue(Queue_Type *p);

void InQueue (Queue_Type *p, int m, int x);

int OutQueue (Queue_Type *p,int m);


int main()
{
	int i,x,flag;
	Queue_Type	p;
	while(1)
	{
		InitQueue(&p);
		printf("请输入缓存数据:\n");
		for(i=1;i<=QUEUE_MAX_NUM;i++)
		{
			scanf("%d",&x);
			InQueue (&p, i, x);
		}
		
		printf("\n缓存完成数据如下:\n\n");


		for(i=1;i<=QUEUE_MAX_NUM;i++)
		{
			flag = OutQueue (&p,i);
			printf("%d  ",flag);
		}
		printf("\n\n");
		
	}

return 0;

}


void InitQueue(Queue_Type *p)
{
       p->front = 0;
       p->rear  = 0;
       p->s = 0;
}

void InQueue (Queue_Type *p, int m, int x)
{
	    p->rear += 1;
	    if(p->rear == m+1) 
		p->rear = 1;
	    p->queue[p->rear - 1] = x;
	    p->s = 1;
}


int OutQueue (Queue_Type *p,int m)
{
        int y;
	    p->front  = p->front%m+1;
	    y = p->queue[p->front -1];
	    if(p->front == p->rear)
		p->s= 0;
	    return y;
     
}