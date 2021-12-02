#include <stdio.h>

/*
注：不允许使用字符串连接函数
编一个程序，输入3个字符串（长度均不超过20）存入一个二维的字符型数组中，
将第3个字符串连接到第二个字符串之后，组成新的字符串存入以为的字符型数组中，
然后输出该新的字符串
*/

int main(){
    char dest[61],str[3][21];
    int i,j,k;
    scanf("%s%s%s",str[0],str[1],str[2]);
    k=0;
    for(i=0;i<3;i++){
        for(j=0;j<20;j++){
            if(str[i][j]=='\0')
                break;
            else{
                dest[k]=str[i][j];
                k++;
            }
        }
    }
    dest[k]='\0';
    printf("%s",dest);
    return 0;
}
