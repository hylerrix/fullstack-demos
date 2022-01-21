#include <stdio.h>
#include <stdlib.h>
#define N 30

//从键盘上输入一个班30个学生的数据并保存到磁盘文件中，再读出该班学生的数据并显示在屏幕上

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
		fprintf(fp,"%s %s %s\n",class[i].num,class[i].name,class[i].sex);
	}
	fclose(fp);
	fp=fopen("class_list.txt","rt");
	printf("该班数据为：\n");
	printf("学号 姓名 性别\n");
	i=0;
	while(fscanf(fp,"%s %s %s\n",class[i].num,class[i].name,class[i].sex)!=EOF)
    {
    	printf("%s %s %s\n",class[i].num,class[i].name,class[i].sex);
    	i++;
	}
	fclose(fp);
	return 0;
}
