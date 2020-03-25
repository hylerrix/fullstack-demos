#include <stdio.h>

//十进制与其他进制（二至九进制）数间的互相转换，程序能够自动帮助用户纠正输入错误

long change(int a[],int len,int b)
/* 把输入的字符数字转换成十进制数字 */
{
    int i,k=1;
    long num=0;
    for(i=1;i<=len;i++)
    {
        num=num+a[i]*k;
        k=k*b;/* k表示权值 */
    }
    return num;
}

ten_to_oth()/* 十进制转换为其他进制 */
{
    int sum,n,i=0,j,arr[80];
    printf("Please input a Dec_num:");/* 输入10进制数 */
    scanf("%d",&sum);
    printf("Please input the base:");/* 输入想要转换的进制 */
    scanf("%d",&n);
    do
    {
        i++;
        arr[i]=sum%n;/* 从下标1开始计数 */
        sum=sum/n;
        if(i>=80)
            printf("overflow");
    }while(sum!=0);
    printf("The result is:");
    for(j=i;j>0;j--)
        printf("%d",arr[j]);
    printf("\n");
}

oth_to_ten()/* 其他进制转换为十进制 */
{
    int base,i,num,arr[80];
    long sum=0;
    char ch;
    /* 想将几进制数转换成十进制数，请输入 */
    printf("Please input the base you want to change :");
    scanf("%d",&base);
    /* 请输入该数 */
    printf("Please input number:");
    scanf("%d",&num);
    for(i=1;num!=0;i++)
    {
        arr[i]=num%10;/* 从下标1开始计数 */
        num=num/10;
    }
    sum=change(arr,i-1,base);
    printf("The result is:%ld\n",sum);
}

int main()
{
    int flag=1;
    while(flag!=0)
    {
        printf("1:ten_to_oth\n");
        printf("2:oth_to_ten\n");
        printf("0:exit\n");
        printf("Enter a number:");
        scanf("%d",&flag);
        switch(flag)
        {
            case 1:ten_to_oth();break;/* 其他进制转换为十进制 */
            case 2:oth_to_ten();break;/* 十进制转换为其他进制 */
            case 0:return 0;
        }
    }
    return 0;
}
