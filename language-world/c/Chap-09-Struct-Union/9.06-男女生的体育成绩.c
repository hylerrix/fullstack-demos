#include <stdio.h>
#define N 10

/*
һ���������γɼ�����������1500�׳ɼ�x��x�룬Ů�����������ԣ���A��B��C��D��E5�ȣ�
�͸��ԳŴ��������������ݷ���һ�ű��У����а���ѧ�š������� �Ա�������ɼ���
���һ������ɼ� �������ݸ����Ա���д��ͬ�����ݡ�
�������ɼ����ݣ����Ա����ʽ�����
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
