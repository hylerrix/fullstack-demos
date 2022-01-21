#include <stdio.h>

//求3*4的矩阵中所有元素的最大值，要求用函数来实现

max(int b[][4])
{
    int i,j,k,max1;
    max1=b[0][0];
    for(i=0;i<3;i++)
        for(j=0;j<4;j++)
            if(b[i][j]>max1)
                max1=b[i][j];
    return (max1);
}

int main()
{
    int m,a[3][4]={5,16,30,40,23,4,156,8,1,3,50,37};
    m=max(a);
    printf("max is %d\n",m);
    return 0;
}
