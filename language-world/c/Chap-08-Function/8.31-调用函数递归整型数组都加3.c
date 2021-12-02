#include <stdio.h>

//通过调用一个函数，将整型数组的所有元素都加3

void add(int b[],int n)
{
    int i;
    for(i=0;i<n;i++)
        b[i]+=3;
}

int main()
{
    int i,a[8]={1,2,3,4,5,6,7,8};
    add(a,8);
    for(i=0;i<8;i++)
        printf("%4d",a[i]);
    return 0;
}
