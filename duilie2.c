//circular_queue.cpp

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
	int* pBase;
	int front;
	int rear;
}QUEUE,* PQUEUE;

int max_size = 6;//数组长度

//声明
void init_queue(PQUEUE pQ);//初始化
bool is_full_queue(PQUEUE pQ);//判满，限定最大元素数为maxsize-1
bool is_empty_queue(PQUEUE pQ);//判空
bool enqueue(PQUEUE pQ, int val);//入队，调用判满
void traverse_queue(PQUEUE pQ);//遍历输出
void dequeue(PQUEUE pQ);//出队

int main() {
	QUEUE Q;
	init_queue(&Q);
	enqueue(&Q, 1);
	enqueue(&Q, 2);
	enqueue(&Q, 3);
	enqueue(&Q, 4);
	enqueue(&Q, 5);
	traverse_queue(&Q);
	enqueue(&Q, 6);
	dequeue(&Q);
	dequeue(&Q);
	dequeue(&Q);
	dequeue(&Q);
	dequeue(&Q);
	dequeue(&Q);

	return 0;
}

void init_queue(PQUEUE pQ) {
	pQ->pBase = (int*)malloc(sizeof(int) * max_size);
	pQ->front = pQ->rear = 0;
}

bool is_full_queue(PQUEUE pQ) {
	if (pQ->front == (pQ->rear + 1) % max_size) {
		return true;
	}
	else {
		return false;
	}
}

bool is_empty_queue(PQUEUE pQ) {
	if (pQ->front == pQ->rear) {
		return true;
	}
	else {
		return false;
	}
}

bool enqueue(PQUEUE pQ, int val) {
	if (is_full_queue(pQ)) {
		printf("入队失败，队列已满！\n");
		return false;
	}
	else {
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear + 1) % max_size;
		return true;
	}
}

void traverse_queue(PQUEUE pQ) {
	int i = pQ->front;
	while (i != pQ->rear) {
		printf("%d ", pQ->pBase[i]);
		i = (i + 1) % max_size;
	}
	printf("\n");
}

void dequeue(PQUEUE pQ) {
	if (is_empty_queue(pQ)) {
		printf("出队失败，这是空队！\n");
		return;
	}
	else {
		int val = pQ->pBase[pQ->front];
		printf("出队：%d \n", val);
		pQ->front = (pQ->front + 1) % max_size;
	}
}
