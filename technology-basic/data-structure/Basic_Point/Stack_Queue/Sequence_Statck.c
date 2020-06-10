#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int top;
}SeqStack;

// 置空栈
SeqStack *Init_SeqStack();
// 判空栈
int Empty_SeqStack(SeqStack *S);
// 入栈
int Push_SeqStack(SeqStack *S, ElemType x);
// 出栈
int Pop_SeqStack(SeqStack *S, ElemType *x);
// 取栈顶元素
ElemType Top_SeqStack(SeqStack *S);

int main(void)
{
	SeqStack *S = Init_SeqStack();
	ElemType x;
	printf("Empty_SeqStack(S): %d\n", Empty_SeqStack(S));
	Push_SeqStack(S, 2);
	printf("Empty_SeqStack(S): %d\n", Empty_SeqStack(S));
	printf("Top_SeqStack(S): %d\n", Top_SeqStack(S));
    Pop_SeqStack(S, &x);
    printf("Empty_SeqStack(S): %d\n", Empty_SeqStack(S));
	return 0;
}

SeqStack *Init_SeqStack()
{
    SeqStack *S;
    S = (SeqStack *)malloc(sizeof(SeqStack));
    S->top = -1;
    return S;
}

int Empty_SeqStack(SeqStack *S)
{
	if (S->top == -1)
	    return 1;
	return 0; 
}

int Push_SeqStack(SeqStack *S, ElemType x)
{
    if (S->top == MAXSIZE-1)
    	return 0;
    S->top++;
    S->data[S->top] = x;
    return 1;
}

int Pop_SeqStack(SeqStack *S, ElemType *x)
{
	if (Empty_SeqStack(S))
    	return 0;
    *x = S->data[S->top];
    S->top--;
    return 1;
}

ElemType Top_SeqStack(SeqStack *S)
{
	if (Empty_SeqStack(S))
    	return 0;
	return S->data[S->top];
}