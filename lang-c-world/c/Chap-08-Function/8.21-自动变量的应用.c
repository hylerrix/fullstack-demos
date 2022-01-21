#include <stdio.h>

//自动变量的应用

func(int n)
{
    auto int a=2;/* 自动变量a，每调用一次都要重新赋初值 */
    a+=2;
    ++n;
    printf("func:n=%d    a=%d\n",n,a);
}

int main()
{
    int a=0;/* 自动变量，与func()不同 */
    func(1);
    printf("main:n=1     a=%d\n",a);
    a+=10;
    func(2);
    printf("main:n=1     a=%d\n",a);
    return 0;
}
