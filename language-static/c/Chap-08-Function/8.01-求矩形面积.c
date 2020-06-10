#include <stdio.h>

//求矩形面积

print_star()/* 打印星号个数 */
{
    int i;
    for(i=0;i<55;i++)
        printf("*");
    printf("\n");
}

float area(float a,float b)/* 求矩形面积函数 */
{
    float s;
    s=a*b;
    return s;
}

int main()/* 主函数 */
{
    float a,b,s;
    print_star();
    printf("please input a and b:\n");
    scanf("%f,%f",&a,&b);
    s=area(a,b);
    printf("area=%.2f\n",s);
    print_star();
    return 0;
}

8.1 求矩形面积#include <stdio.h>

//求矩形面积

print_star()/* 打印星号个数 */
{
    int i;
    for(i=0;i<55;i++)
        printf("*");
    printf("\n");
}

float area(float a,float b)/* 求矩形面积函数 */
{
    float s;
    s=a*b;
    return s;
}

int main()/* 主函数 */
{
    float a,b,s;
    print_star();
    printf("please input a and b:\n");
    scanf("%f,%f",&a,&b);
    s=area(a,b);
    printf("area=%.2f\n",s);
    print_star();
    return 0;
}
