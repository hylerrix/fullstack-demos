#include <stdio.h>
#include <stdlib.h>

/*有两个磁盘文件string1和string2，
各存放一行字母，要求把这两个文件中的信息合并
后并按字母顺序输出到一个新的磁盘文件string中 */

int main()
{
	FILE *fp;
	int i,j,count,count1;
	char string[160],t,ch;
	fp=fopen("string1.txt","rt");
	if(fp==NULL)
	{
		printf("不能打开文件 string1！\n");
		exit(1);
	}
	printf("\n 读取到文件string1的内容为：\n");
	for(i=0;(ch=fgetc(fp))!=EOF;i++)
	{
		string[i]=ch;
		putchar(string[i]);
	}
	fclose(fp);
	count1=i;/*记录连接数组2的位置*/
	fp=fopen("string2.txt","rt");
	if(fp==NULL)
	{
		printf("不能打开文件 string1！\n");
		exit(1);
	}
	printf("\n 读取到文件string2的内容为：\n");
	for(i=count;(ch=fgetc(fp))!=EOF;i++)
	{
		string[i]=ch;
		putchar(string[i]);
	}
	fclose(fp);
	count=i;/*记录数组string的长度*/
	for(i=0;i<count;i++)/*冒泡排序算法对数组进行排序*/
	    for(j=i+1;j<count;j++)
	        if(string[i]>string[j])
	        {
	        	t=string[i];
	        	string[i]=string[j];
	        	string[j]=t;
			}
	printf("\n 排序后数组string的内容为：\n");
	printf("%s\n",string);
	fp=fopen("string.txt","wt");
	fputs(string,fp);/*将数组string的内容写到fp所指的文件中*/
	printf("并已将改内容写入文件string.txt中！");
	fclose(fp);
	return 0;
}
