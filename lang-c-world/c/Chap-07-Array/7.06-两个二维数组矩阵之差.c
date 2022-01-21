#include <stdio.h>

//二维数组计算两个矩阵MA和MB之差，将结果存储在MA中

int main(){
    int i,j;
    int a[3][3]={5,6,7,4,3,8,2,9,1,10};
    int b[3][3]={1,5,4,6,9,8,7,3,2,10};
    printf("矩阵1：\n");/* 输出矩阵MA */
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    printf("矩阵2：\n");/* 输出矩阵MB */
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%4d",b[i][j]);
        }
        printf("\n");
    }
    printf("2个矩阵之差：\n");/* 输出矩阵MA-MB的结果 */
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            a[i][j]-=b[i][j];
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
