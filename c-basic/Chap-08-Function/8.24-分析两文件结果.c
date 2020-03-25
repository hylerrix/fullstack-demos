#include <stdio.h>

//下面程序由两个文件组成，请分析运行结果

/* 文件一 */
int x=10;/* 定义非静态全局变量x,y */
int y=10;

add()
{
    y=10+x;
    x=x*2;
}

int main()
{
    extern sub();/* 对外部函数sub进行引用声明 */
    x+=5;
    add();



    /* 此段内容没印刷上 */


    return 0;
}
