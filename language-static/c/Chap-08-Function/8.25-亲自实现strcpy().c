#include <stdio.h>

//实现系统提供的字符串复制函数 strcpy()的全部功能

char *strcpy(char*s1,char *s2)
{
    char *p=s1;/* 用p保存s1接收来的实参字符数组的首地址 */
    while(*s1++=*s2++);/* 当s2指到'\0'时，先赋值完成后循环结束 */
    return(p);/* 通过函数名返回指针值 */
}

int main()
{
    char s[20];
    printf("%s\n",strcpy(s,"Welocme to you!"));/* 输出返回值指向的内容 */
    return 0;
}
