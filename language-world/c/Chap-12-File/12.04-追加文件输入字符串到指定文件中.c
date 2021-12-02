#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <io.h>
#define LEN 100

//利用fgets()函数和fputs()函数重做例 12.3

int main()
{
	FILE *fp;
	char filename[LEN],data[LEN];
	int fno,fsize,i;
	char ch;
	printf("写文件程序...\n");
	printf("请输入要打开文件的完整路径及文件名：\n");
	gets(filename);
	fp=fopen(filename,"a+");/*文件以追加方式写*/
	if(fp==NULL)
	{
		printf("\n 打开文件失败，%s可能不存在\n",filename);
		exit(1);
	}
	fno=fileno(fp);
	fsize=filelength(fno);
	printf("\n%s 文件打开！:\n",filename);
	printf("\n 文件大小 %d Bytes\n",fsize);
	printf("\n 文件内容为：");
	while((ch=fgetc(fp))!=EOF)
	    printf("%c",ch);
	while(1)
	{
		printf("\n\n 请问是否要添加数据（Y/N）：");
		if(toupper(getche()=='Y'))/*toupper()函数为大小写转换函数*/
		{
			printf("\n\n 请输入要添加的数据：");
			gets(data);
	        fputs(data,fp);
		}
		else
		{
			fclose(fp);
			break;
		}
	}
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("\n 打开文件失败，%s可能不存在\n",filename);
		exit(1);
	}
	fno=fileno(fp);
	fsize=filelength(fno);
	printf("\n%s 文件打开！:\n",filename);
	printf("\n 文件大小 %d Bytes\n",fsize);
	printf("\n 文件内容为：");
	while((ch=fgetc(fp))!=EOF)
	    printf("%c",ch);
	fclose(fp);
	printf("\n\n");
	return 0;
}
