#include <stdio.h>
#define PI 3.14

//已知圆的半径，求周长、面积

float c,area;

void f(float r)
{
    c=2*PI*r;
    area=PI*r*r;
}

int main()
{
    float r;
    printf("input radius:");
    scanf("%f",&r);
    f(r);
    printf("%f,%f\n",c,area);
    return 0;
}
