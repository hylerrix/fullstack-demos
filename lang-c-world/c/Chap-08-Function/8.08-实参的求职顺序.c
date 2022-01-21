#include <stdio.h>

//实参的求职顺序

int main()
{
    int i=3,p;
    p=f(i,++i,++i);/* 函数调用 */
    //Turbo C系统按从右至左的顺序求实参的值，相当于(5,5,4)
    printf("%d",p);
    return 0;
}

int f(int a,int b,int c)/* 函数定义 */
{
    printf("%d %d %d\n",a,b,c);
    return(a+b+c);
}
