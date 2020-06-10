#include <stdio.h>

//地址越界实例，本程序不能正常运行

int main(){
    char ps[]="Good!",*p=ps;
    char pt[]="you are a student.";
    printf("%s\n",ps);
    for(p=ps;p<ps+10;p++)
        *p='M';/* 错误：地址越界 */
    printf("%s\n",ps);/* 错误，ps的字符串结束标志被破坏 */
    scanf("%s",ps);/* 如果输入字符串长度超过5则越界 */
    printf("%s\n",ps);/* 可能输出乱符 */
    return 0;
}
