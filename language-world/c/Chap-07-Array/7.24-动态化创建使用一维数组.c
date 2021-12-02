#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//用动态数组实现一维数组的创建和使用

int main(){
    int *array = NULL,num,i;
    printf("please input the number of element:");
    scanf("%d",&num);/* 申请动态数组使用的内存块 */
    array=(int *)malloc(sizeof(int)*num);
    if(array==NULL){
        printf("out of memory,press any key to quit...\n");
        exit(0);
    }
    /* 提示输入num个数据 */
    printf("please input %d elements: ",num);
    for(i=0;i<num;i++)
        scanf("%d",&array[i]);
    /* 输出刚输入的num个数据 */
    printf("%d elements are: \n",num);
    for(i=0;i<num;i++)
        printf("%d,",array[i]);
    free(array);/* 释放又malloc函数申请的内存块 */
    return 0;
}
