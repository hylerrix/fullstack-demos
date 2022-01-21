#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct StackNode
{
	ElemType data;
	struct StackNode *next;
}slStackType;

// 入栈操作
int PushLStack(slStackType *Top, ElemType x);
ElemType PopLStack(slStackType *Top);

int main(void)
{
	slStackType *Top;
	printf("PushLstack(Top, 1): %d\n", PushLStack(Top, 1));
	printf("PopLStack(Top): %d\n", PopLStack(Top));
	return 0;
}

int PushLStack(slStackType *Top, ElemType x)
{
    slStackType *P;
    P = (slStackType *)malloc(sizeof(slStackType));
    if (P == NULL)
    	return 0;
    P->data = x;
    P->next = Top->next;
    Top->next = P;
    return 1;
}

ElemType PopLStack(slStackType *Top)
{
    slStackType *P;
    ElemType x;
    if (Top->next == NULL)
    	return 0;
    P = Top->next;
    Top->next = P->next;
    x = P->data;
    free(P);
    return x;
}