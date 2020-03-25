#include <stdio.h>

//外部变量声明语句

int main()
{
    extern int a;/* 外部引用声明 */
    printf("%d\n",a);
    return 0;
}

int a=5;
