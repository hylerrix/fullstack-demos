#include <stdio.h>
#include "horse.h"

extern SqStack S;

void OutputPath()    // 输出马走过的路径
{
    int i,f,k;
    SqStack s1 = S;
    int path[N][N];
    for (i = 0; s1.top != s1.base; i++) {
    	path[(*s1.base).seat.x][(*s1.base).seat.y] = i+1;
    	++s1.base;
    }
    for (f = 0; f < N; f++) {
        printf("\n");
        for (k = 0; k < N; k++) {
        	printf("\t%d", (path[f][k]));
        }
    }
    printf("\n");
}