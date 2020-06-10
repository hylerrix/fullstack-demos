#include <stdio.h>

/*输入一个学生的基本信息，
包括学号、姓名、性别、年龄、出生日期、三门成绩，
输出该学生的基本信息和平均成绩*/

struct date
{
    int year;/* 年份 */
    int month;/* 月份 */
    int day; /* 日期 */
};

struct student
{
    char num[9];/* 学号 */
    char name[21];/* 姓名 */
    char sex;/* 性别 */
    int age;/* 年龄 */
    struct date birthday;/* 引用了struct dat e类型 */
    int score[3];/* 三门成绩 */
    float aver;/* 三门成绩的平均值 */
};

int main()
{
    struct student stu;
    int i,sum=0;
    printf("please input the information:\n");
    printf("please input num:");
    scanf("%s",&stu.num);
    printf("please input name:");
    scanf("%s",&stu.name);
    printf("please input sex:");
    flushall();/*  清楚输入缓存区。以便正确输入性别 */
    scanf("%c",&stu.sex);
    printf("please input age:");
    scanf("%d",&stu.age);
    printf("please input birthday:");
    scanf("%d%d%d",&stu.birthday.year,&stu.birthday.month,&stu.birthday.day);
    printf("please input scores:");
    for(i=0;i<3;i++)/*  循环输入该学生的三门成绩 */
        scanf("%d",&stu.score[i]);
    for(i=0;i<3;i++)/*  计算该学生的三门成绩的总和 */
        sum+=stu.score[i];
    stu.aver=sum/3.0;/*  计算该学生的三门成绩的平均值 */
    printf("\nthe information is:");
    printf("\nthe num is %s",stu.num);
    printf("\nthe name is %s",stu.name);
    printf("\nthe sex is %c",stu.sex);
    printf("\nthe age is %d",stu.age);
    printf("\nthe birthday is %02d-%02d-%02d",stu.birthday.year,stu.birthday.month,stu.birthday.day);
    printf("\nthe score is");
    for(i=0;i<3;i++)
        printf("%d ",stu.score[i]);
    printf("\nthe aver is %.2f\n",stu.aver);
    return 0;
}
