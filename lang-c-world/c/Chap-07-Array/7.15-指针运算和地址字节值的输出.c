#include <stdio.h>

//指针运算和地址字节值的输出，下标法和指针法访问数组元素的实例

int main(){
    int b[10]={100,200,300,400,500,600,700,800,900,1000};
    int *p=b;/* 可将*p=b改为*p=&b[0] */
    float s[8],*pf=s;
    printf("sizeof(int)=%d \n",sizeof(int));            /* 32位编译系统中int的字节数是4 */
    printf("sizeof(float)=%d \n",sizeof(float));        /* float类型字节数是4 */
    printf("pf=%X    pf+1=%X \n",pf,pf+1);                /* pf基类型字节数是4 */
    printf("p=%X    p+1=%X \n",p,p+1);                    /* p基类型字节数是4 */
    printf("&p[0]=%X    &p[1]=%X \n",&p[0],&p[1]);        /* 改为下标法效果相同 */
    printf("&b[0]=%X    &b[1]=%X \n",&b[0],&b[1]);        /* 将p改为b效果相同 */
    printf("*p+4=%d    *(p+4)=%d\n",*p+4,*(p+4));        /* *p+4和*(p+4)不同 */
    printf("*b+4=%d    *(b+4)=%d\n",*b+4,*(b+4));        /* 将p改为b效果相同 */
    return 0;
}
