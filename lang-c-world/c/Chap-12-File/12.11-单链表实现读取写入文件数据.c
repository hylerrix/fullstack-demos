#include <stdio.h>
#include <stdlib.h>

/*从键盘上输入一个班30个学生的基本信息，
并保存到指定的磁盘文件中，再读出该班学生的基本信息，并显示在屏幕上。
要求选取单链表作为数据结构，并且个功能通过调用函数来实现。*/

struct Node
{
	char name[10];
	int num;
	int age;
	char addr[15];/*数据域*/
	struct Node *next;/*指针域*/
};

struct Node *creat_inf()/*尾插法建立带头结点的单链表*/
{
	struct Node *head,*r,*stu;
	int i=0;
	char choice;
	head=(struct Node *)malloc(sizeof(struct Node));/*创建头结点*/
	head->next=NULL;
	r=head;
	do
	{
		stu=(struct Node *)malloc(sizeof(struct Node));
		printf("\n\n 第%d个人的信息：\n",++i);
		printf("\n 姓名：");
		scanf("%s",stu->name);
		printf("\n 学号：");
		scanf("%d",&stu->num);
		printf("\n 年龄：");
		scanf("%d",&stu->age);
		printf("\n 住址：");
		scanf("%s",stu->addr);
		r->next=stu;/*尾插新结点*/
		r=stu;/*指向尾结点*/
		printf("Continue?(Y/N)");
		choice=getche();
	}while(choice=='Y'||choice=='y');
	r->next=NULL;
	return(head);
}

save_inf(struct Node *h)/*将单链表中的信息保存到指定的磁盘文件中*/
{
	struct Node *stu;
	FILE *fp;
	char filename[40];
	printf("\n 请输入要保存的文件名：");
	scanf("%s",filename);
	if((fp=fopen(filename,"wt"))==NULL)
	{
		printf("写文件出错，按任意键退出！");
		getch();
		exit(1);
	}
	for(stu=h->next;stu!=NULL;stu=stu->next)
	    fprintf(fp,"%s %d %d %s\n",stu->name,stu->num,stu->age,stu->addr);
	printf("\n 文件已成功保存，按任意键返回！");
	getch();
	fclose(fp);
}

struct Node *read_inf()/*从指定的磁盘文件中读取信息并存入单链表*/
{
	struct Node *head,*r,*stu;
	FILE *fp;
	char filename[40];
	printf("\n 请输入要打开的文件名：");
	scanf("%s",filename);
	if((fp=fopen(filename,"rt"))==NULL)
	{
		printf("读文件出错，按任意键退出！");
		getch();
		exit(1);
	}
	head=(struct Node *)malloc(sizeof(struct Node));
	head->next=NULL;
	r=head;
	while(!feof(fp))/*文件未结束*/
	{/*开辟空间，以存放读取的信息*/
		stu=(struct Node *)malloc(sizeof(struct Node));
		/*存放读取信息*/
		fscanf(fp,"%s %d %d %s",stu->name,&stu->num,&stu->age,stu->addr);
		r->next=stu;/*链接结点*/
		r=stu;
	}
	r->next=NULL;
	fclose(fp);
	printf("\n 文件中信息已正确读出，按任意键返回！");
	getch();
	return head;
}

printf_inf(struct Node *h)/*将链表中的信息打印输出*/
{
	struct Node *stu;
	printf("\n 该班数据为：\n");
	printf("姓名 学号 年龄 住址\n");
	for(stu=h->next;stu->next!=NULL;stu=stu->next)
	    printf("%s %d %d %s\n",stu->name,stu->num,stu->age,stu->addr);
}

int main()
{
	struct Node *head;
	head=creat_inf();/*创建基本信息单链表*/
	save_inf(head);/*保存基本信息到指定文件*/
	head=read_inf();/*从指定文件中读取信息*/
	printf_inf(head);/*打印显示单链表中基本信息*/
	return 0;
}
