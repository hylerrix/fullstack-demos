#include <stdio.h>

//从键盘输入一个2行3列的矩阵，并将其转置（行和列元素互换）并存到二维数组中

int main(){
    int c[2][3];
    int d[3][2];
    int i,j;
    printf("Input matix c[2][3]：\n");
    for(i=0;i<2;i++){
        for(j=0;j<3;j++)
            scanf("%d",&c[i][j]);
    }
    printf("matix c[2][3]：\n");
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("%4d",c[i][j]);
            d[j][i]=c[i][j];
        }
        printf("\n");
    }
    printf("matix d[3][2]：\n");
    for(j=0;j<3;j++){
        for(i=0;i<2;i++)
            printf("%4d",d[j][i]);
        printf("\n");
    }
    return 0;
}
