#include <stdio.h>

//矩阵乘法实现，例如 C[2][3]={{1,3,5},{2,4,6}},D[3][2]={{1,2},{3,4},{5,6}}

int main()
{
	int C[2][3]={{1,3,5},{2,4,6}},D[3][2]={{1,2},{3,4},{5,6}};
	int i,j,k,E[2][3]={0};
	for(i=0;i<2;i++)/*遍历C矩阵的各行*/
	    for(j=0;j<2;j++)
	        for(k=0;k<3;k++)/*用k循环求累加和来计算E[i][j]*/
		        E[i][j]+=C[i][k]*D[k][j];
	printf("Array E=C*D:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		    printf("%5d",E[i][j]);
		printf("\n");
	}
	return 0;
}
