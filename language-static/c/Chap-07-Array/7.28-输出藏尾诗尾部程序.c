#include <stdio.h>
#include <string.h>

/*编写一个解密藏尾诗的程序。输入一首藏尾诗（假设只有4句），
输出其藏尾的真实含义。例如，输入：
悠悠田园风    然而心难平    兰花轻涌浪    兰香愈幽静
输出：风平浪静*/

int main()
{
	char p[16];
	char s[4][20];
	int i,len;
	for(i=0;i<4;i++)
	    scanf("%s",s[i]);
	len=strlen(s[0]);
	printf("%s",s[0][len-2]);
	for(i=0;i<4;i++)
	{
		p[2*i]=s[i][len-2];/*strlen的长度包括‘\0’*/
		p[2*i+1]=s[i][len-1];/*注意：汉字占两个字符的位置*/
	}
	p[2*i]='\0';
	puts("诗中藏意为：");
	puts(p);
}
