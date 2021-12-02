#include <stdio.h>

//函数表达式调用

max(int x,int y)
{
    int z;
    z=(x>y)?x:y;
    return(z);
}

int main()
{
    int a,b,m;
    scanf("%d,%d",&a,&b);
    m=max(a,b);/* max(a,b)作为表达式出现在赋值号右边 */
    printf("max=%d",m);
    return 0;
}
