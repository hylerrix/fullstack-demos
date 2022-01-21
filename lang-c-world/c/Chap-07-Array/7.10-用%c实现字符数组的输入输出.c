#include <stdio.h>
#include <stdlib.h>

//用格式符%c逐个输入字符到字符数组，然后逐个字符输出

int main(){
    char d[20];int i;
    printf("please input 10 char:\n");
    for(i=0;i<10;i++)
        scanf("%c",&d[i]);/* 必须输入10个字符，不会自动加结束符'\0' */
    d[i]='\0';/* 在末尾加上结束符'\0' */
    for(i=0;i<10;i++)
        printf("%c",d[i]);
    printf("\n");
    printf("%s",d);/* 因为在末尾加了结束符，所以可以整体输出 */
    return 0;
}
