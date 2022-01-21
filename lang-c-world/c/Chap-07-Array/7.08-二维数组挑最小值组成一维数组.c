#include <stdio.h>

//在二维数组A中选出个行最小值的元素组成一个一维数组B

int main(){
    int a[3][4]={3,2,1,5,8,6,5,7,9,8,6,7};
    int b[3],i,j,min;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            min=a[i][j];
            if(a[i][j]>a[i][j+1])
                min=a[i][j+1];
        }
        b[i]=min;
    }
    printf("array A:\n");
    for(i=0;i<3;i++){
        for(j=0;j<4;j++)
            printf("%4d",a[i][j]);
        printf("\n");
    }
    printf("array B:\n");
    for(i=0;i<3;i++)
        printf("%4d",b[i]);
    return 0;
}
