#include <stdio.h>

//输入两个整数，按从小到大的顺序输出，调用swap函数实现变量值的交换。

swap(int a1,int a2)
{
    int a;
    a=a1;
    a1=a2;
    a2=a;/* 交换a1和a2,m和n不变 */
}

int main()
{
    int m,n;
    printf("Input m,n:");
    scanf("%d%d",&m,&n);
    if(m>n) swap(m,n);/* 实参传送m和n的值 */
    printf("Sorted:%d %d \n",m,n);
    return 0;
}
