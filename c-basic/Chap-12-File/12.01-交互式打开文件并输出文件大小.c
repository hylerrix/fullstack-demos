#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#define LEN 100

/*采用交互式文件方式打开指定文件，
若文件打开成功，则显示该文件的大小（byte）；
若文件打开失败，则提输出错信息 */

int main()
{
	FILE *fp;
	char filename[LEN];
	int fno,fsize;
	printf("请输入要打开文件的完整路径及文件名：");
	gets(filename);/*输入要打开的文件所在路径及其名称*/
	fp=fopen(filename,"r");/*打开已经存在的文件*/
	if(fp==NULL)/*判断是否打开文件成功*/
	{
		printf("\n打开文件失败，%s可能不存在\n",filename);
		exit(1);/*错误退出*/
	}
	fno=fileno(fp);/*取得文件描述字*/
	fsize=filelength(fno);/*取得文件大小，以Byte为单位*/
	printf("\n %s文件打开成功，文件大小 %d Bytes\n",filename,fsize);
	return 0;
}
