#include <stdio.h>
#include <stdlib.h>

/*编写一段程序，要求定义一个含有5个元素的数组，实现数组接受键盘输入的数字，
输入完毕后打印数组元素，比较得出数组元素的最大值和最小值，并输出*/

int main(){
    int a[5],i;
    int max,min;
    printf("请输入5个整数，用空格隔开：\n");
    fflush(stdout);/* 清空标准输出 stdout 的缓冲区 */
    for(i=0;i<5;i++)    scanf("%d",&a[i]);
    printf("这五个整数为：\n");
    for(i=0;i<5;i++)    printf("%d ",a[i]);
    max=min=a[0];
    for(i=0;i<5;i++){
        if(max<a[i]) max=a[i];
        else if(max>a[i]) min=a[i];
    }
    printf("\n");
    printf("最大数：%d\n",max);
    printf("最小数：%d\n",min);
    return 0;
}
