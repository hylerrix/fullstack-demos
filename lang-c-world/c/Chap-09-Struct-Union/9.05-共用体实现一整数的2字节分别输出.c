#include <stdio.h>

//ͨ���������������һ��������2�ֽڷֱ�ʮ�����ƺ��ַ���ʽ���

union int_char
{
    char ch[2];
    int i;
};

void OutPut(union int_char x)
{
    printf("i=%d\ti=%X\n",x.i,x.i);
    printf("ch0=%X,ch1=%X\n",x.ch[0],x.ch[1]);
    printf("ch0=%c,ch1=%c\n",x.ch[0],x.ch[1]);
}

int main()
{
    union int_char x;
    x.i=19788;
    OutPut(x);
    return 0;
} 
