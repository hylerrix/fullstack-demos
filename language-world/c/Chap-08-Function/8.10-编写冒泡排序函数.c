#include <stdio.h>

//编写冒泡排序函数，对主函数中输入的无序整数按由大到小的顺序进行排序。

sort(int b[10],int n)
{
    int i,j,t;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(b[j]<b[j+1])/* b[j]和b[j+1]交换 */
            {
                t=b[j];
                b[j]=b[j+1];
                b[j+1]=t;
            }
}

int main()
{
    int a[10],i;
    printf("Please input 10 numbers:\n");
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    sort(a,10);/* 调用函数对数组进行排序 */
    printf("Sorted data is:\n");
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
