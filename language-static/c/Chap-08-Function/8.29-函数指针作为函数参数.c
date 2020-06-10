#include <stdio.h>

//用指向函数的指针变量作为函数的参数

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

int result(int n,int (*p)(int))
{
    int sum;
    sum=(*p)(n);/* 调用p所指向的函数 */
    return sum;
}

int main()
{
    int n,sum,flag;
    printf("input n:");
    scanf("%d",&n);
    printf("input flag(0 or 1):");
    scanf("%d",&flag);
    if(flag==1)    sum=result(n,oddsum);
    else    sum=result(n,evensum);
    printf("sum=%d\n",sum);
    return 0;
}
