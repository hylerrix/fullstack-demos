#include <stdio.h>
#define N 10

/*
一个班体育课成绩，男生测验1500米成绩x分x秒，女生测验柔韧性（分A、B、C、D和E5等）
和俯卧撑次数，将测验数据放在一张表中，表中包括学号、姓名、 性别和体育成绩。
最后一项“体育成绩 ”的内容根据性别填写不同的内容。
编程输入成绩数据，再以表格形式输出。
*/

struct boyscore
{
    int minute;
    int second;
};

struct girlscore
{
    char flexibility;
    int number;
};

struct student
{
    char num[9];
    char name[21];
    char sex;
    union
    {
        struct boyscore bs;
        struct girlscore gs;
    }score;
};

int main()
{
    struct student st[N];
    int n,i;
    printf("please input number of students:");
    scanf("%d",&n);
    printf("please input num name sex score:\n");
    for(i=0;i<n;i++)
    {
        printf("No%d.stu is: ",i+1);
        scanf("%s%s %c",st[i].num,st[i].name,&st[i].sex);
        if(st[i].sex=='b'  ||  st[i].sex=='B')
            scanf("%d%d",&st[i].score.bs.minute,&st[i].score.bs.second);
        else if(st[i].sex=='g'  ||  st[i].sex=='G')
            scanf(" %c%d",&st[i].score.gs.flexibility,&st[i].score.gs.number);
        else
            printf("input error!");
    }
    printf("\nthe information is:\n");
    for(i=0;i<n;i++)
    {
        printf("%-8s %s\t",st[i].num,st[i].name,st[i].sex);
        if(st[i].sex=='b'  ||  st[i].sex=='B')
            printf("%d:%d\n",st[i].score.bs.minute,st[i].score.bs.second);
        else if(st[i].sex=='g'  ||  st[i].sex=='G')
            printf("%c and %d\n",st[i].score.gs.flexibility,st[i].score.gs.number);
    }
    return 0;
}
