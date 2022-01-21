#include <stdio.h>

//将用户输入的华氏温度换算成摄氏温度输出。华氏温度与摄氏温度的换算公式为：C=(5/9)*(F-32)

int ftoc(float f)
{
    return (5.0/9.0)*(f-32);
}

int main()
{
    float f;
    printf("请输入一个华氏温度：\n");
    scanf("%f",&f);
    printf("摄氏温度为:%d",ftoc(f));
    return 0;
}
