#include <stdio.h>
#include <stdlib.h>

//使用malloc函数动态分配空间

int main()
{
    int *iIntMalloc=(int *)malloc(sizeof(int));//分配空间
    *iIntMalloc=100;//使用该空间保存数据
    printf("%d\n",*iIntMalloc);
    return 0;
}
