#include <stdio.h>

//函数表达式调用出现在实参表中

max(int x,int y)
{
    int z;
    z=(x>y)?x:y;
    return(z);
}

int main()
{
    int a,b,c,m;
    scanf("%d,%d,%d",&a,&b,&c);
    m=max(max(a,b),c);
    printf("max=%d",m);
    return 0;
}
