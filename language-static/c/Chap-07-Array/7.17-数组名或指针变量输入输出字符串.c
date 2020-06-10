#include <stdio.h>

//用字符型数组名和字符指针变量两种方法整体输入与输出字符串

int main(){
    char str[62]="good moring!",*p=str;/* 定义ps为指向字符串的首字符的指针变量 */
    char *nstr="nice to meet you";
    printf("%s\n",str);/* 用字符型数组整体输出字符串 */
    printf("%s\n",nstr);/* 用字符指针整体输出字符串 */
    gets(str);/* 用字符型数组整体输入带空格的字符串 */
    printf("%s\n",str);
    gets(p);/* 用字符指针整体输入带空格的字符串 */
    printf("%s\n",str);/* 与printf("%s\n",p); 等价 */
    return 0;
}
