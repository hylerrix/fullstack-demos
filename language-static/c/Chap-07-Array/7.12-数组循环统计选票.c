#include <stdio.h>

//统计选票，假设候选人有3人，参加投票的有6人

int main(){
    char k[15],s[3][15];
    int b[3],i,j;
    printf("请输入3个候选人：\n");
    for(i=0;i<3;i++){
        gets(s[i]);
        b[i]=0;
    }
    printf("请输入6张选票：\n");
    for(i=0;i<6;i++){/* 6张票 */
        gets(k);
        for(j=0;j<3;j++)
            if(!strcmp(s[j],k))    b[j]++;
    }
    printf("选票结果：\n");
    for(i=0;i<3;i++)
        printf("%s:%d\n",s[i],b[i]);
    return 0;
}
