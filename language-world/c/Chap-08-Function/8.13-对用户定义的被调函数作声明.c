#include <stdio.h>

//对用户定义的被调函数作声明

int main()
{
    float add(float x,float y);/* 对被调函数的声明 */
    float a,b,c;
    scanf("%f,%f",&a,&b);
    c=add(a,b);
    printf("sum is %f",c);
    return 0;
}

float add(float x,float y)/* 函数定义 */
{
    return (x+y);
}
