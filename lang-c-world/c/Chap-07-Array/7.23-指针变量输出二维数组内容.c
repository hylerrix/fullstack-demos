#include <stdio.h>

/*利用指向分数组的指针变量，输入多个字符串，
将它们按行存储在二维字符数组中，然后输出全部字符串*/

int main(){
    char a[4][20];
    char (*p)[20];/* p是指向分数组的指针变量 */
    printf("Input srtings:\n");
    for(p=a;p<a+4;p++)
        gets(*p);
    printf("Output srtings:\n");
    for(p=a;p<a+4;p++)
        printf("%s ",*p);
    return 0;
}
