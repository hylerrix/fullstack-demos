#include <stdio.h>

//寄存器变量

int main()
{
    register int temp=0,j;
    int i;
    for(i=1;i<100;i++)
    {
        for(j=0;j<1000;j++)
            temp+=j;
        printf("i=%d    temp%d",i,temp);
        temp%=1;
    }
    return 0;
}
