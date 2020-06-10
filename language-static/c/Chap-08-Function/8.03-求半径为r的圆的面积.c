#include <stdio.h>
#define PI 3.1415926

//求半径为r的圆的面积

float a(float r)
{
    return(PI*r*r);
}

int main()
{
    float r;
    printf("请输入圆的半径：");
    scanf("%f",&r);
    printf("area=%f",a(r));
    return 0;
}
