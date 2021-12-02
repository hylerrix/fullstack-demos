#include <stdio.h>

//汉诺塔问题

void haoni(int n,char x,char y,char z)
{
    if(n==1) printf("%c->%c\n",x,z);
    else
    {
        haoni(n-1,x,z,y);/* 递归调用 */
        printf("%c->%c\n",x,z);
        haoni(n-1,y,x,z);/* 递归调用 */
    }
}

int main()
{
    int m;
    printf("Input the number of disks:");
    scanf("%d",&m);
    printf("The steps to moving %3d disks:\n",m);
    haoni(m,'A','B','C');
    return 0;
}
