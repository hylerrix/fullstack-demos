#include <stdio.h>

//从键盘输入4个学生语文和数学课程的成绩，求每个学生两门课的总分，并按总分从高到低的顺序输出每个学生两门课程的成绩和总分
//方法一：两次循环，外层循环只找总最大值的一行和首行交换，和总分放在另一个数组，两个数组分别交换值

int main(){
    int i,j,k,t,score[4][2],sum[4];/* 定义数组和变量 */
    printf("Input 4 student`s scores(Chinese and Math):\n");
    for(i=0;i<4;i++){
        scanf("%d,%d",&score[i][0],&score[i][1]);/* 输入成绩 */
        sum[i]=score[i][0]+score[i][1];
    }
    for(i=0;i<4;i++){
        k=i;/* 用k存储第一趟总分最高者的下标 */
        for(j=i+1;j<4;j++)
            if(sum[j]>sum[k])    k=j;
        if(k!=i)
        {
            for(j=0;j<2;j++)
            {
                t=score[i][j];/* 变量t用来作交换值的中间值 */
                score[i][j]=score[k][j];
                score[k][j]=t;
            }
            t=sum[i];/* 变量t用来作交换值的中间值 */
            sum[i]=sum[k];
            sum[k]=t;
        }
    }
    printf("The sorted scores:\n");
    printf("%6s%6s%6s:\n","chinese","math","sum");
    for(i=0;i<4;i++)/* 输出每个学生的成绩和总分 */
        printf("%6d%6d%6d\n",score[i][0],score[i][1],sum[i]);
    return 0;
}

//方法二：用到了三重循环（数组冒泡排序），并且将总分分别加入每个一维数组中

int main2(){
    int i,j,k,t,score[4][3];/* 定义数组和变量 */
    printf("Input 4 student`s scores(Chinese and Math):\n");
    for(i=0;i<4;i++){
        scanf("%d,%d",&score[i][0],&score[i][1]);/* 输入成绩 */
        score[i][2]=score[i][0]+score[i][1];
    }
    for(i=0;i<3;i++){/* 控制前一行 */
        for(k=i+1;k<4;k++){/* 控制后一行 */
            if(score[i][2]<score[k][2]){/* 如果前一行的总分比后一行的小 */
                for(j=0;j<3;j++){/* 交换两行的每一列 */
                    t=score[i][j];
                    score[i][j]=score[k][j];
                      score[k][j]=t;
                }
            }
        }
    }
    printf("The sorted scores:\n");
    printf("%6s%6s%6s:\n","chinese","math","sum");
    for(i=0;i<4;i++)/* 输出每个学生的成绩和总分 */
        printf("%6d%6d%6d\n",score[i][0],score[i][1],score[i][2]);
    return 0;
}
