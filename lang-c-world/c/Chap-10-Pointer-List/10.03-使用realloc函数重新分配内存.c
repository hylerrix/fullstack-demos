#include <stdio.h>
#include <stdlib.h>

//使用realloc函数重新分配内存

int main()
{
    short *s;/* 定义短整型指针变量s */
    double *f=(double *)malloc(sizeof(double));/* 申请double变量所占内存空间 */
    printf("指针f指向内存空间的起始地址：%d\n",f);/* 打印首地址 */
    printf("指针f指向内存空间的大小，%d字节\n",sizeof(*f));/* 打印空间大小 */
    s=(short *)realloc(f,sizeof(short));/* 重新分配内存 */
    printf("指针s指向内存空间的起始地址：%d\n",s);/* 打印首地址 */
    printf("指针s指向内存空间的大小，%d字节\n",sizeof(*s));/* 打印空间大小 */
    return 0;
}
