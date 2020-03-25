#include <stdio.h>

//实现系统提供的字符串连接函数strcat(s1,s2)

char *strcat(char *s1,char *s2)
{
    char *p=s1;/* 用p保存s1接收来的实参字符数组的首地址 */
    while(*s1)    s1++;/* s1指到'\0'时循环结束 */
    while(*s1++=*s2++);/* 当s2指到'\0'时，先赋值完成后循环结束 */
    return(p);/* 通过函数名返回指针值 */
}

int main()
{
    char s[20]="Hello,";
    printf("%s\n",strcat(s,"Welcome to you!"));
    return 0;
}
