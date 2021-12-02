#include <stdio.h>

//求自然数1~n的奇数和或偶数和，用指向函数的指针变量实现

int evensum(int n)/* 求自然数1~n中偶数的和 */
{
    int i,sum=0;
    for(i=2;i<=n;i+=2)
        sum+=i;
    return sum;
}

int oddsum(int n)/* 求自然数1~n中奇数的和 */
{
    int i,sum=0;
    for(i=1;i<=n;i+=2)
        sum+=i;
    return sum;
}

int main()
{
    int n,sum,flag;
    int (*p)(int);/*定义指向函数的指针变量*/
    printf("input n:");
    scanf("%d",&n);
    printf("input flag(0 or 1):");
    scanf("%d",&flag);/* 输入标志 */
    if(flag==1)    p=oddsum;/* 当flag为1时，p指向函数oddsum */
    else    p=evensum;/* 当flag尾华1时，p指向函数evensum */
    sum=(*p)(n);
    printf("sum=%d\n",sum);
    return 0;
}
