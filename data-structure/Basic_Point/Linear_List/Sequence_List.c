#include <stdio.h>
#define OVERFLOW 0
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define MAXSIZE 10

typedef int ElemType;

typedef struct 
{
	ElemType elem[MAXSIZE];
	int length;
}SeqList;

// 顺序表的初始化
void Init_SeqList(SeqList *L);
// 顺序表的插入
int Insert_SeqList(SeqList *L, int i, int x);
// 顺序表的删除
int Delete_SeqList(SeqList *L, int i);
// 顺序表中按值查找
int Location_SeqList(SeqList *L, ElemType x);

int main(void)
{
	SeqList *L;
	
	Init_SeqList(L);
	Insert_SeqList(L, 1, 1);
	Delete_SeqList(L, 1);

	return 0;
}

void Init_SeqList(SeqList *L)
{
	L->length = 0;
}

int Insert_SeqList(SeqList *L, int i, ElemType x)
{
    int j;
    if (L->length == MAXSIZE) {
        return OVERFLOW;
    }
    if (i < 1 || i > L->length + 1) {
        return ERROR;
    }
    for (j = L->length; j >= i; --j) {
        L->elem[j+1] = L->elem[j];
    }
    L->elem[i] = x;
    L->length++;
    return TRUE;
}

int Delete_SeqList(SeqList *L, int i)
{
	int j;
	if (i < 1 || i > L->length)
		return ERROR;
    for (j = i; j < L->length; ++j) {
    	L->elem[j] = L->elem[j+1];
    }
    L->length--;
    return TRUE;
}

int Location_SeqList(SeqList *L, ElemType x)
{
	int i = 1;
	while (i <= L->length && L->elem[i]!=x)
		i++;
	if (i > L->length)
		return FALSE;
	else
		return i;
}