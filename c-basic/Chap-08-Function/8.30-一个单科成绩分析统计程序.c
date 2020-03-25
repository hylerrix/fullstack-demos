#include <stdio.h>
#define N 30

//编写#include <stdio.h>
#define N 30

//编写一个单科成绩分析统计程序，要求如下：
//(1)从键盘输入N名同学的成绩
//(2)求其平均分、最高分、最低分
//(3)并统计各分数段人数和及格率
//(4)对学生成绩进行降序排序
//(5)使用菜单完成各功能

input(float s[],int n)
{
    int i;
    printf("请输入%d名学生的成绩：\n",n);
    for(i=0;i<n;i++)
    scanf("%f",&s[i]);
}

count(float s[],int n)
{
    int i,j,b[10]={0,0,0,0,0,0,0,0,0,0};
    int failure=0;
    for(i=0;i<n;i++)
    {
        j=s[i]/10;
        b[j]++;
    }
    printf(" 0-9 ,10-19,20-29,30-39,40-49,50-59,60-69,70-79,80-89,90-100\n");
    for(i=0;i<10;i++)
        printf("  %-4d",b[i]);
    for(i=0;i<6;i++)
        failure+=b[i];
    printf("\n及格率：%2.f%%\n",(n-failure)/n*100);
}

avemaxmin(float s[],int n,float *aver,float *max,float *min)
{
    int i;
    float sum;
    for(i=0;i<n;i++)
        sum+=s[i];
    *min=s[0];
    *max=s[0];
    for(i=0;i<n;i++)
        if(s[i]<s[0])
            *min=s[i];
        if(s[i]>s[0])
            *max=s[i+1];
    *aver=sum/n;
}

sort(float s[],int n)
{
    int i,j,t;
    for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
            if(s[j]<s[j+1])
            {
                t=s[j];
                s[j]=s[j+1];
                s[j+1]=t;
            }
}

output(float s[],int n)
{
    int i;
    printf("排序后的成绩为：\n");
    for(i=0;i<n;i++)
        printf("%.2f   ",s[i]);
    printf("\n");
}

int main()
{
    int choice,n;
    float s[N],aver,max,min;
    do
    {
        printf("1.输入N名同学成绩（必须先输入成绩）\n");
        printf("2.求平均分、最高分、最低分\n");
        printf("3.分段统计人数和及格率\n");
        printf("4.排序\n");
        printf("0.退出系统\n");
        printf("请选择(0~4)：请输入选择：");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("请输入学生人数：");
                scanf("%d",&n);
                input(s,n);
                break;
            case 2:
                avemaxmin(s,n,&aver,&max,&min);
                printf("平均分=%.2f,最高分=%.2f,最低分=%.2f\n",aver,max,min);
                break;
            case 3:
                count(s,n);
                break;
            case 4:
                sort(s,n);
                output;
                break;
            case 0:break;
        }
    }while(choice!=0);
    return 0;
}，要求如下：
//(1)从键盘输入N名同学的成绩
//(2)求其平均分、最高分、最低分
//(3)并统计各分数段人数和及格率
//(4)对学生成绩进行降序排序
//(5)使用菜单完成各功能

input(float s[],int n)
{
    int i;
    printf("请输入%d名学生的成绩：\n",n);
    for(i=0;i<n;i++)
    scanf("%f",&s[i]);
}

count(float s[],int n)
{
    int i,j,b[10]={0,0,0,0,0,0,0,0,0,0};
    int failure=0;
    for(i=0;i<n;i++)
    {
        j=s[i]/10;
        b[j]++;
    }
    printf(" 0-9 ,10-19,20-29,30-39,40-49,50-59,60-69,70-79,80-89,90-100\n");
    for(i=0;i<10;i++)
        printf("  %-4d",b[i]);
    for(i=0;i<6;i++)
        failure+=b[i];
    printf("\n及格率：%2.f%%\n",(n-failure)/n*100);
}

avemaxmin(float s[],int n,float *aver,float *max,float *min)
{
    int i;
    float sum;
    for(i=0;i<n;i++)
        sum+=s[i];
    *min=s[0];
    *max=s[0];
    for(i=0;i<n;i++)
        if(s[i]<s[0])
            *min=s[i];
        if(s[i]>s[0])
            *max=s[i+1];
    *aver=sum/n;
}

sort(float s[],int n)
{
    int i,j,t;
    for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
            if(s[j]<s[j+1])
            {
                t=s[j];
                s[j]=s[j+1];
                s[j+1]=t;
            }
}

output(float s[],int n)
{
    int i;
    printf("排序后的成绩为：\n");
    for(i=0;i<n;i++)
        printf("%.2f   ",s[i]);
    printf("\n");
}

int main()
{
    int choice,n;
    float s[N],aver,max,min;
    do
    {
        printf("1.输入N名同学成绩（必须先输入成绩）\n");
        printf("2.求平均分、最高分、最低分\n");
        printf("3.分段统计人数和及格率\n");
        printf("4.排序\n");
        printf("0.退出系统\n");
        printf("请选择(0~4)：请输入选择：");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("请输入学生人数：");
                scanf("%d",&n);
                input(s,n);
                break;
            case 2:
                avemaxmin(s,n,&aver,&max,&min);
                printf("平均分=%.2f,最高分=%.2f,最低分=%.2f\n",aver,max,min);
                break;
            case 3:
                count(s,n);
                break;
            case 4:
                sort(s,n);
                output;
                break;
            case 0:break;
        }
    }while(choice!=0);
    return 0;
}
