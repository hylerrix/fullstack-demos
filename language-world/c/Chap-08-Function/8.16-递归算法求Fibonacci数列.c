#include <stdio.h>

//利用递归算法求Fibonacci数列

long f(int n)
{
    long s;
    if(n==1 || n==2)
        return 1;
    s=f(n-1)+f(n-2);
    return s;
}

int main()
{
    int n;
    printf("please input n:\n");
    scanf("%d",&n);
    if(n<0)
        printf("error!\n");
    else
        printf("第%d项Fibonacci数列的值为%ld",n,f(n));
    return 0;
}
