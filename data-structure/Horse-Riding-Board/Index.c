#include <stdio.h>
#include "horse.h"

extern SqStack S;

int main(void)
{
    PosType start;
    InitStack();
    printf("请输入起始位置：（0-7）\n");
    printf("X: ");
    scanf("%d", &start.x);
    printf("Y: ");
    scanf("%d", &start.y);
    SetWeight();
    SetMap();
    HorsePath(start);
    OutputPath();
	return 0;
}




