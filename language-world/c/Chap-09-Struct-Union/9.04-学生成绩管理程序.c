#include <stdio.h>
#include <stdlib.h>
#define N 20 /*学生总人数不超过20人*/

//编写程序完成对学生成绩的管理，要求实现的功能包括：
//(1)学生信息录入：从键盘按学号顺序输入n名学生信息（学号、姓名、3门课程成绩）。
//(2)计算平均值：计算每个学生3门课程成绩的平均值。
//(3)学生信息排序：按照平均值从低到高的顺序对录入的学生信息进行排序。
//(4)学生信息输出：将排好序的学生信息输出。

struct student/* 学生结构体类型定义 */
{
    int id;
    char name[20];
    int score[3];
    float aver;
};

void Input(struct student st[],int n)/* n个学生信息的录入 */
{
    int i,j;
    printf("Please input Information:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&st[i].id);
        scanf("%s",st[i].name);
        for(j=0;j<3;j++)
            scanf("%d",&st[i].score[j]);
    }
}

void CalAver(struct student st[],int n)/* 计算n个学生3门课的平均值 */
{
    int i,j;
    for(i=0;i<n;i++)
    {
        int s=0;
        for(j=0;j<3;j ++)
            s+=st[i].score[j];
        st[i].aver=s/3.0;
    }
}

void Sort(struct student st[],int n)/* 依据平均值，对n个学生的信息进行排序 */
{
    int i,j,k;
    struct student t;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
            if(st[k].aver>st[j].aver)
                k=j;
        if(k!=i)
        {
            t=st[k];
            st[k]=st[i];
            st[i]=t;
        }
    }
}

void Output(struct student st[],int n)/* n个学生的信息输出 */
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("%d\t%s",st[i].id,st[i].name);
        for(j=0;j<3;j++)
            printf("\t%d",st[i].score[j]);
        printf("\t%f\n",st[i].aver);
    }
}

int main()
{
    int n;
    struct student st[N];
    printf("please input numbers: ");
    scanf("%d",&n);
    Input(st,n);/* 调用输入函数 */
    CalAver(st,n);/* 调用计算平均值函数 */
    Sort(st,n);/* 调用排序函数 */
    Output(st,n);/* 调用输出函数 */
    return 0;
}
