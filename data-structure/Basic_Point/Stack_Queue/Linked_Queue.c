#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}QNode;

typedef struct
{
	QNode *front;
	QNode *rear;
}LQueue;

// 创建一个带头结点的空队
LQueue *Init_LQueue();
// 入队
int InLQueue(LQueue *Q, ElemType x);
// 判队空
int Empty_LQueue(LQueue *Q);
// 出队
int Out_LQueue(LQueue *Q, ElemType *x);

int main(void)
{
	LQueue *Q;
	ElemType x;
	Q = Init_LQueue();
    printf("Empty_LQueue(Q): %d\n", Empty_LQueue(Q));
    printf("InLQueue(Q, 2): %d\n", InLQueue(Q, 2));
    printf("InLQueue(Q, 3): %d\n", InLQueue(Q, 3));
    printf("Empty_LQueue(Q): %d\n", Empty_LQueue(Q));
    printf("Out_LQueue(Q, x): %d\n", Out_LQueue(Q, &x));
    printf("x: %d\n", x);
	return 0;
}

LQueue *Init_LQueue()
{
	LQueue *Q;
	QNode *p;
	Q = malloc(sizeof(LQueue *));
	p = malloc(sizeof(LQueue *));
	p->next = NULL;
	Q->front = Q->rear = p;
	return Q;
}

int InLQueue(LQueue *Q, ElemType x)
{
    QNode *p;
    p = malloc(sizeof(QNode));
    p->data = x;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return 1;
}

int Empty_LQueue(LQueue *Q)
{
    if (Q->front == Q->rear)
    	return 1;
    return 0;
}

int Out_LQueue(LQueue *Q, ElemType *x)
{
	QNode *p;
	if(Empty_LQueue(Q))
		return 0;
	p = Q->front->next;
	Q->front->next = p->next;
	*x = p->data;
	free(p);
	if (Q->front->next == NULL)
	    Q->rear = Q->front;
	return 1;
}