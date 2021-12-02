#include <stdio.h>

//定义一个由整数组成的数组，求出其中奇数的个数和偶数的个数，并打印

int main(){
    int a[]={1,2,3,4,5,6,8};
    int i,odd=0,even=0;
    int len=sizeof(a)/sizeof(int);
    printf("数组元素为：\n");
    for(i=0;i<len;i++)
    {
        if(a[i]%2==0) even++;
        else odd++;
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("奇数的个数：%d\n",odd);
    printf("偶数的个数：%d\n",even);
    return 0;
}
