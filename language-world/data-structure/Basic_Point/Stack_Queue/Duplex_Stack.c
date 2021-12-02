#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
typedef int ElemType;

typedef struct
{
	ElemType stack[MAXSIZE];
	int lefttop;
	int righttop;
}DupSeqStack;

DupSeqStack *InitDupStack();
int PushDupStack(DupSeqStack *S, char status, ElemType x);
ElemType PopDupStack(DupSeqStack *s, char status);

int main(void)
{
    DupSeqStack *S = InitDupStack();
    char status;
    status = 'L';
    printf("PushDupStack(S, status, 1): %d\n", PushDupStack(S, status, 1));
	printf("PopDupStack(S, status): %d\n", PopDupStack(S, status));
	printf("PopDupStack(S, status): %d\n", PopDupStack(S, status));
	return 0;
}

DupSeqStack *InitDupStack()
{
    DupSeqStack *S;
    S = (DupSeqStack *)malloc(sizeof(DupSeqStack));
    S->lefttop = -1;
    S->righttop = MAXSIZE-1;
    return S;
}

int PushDupStack(DupSeqStack *S, char status, ElemType x)
{
    if (S->lefttop+1 == S->righttop)
    	return 0;
    switch (status) {
    	case 'L':
            S->stack[++S->lefttop] = x;
            break;
        case 'R':
            S->stack[--S->righttop] = x;
            break;
        default:
            return 0;
            break;
    }
    return 1;
}

ElemType PopDupStack(DupSeqStack *S, char status)
{
	if (S->lefttop+1 == S->righttop)
    	return 0;
    switch (status) {
    	case 'L':
            if (S->lefttop < 0)
            	return 0;
            return S->stack[S->lefttop--];
            break;
        case 'R':
            if (S->righttop > MAXSIZE-1)
            	return 0;
            return S->stack[S->righttop++];
            break;
        default:
            return 0;
            break;
    }
    return 1;
}