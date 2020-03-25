#include <stdio.h>
#include <math.h>

/*一个素数经过任意次调换位，任然为素数，则称其为绝对素数，
例如，13(31)就是一个绝对素数。求两位的所有绝对素数并输出。*/

int prime(int n)/* 判断一个数是否是素数 */
{
    int i;
    if(n<=1)/* 小于2不是素数 */
        return 0;
    else if(n==2)/* 2是素数 */
        return 1;
    else/* 大于2要判断是不是 */
    {
        for(i=2;i<sqrt(n);i++)
            if(n%i==0)/* 一旦能整除i，则n不是素数 */
                return 0;
        return 1;/* 如鼓苤葱姓馓跤锞洌�代表n从来没被i整除过，是素数 */
    }
}

int ab_prime(int m)/* 判断一个位数是否是绝对素数 */
{
    int a;
    a=(m%10)*10+m/10;/* 得到换位后的数 */
    if(prime(m)&&prime(a))/* m和a都是素数，则m为绝对素数，否则不是 */
        return 1;
    else
        return 0;
}

int main()
{
    int i;
    for(i=10;i<100;i++)
        if(ab_prime(i))/* 循环从10到99找绝对素数 */
            printf("%d,",i);/* 是绝对素数则输出 */
    return 0;
}
