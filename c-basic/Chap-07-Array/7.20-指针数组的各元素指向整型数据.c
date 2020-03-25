#include <stdio.h>

//指针数组的各元素指向整型数据的简单示例

int main(){
    int sp[4]={5,6,7,8};
    int *q[4]={&sp[0],&sp[1],&sp[2],&sp[3]};
    int **p;/* 定义二级指针变量p */
    printf("二级指针访问：\n");
    for(p=q;p<q+4;p++)
        printf("%3d",**p);/* **p表示两次指针访问 */
    return 0;
}
