#include <stdio.h>
#include <math.h>
#define PI 3.1415926

//函数的嵌套调用

float area_ring(float x,float y);
float area(float r);

int main()
{
    float r,r1;
    printf("input two figures:\n");
    scanf("%f,%f",&r,&r1);
    printf("area_ring is %f ",area_ring(r,r1));
    return 0;
}

float area_ring(float x,float y)
{
    float c;
    c=fabs(area(x)-area(y));
    return c;
}

float area(float r)
{
    return (PI*r*r);
}
