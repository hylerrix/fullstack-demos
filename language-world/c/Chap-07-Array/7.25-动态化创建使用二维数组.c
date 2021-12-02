#include <stdio.h>

//用动态数组实现二维数组的创建和使用

int main(){
    int n1,n2;
    int **array,i,j;
    puts("输入一维长度：");
    scanf("%d",&n1);
    puts("输入二维长度：");
    scanf("%d",&n2);
    /* 先遵循从外层到里层，逐层申请的原则： */
    /* 第一维，开辟元素为n1的指针型数组，用来存放二维数组每行首地址 */
    array=(int**)malloc(n1*sizeof(int*));
    if(array==NULL){/* 内存申请失败，提示退出 */
        printf("out of memory,press any key to quit...\n");
        exit(0);/* 终止程序运行，返回操作系统 */
    }
    for(i=0;i<n1;i++){
        array[i]=(int*)malloc(n2* sizeof(int));
        if(array==NULL){/* 内存申请失败，提示退出 */
            printf("out of memory,press any key to quit...\n");
            exit(0);/* 终止程序运行，返回操作系统 */
        }
        for(j=0;j<n2;j++){
            array[i][j]=i+j+1;
            printf("%d\t",array[i][j]);
        }
        puts("");
    }
    /* 最后不要忘了释放这些内存，这要遵循释放的时候从里层到外层，逐层释放的原则 */
    for(i=0;i<n1;i++)
        free(array[i]);
    free(array);
    return 0;
}
