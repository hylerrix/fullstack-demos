#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#define LEN 100

//将例12.1中的文件内容显示出来

int main(){
	FILE *fp;
	char filename[LEN];
	int fno,fsize;
	char ch;
	printf("请输入要打开文件的完整路径及文件名：");
	gets(filename);
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("\n 打开文件失败，%s可能不存在\n",filename);
		exit(1);
	}
	fno=fileno(fp);
	fsize=filelength(fno);
	printf("\n%s 文件打开！\n",filename);
	printf("\n 文件大小 %d Bytes\n",fsize);
	printf("\n 文件内容为：");
	while((ch=fgetc(fp))!=EOF)
	    printf("%c ",ch);
	return 0;
}
