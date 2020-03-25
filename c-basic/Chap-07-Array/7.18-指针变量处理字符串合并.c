#include <stdio.h>

//用指向字符串的指针变量处理两个字符串的合并

int main(){
    char str1[80],str2[30],*ptr1=str1,*ptr2=str2;
    printf("input str1:");
    gets(str1);
    printf("input str2:");
    gets(str2);
    printf("str1----------str2\n");
    printf("%s.......%s\n",ptr1,ptr2);
    while(*ptr1)ptr1++;/* 移动指针到串尾 */
    while(*ptr2)*ptr1++=*ptr2++;/* 连接串 */
    *ptr1='\0';/* 写入串的结束标志 */
    ptr1=str1;ptr2=str2;
    printf("str1----------str2\n");
    printf("%s.......%s\n",ptr1,ptr2);
    return 0;
}
