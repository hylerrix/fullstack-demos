#include <stdio.h>

/*从键盘输入序列{48,62,35,77,55,14,35,98,22,40}，
用冒泡排序法由低到高排序并输出排序结果*/

int main(){
    int i,j,change=1;
    int a[10]={48,62,35,77,55,14,35,98,22,40};
    for(i=0;i<10&&change;i++)/* 如果比较一趟没有发生交换，这说明已经有序 */
    {
        change=0;
        for(j=0;j<10-i-1;j++)
        if(a[j]>a[j+1])
        {
            a[j]^=a[j+1];
            a[j+1]^=a[j];
            a[j]^=a[j+1];
            change=1;
        }
    }
    printf("排序后：\n");
    for(i=0;i<10;i++)    printf("%d ",a[i]);
    return 0;
}
