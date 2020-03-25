#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef int ElemType;

typedef struct 
{
	ElemType data[MAXSIZE];
	int rear,front;
}CSeQueue;

// 置空队
CSeQueue *InitQueue();
// 入队操作
int InSeQueue(CSeQueue *q, ElemType x);
// 出队操作
int OutSeQueue(CSeQueue *q, ElemType *x);
// 判队空操作
int EmptySeQueue(CSeQueue *q);

int main(void)
{
	CSeQueue *q;
	ElemType x;
	q = InitQueue();
	printf("EmptySeQueue(q): %d\n", EmptySeQueue(q));
	printf("InSeQueue(q, 1): %d\n", InSeQueue(q, 1));
	printf("InSeQueue(q, 1): %d\n", InSeQueue(q, 2));
	printf("InSeQueue(q, 1): %d\n", InSeQueue(q, 3));
	printf("OutSeQueue(q, &x): %d\n", OutSeQueue(q, &x));
	printf("x: %d\n", x);
	printf("OutSeQueue(q, &x): %d\n", OutSeQueue(q, &x));
	printf("x: %d\n", x);
	printf("EmptySeQueue(q): %d\n", EmptySeQueue(q));
	return 0;
}

CSeQueue *InitQueue()
{
	CSeQueue *q;
	q = (CSeQueue *)malloc(sizeof(CSeQueue));
	q->front = q->rear = MAXSIZE - 1;
	return q;
}

int InSeQueue(CSeQueue *q, ElemType x)
{
	if ((q->rear +1) % MAXSIZE == q->front)
	    return 0;
	q->rear = (q->rear+1) % MAXSIZE;
	q->data[q->rear] = x;
	return 1;
}

int OutSeQueue(CSeQueue *q, ElemType *x)
{
	if (q->front == q->rear)
		return 0;
	q->front = (q->front+1) % MAXSIZE;
	*x = q->data[q->front];
	return 1;
}

int EmptySeQueue(CSeQueue *q)
{
	if (q->front == q->rear)
		return 1;
    return 0;
}