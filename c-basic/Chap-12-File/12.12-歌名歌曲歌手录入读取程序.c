#include <stdio.h>
#include <string.h>
#define N 3

/*一个文件song.txt存放了若干首歌曲的记录，
每条记录由歌名（40个字符）和演唱者（30个字符）组成，
如图12.5所示的格式，以减少文件的长度。
其中，M是歌名长度，NN是演唱者长度。编写一个程序，
完成这种格式的转换，转换后的新格式记录放在Newsong.txt文件中。 */

typedef struct song
{
	char sname[40];/*歌名*/
	char pname[30];/*演唱者*/
}REC;

int main()
{
	REC song[N],t;
	int M,NN,i;
	char ch;
	FILE *fsource,*farget;
	fsource=fopen("song.txt","w+");
	farget=fopen("Newsong.txt","w");
	if(fsource==NULL||farget==NULL)
	{
		printf("打开文件出错，按任意键退出！");
		getch();
		exit(1);
	}
	for(i=0;i<N;i++)
	{
		printf("\n第%d首歌的信息：\n",i+1);
		printf("\n歌名：");
		gets(song[i].sname);
		printf("\n演唱者：");
		gets(song[i].pname);
		fwrite(&song[i],sizeof(REC),1,fsource);
		fputc('\n',fsource);/*写一个回车换行*/
	}
	rewind(fsource);/*回到文件开始*/
	while(fread(&t,sizeof(REC),1,fsource)!=NULL);
	{
		fgetc(fsource);/*读完回车换行*/
		M=strlen(t.sname);/*歌名实际长度*/
		NN=strlen(t.pname);/*演唱者实际长度*/
		fprintf(farget,"%d",M);/*向文件中写歌名长度*/
		fprintf(farget,"%d",NN);/*向文件中写演唱者长度*/
		//fwrite(&t.sname,M,1,farget);/*向文件中写歌名*/
		//fwrite(&t.pname,NN,1,farget);/*向文件中写演唱者*/
		fputc('\n',farget);/*写一个回车换行*/
	}
	fclose(fsource);
	fclose(farget);
	return 0;
}
