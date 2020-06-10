#include <stdio.h>
#include <stdlib.h>

//在例12.7中的class.txt学生文件中读出第二个学生的数据

struct stu
{
	char num[20];
	char name[40];
	char sex[5];
}q;

int main()
{
	FILE *fp;
	int i=1;
	printf("\n 输入该班的数据：\n");
	fp=fopen("class_list.txt","rt");
	if(fp==NULL)
	{
		printf("不能打开此类文件，按任意键退出！");
		getch();
		exit(1);
	}
	fseek(fp,i*sizeof(struct stu),0);
	fread(&q,sizeof(struct stu),1,fp);
	printf("\n 该班第二个学生的数据信息为：");
	printf("\n\n 姓名 学号 年龄 地址\n");
	printf("%s %s %s\n",q.num,q.name,q.sex);
}
