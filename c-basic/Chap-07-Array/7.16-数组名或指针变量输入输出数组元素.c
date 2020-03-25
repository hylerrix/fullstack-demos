#include <stdio.h>

//分别用数组名和指针变量，以下标法和指针法输入和输出数组的所有元素

int main(){
    int i=0;
    int array[6];
    int *p=array;
    printf("\n Please input array[6]: \n");
    while(p<(array+6))
        scanf("%d",p++);
    printf("\n Output array[i]: \n");
    for(i=0;i<6;i++)/* （1）数组名，下标法 */
        printf("%d,",array[i]);
    printf("\n Output *(array+i): \n");
    for(i=0;i<6;i++)/* （2）数组名，指针法 */
        printf("%d,",*(array+i));
    printf("\n Output p[i]: \n");
    p=array;
    for(i=0;i<6;i++)/* （3）指针变量，下标法 */
        printf("%d,",p[i]);
    printf("\n Output *(p+i): \n");
    for(i=0;i<6;i++)/* （4）指针变量，指针法 */
        printf("%d,",*(p+i));
    printf("\n Output *p++: \n");
    while(p<(array+6))/* （5）指针变量，指针法，效率最高 */
        printf("%d,",*p++);
    printf("\n");
    return 0;
}
