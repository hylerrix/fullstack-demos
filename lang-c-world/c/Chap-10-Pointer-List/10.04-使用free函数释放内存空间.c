#include <stdio.h>
#include <stdlib.h>

//使用free函数释放内存空间

int main()
{
    int *pInt;
    pInt=(int *)malloc(sizeof(pInt));
    *pInt=100;
    printf("%d\n",*pInt);
    free(pInt);
    printf("%d\n",*pInt);
    return 0;
}
