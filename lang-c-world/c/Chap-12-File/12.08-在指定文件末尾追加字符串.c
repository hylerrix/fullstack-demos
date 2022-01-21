#include <stdio.h>
#include <stdlib.h>

//实现在已存在的指定文件末尾追加一个可带空格的字符串

int main()
{
	FILE *fp;
	char ch,str[20];
	fp=fopen("string.txt","at+");/*以追加方式打开文件*/
	if(fp==NULL)
	{
		printf("不能打开此类文件，按任意键退出！");
		getch();
		exit(1);
	}
	printf("请输入一个字符串：\n");
	gets(str);
	fwrite(str,strlen(str),1,fp);/*将数组str中的字符串写入文件中*/
	rewind(fp);/*将文件指针fp重新移回文件首部*/
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	printf("\n");
	fclose(fp);
	return 0;
}
