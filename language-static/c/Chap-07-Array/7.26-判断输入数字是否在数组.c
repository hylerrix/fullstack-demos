#include <stdio.h>
#define M 10

/*从键盘输入一个数，判定该数是否在数组中，
若在，输出所在序号；若不再，输出相应信息。*/

int main()
{
	int a[M]={-12,0,6,16,23,56,80,100,110,115};
	int n,low,mid,high,found;
	low=0;
	high=M-1;
	found=0;
	printf("Input a number to be searched:");
	scanf("%d",&n);
	while(low<=high)
	{
		mid=(low+high)/2;
		if(n==a[mid])
		{
			found=1;
			break;
		}/*找到，结束循环*/
		else if(n>a[mid])
		    low=mid+1;
		else
		    high=mid-1;
	}
	if(found==1)
		printf("The index of %d is %d",n,mid);
	else
	    printf("There is not %d",n);
	return 0;
}
