#include <stdio.h>
#include <string.h>

/*选票的统计：设有3个班长候选人"fu"、"lu"、"shou"，全班共80个人，
个人只能选一位班长候选人的名字，再按票数从高到低的顺序输出各候选人的得票数 */

struct person
{
    char name[20];
    int count;
};

int main()
{
    struct person leader[3]={"fu",0,"lu",0,"shou",0},t;
    int i,j,k;
    int n=3,m;/* 班长候选人数 */
    char name[20];
    printf("please input count of votes:");
    scanf("%d",&m);
    printf("please input the elestion`s name:\n");
    for(i=1;i<=m;i++)
    {
        printf("No.%d:",i);
        scanf("%s",&name);
        for(j=0;j<3;j++)
            if(strcmp(name,leader[j].name)==0)
                leader[j].count++;
    }
    for(i=0;i<n-1;i++)/* 以得票数为关键，进行升序排序 */
    {
        k=i;
        for(j=i+1;j<n;j++)
            if(leader[k].count<leader[j].count)
                k=j;
        if(k!=i)
        {
            t=leader[i];
            leader[i]=leader[k];
            leader[k]=t;
        }
    }
    printf("the vote leader is:\n");
    for(i=0;i<3;i++)
        printf("%s\t%d\n",leader[i].name,leader[i].count);
    return 0;
}
