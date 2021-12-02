#include <stdio.h>

//比较两个数，输出较大者

int a=3,b=5;

max(int x,int y)
{
    int c;
    c=x>y?x:y;
}

int main()
{
    int a=8;
    printf("%d\n",max(a,b));
    return 0;
}
