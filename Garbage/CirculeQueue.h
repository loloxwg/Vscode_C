#ifndef __QUEUE_H_  
#define __QUEUE_H_  

typedef  int QueueElementDataType;



///
//利用空一个元素空间区分队空还是队满
//
typedef struct queue   
{  
	QueueElementDataType *pBase;	  //初始化的动态非配存储空间
	int front;    //队头指针，指向队首位置，删除一个元素就将front顺时针移动一位  
	int rear;    //队尾指针，指向队列最后一个元素的下一个元素，插入一个元素就将rear顺时针移动一位 
	int QueueMaxsize; //循环队列的最大存储空间  
}QUEUE,*PQUEUE;  

void InitialQueue(PQUEUE Q,int QueueMaxsize);   
bool FullQueue(PQUEUE Q);  
bool EmptyQueue(PQUEUE Q);  
bool Enqueue(PQUEUE Q, int val);  
bool Dequeue(PQUEUE Q, int *val);  

///
//利用计数标志区分队空还是队满
//
typedef struct queue2   
{  
	QueueElementDataType *pBase;	  //初始化的动态非配存储空间
	int front;    //队头指针，指向队首位置，删除一个元素就将front顺时针移动一位  
	int rear;    //队尾指针，指向队列最后一个元素的下一个元素，插入一个元素就将rear顺时针移动一位 
	int QueueMaxsize; //循环队列的最大存储空间  
	int nCount;	 //计算器
}QUEUE2,*PQUEUE2;  

void InitialQueue2(PQUEUE2 Q,int QueueMaxsize); 
bool FullQueue2(PQUEUE2 Q);  
bool EmptyQueue2(PQUEUE2 Q); 
bool Enqueue2(PQUEUE2 Q, int val);  
bool Dequeue2(PQUEUE2 Q, int *val);  

#endif