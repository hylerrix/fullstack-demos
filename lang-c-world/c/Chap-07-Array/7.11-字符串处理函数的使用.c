#include <stdio.h>
#include <string.h>/* 字符串处理函数 */

//字符串长度函数        strlen(字符串)
//字符串整行输入函数    gets(字符串)
//字符串整体输出函数    puts(字符串)
//字符串比较函数        strcmp(字符串1,字符串2)
//字符串复制函数        stecpy(字符串数组1,字符串2)
//字符串连接函数        strcat(字符串数组1,字符串2)

//上述6个字符串处理函数应用举例

int main(){
    char str1[30]="Happy birthday",str2[30]="2014";
    puts(strcat(str1,str2));
    printf("%d %d\n",strlen(str1),strcmp(str1,str2));
    gets(str1);
    printf("%d %d\n",strlen(str1),strcmp(str1,str2));
    puts(strcpy(str1,str2));
    printf("%d %d\n",strlen(str1),strcmp(str1,str2));
    gets(str1);
    puts(strcat(str1,str2));
    return 0;
}
