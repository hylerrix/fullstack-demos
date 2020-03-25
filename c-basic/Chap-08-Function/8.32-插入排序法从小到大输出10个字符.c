#include <stdio.h>

//利用插入排序法将10个字符从小到大进行排序

insert(char s[])
{
    int i,j,t;
    for(i=1;i<9;i++)
    {
        t=s[i];
        j=i-1;
        while((j>=0)&&(t<s[j]))
        {
            s[j+1]=s[j];
            j--;
        }
        s[j+1]=t;
    }
}

int main()
{
    char a[11];
    int i;
    printf("Input 10 character:");
    for(i=0;i<10;i++)
        a[i]=getchar();
    a[i]='\0';/* 在10个字符后面加上'\0'，形成字符串 */
    insert(a);
    printf("Sorted character is:%s\n",a);/* 将已排序的10个字符输出 */
    return 0;
}
