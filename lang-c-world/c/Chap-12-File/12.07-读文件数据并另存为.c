#include <stdio.h>
#include <stdlib.h>
#define N 30

//利用fread()和fwrite()函数实现例12.6

struct stu
{
	char num[20];
	char name[40];
	char sex[5];
}class[N];

int main()
{
	FILE *fp;
	int i;
	printf("\n 输入该班的数据：\n");
	fp=fopen("class_list.txt","wt");
	if(fp==NULL)
	{
		printf("不能打开此类文件，按任意键退出！");
		getch();
		exit(1);
	}
	for(i=0;i<N;i++)
	{
		printf("\n 第%d个人的信息：\n",i+1);
		printf("\n 学号：");
		gets(class[i].num);
		printf("\n 姓名：");
		gets(class[i].name);
		printf("\n 性别：");
		gets(class[i].sex);
		fwrite(&class[i],sizeof(struct stu),1,fp);
	}
	fclose(fp);
	fp=fopen("class_list.txt","rt");
	printf("该班数据为：\n");
	printf("学号 姓名 性别\n");
	i=0;
	while(fread(&class[i],sizeof(struct stu),1,fp)!=NULL)
    {
    	printf("%s %s %s\n",class[i].num,class[i].name,class[i].sex);
    	i++;
	}
	fclose(fp);
	return 0;
}
