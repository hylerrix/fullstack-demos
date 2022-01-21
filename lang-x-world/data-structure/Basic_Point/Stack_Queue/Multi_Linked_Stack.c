#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
typedef int ElemType;

typedef struct StackNode
{
	ElemType data;
	struct StackNode *next;
}slStackType;

int PushDupLS(slStackType *Top[MAXSIZE], int i, ElemType x);

int main(void)
{
	slStackType *Top[MAXSIZE];
	printf("PushDupLS(Top, 2, 3): %d\n", PushDupLS(Top, 0, 2));;
	printf("PopDupLS(Top, 1): %d\n", PopDupLS(Top, 0));
	return 0;
}

int PushDupLS(slStackType *Top[MAXSIZE], int i, ElemType x)
{
	slStackType *p;
	p = (slStackType *)malloc(sizeof(slStackType));
	if (p == NULL)
		return 0;
	p->data = x;
	p->next = Top[i]->next;
	Top[i]->next = p;
	return 1;
}

ElemType PopDupLS(slStackType *Top[MAXSIZE], int i)
{
	slStackType *p;
	ElemType x;
	if (Top[i]->next == NULL)
	    return 0;
    p = Top[i]->next;
    Top[i]->next = p->next;
    x = p->data;
    free(p);
    return x;
}