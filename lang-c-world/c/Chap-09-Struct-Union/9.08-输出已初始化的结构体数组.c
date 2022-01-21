#include <stdio.h>

//编写程序输出初始化好的结构体数组中的元素信息

typedef struct student/* 结构体类型定义 */
{
    int id;
    char name[20];
    int score;
}STUDENT,*STU;

int main()
{
    STUDENT st[3]={{10101,"Li Lin",98},{10102,"Zhang Fun",87},{10103,"Wang Min",79}};/* 结构体数组初始化 */
    STUDENT *p;/* STU p;也可以定义结构体类型指针变量p */
    for(p=st;p<st+3;p++)
        printf("%-6d%s\t%d\n",p->id,p->name,p->score);
    return 0;
}
