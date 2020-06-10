#include <stdio.h>

//静态局部变量

int n=1;

func()
{
    static int a=2;/* 静态局部变量，与main()函数中的a不同 */
    a+=2;
    ++n;
    printf("func:n=%d    a=%d\n",n,a);
}

int main()
{
    static int a;/* 静态局部变量，初始化为0 */
    printf("main:n=%d    a=%d\n",n,a);
    func();
    a+=10;
    printf("main:n=%d    a=%d\n",n,a);
    func();
    printf("main:n=%d    a=%d\n",n,a);
    return 0;
}
