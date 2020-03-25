#include <stdlib.h>
#include "horse.h"

extern SqStack S;

int InitStack()    // 初始化一个空栈
{
	S.base = (ElemType *)malloc(STACK_SIZE * sizeof(ElemType));
	if (!S.base)
		return 0;
	S.top = S.base;
	S.stacksize = STACK_SIZE;
	return 1;
}

ElemType GetTop()    // 取得栈顶的值
{
	// if (S.top == s.base)
	// 	exit(0);
	return *(S.top-1);
}

void Push(ElemType elem)    // 将元素压入栈
{
	*S.top++=elem;
}

int Pop(ElemType *elem)    // 将栈顶值出栈
{
    if (S.top == S.base) 
    	return 0;
    *elem = *--S.top;
    return 1;
}

int StackEmpty()    // 判断栈是否为空
{
	if (S.top == S.base)
		return 1;
    return 0;
}