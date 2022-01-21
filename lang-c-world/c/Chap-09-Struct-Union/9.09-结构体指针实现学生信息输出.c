#include <stdio.h>

//编写程序输入一个学生的基本信息，包括学号、姓名、三门课程的成绩、
//并计算该学生三门课程成绩的平均值，最后输出该学生信息

typedef struct person
{
    int num;
    char name[21];
    int s[3];
    float aver;
}PERSON;

void Input(PERSON *p)/* 用指向结构体的指针变量作形参 */
{
    scanf("%d%s%d%d%d",&p->num,p->name,&p->s[0],&p->s[1],&p->s[2]);
    p->aver=(p->s[0]+p->s[1]+p->s[2])/3.0;
}

int main()
{
    PERSON st;
    printf("please input information\n");
    Input(&st);/* 实现引用传递 */
    printf("\nthe information is:\n");
    printf("%d\t%s\t %d %d %d %5.2f\n",st.num,st.name,st.s[0],st.s[1],st.s[2],st.aver);
    return 0;
}
