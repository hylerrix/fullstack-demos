#include <stdio.h>
#include <conio.h>
#include <windows.h>

//��дһ�������õ�ʱ�ӳ��򣬰�S����ʼ��ʱ����E��ֹͣ��ʱ

struct clock
{
    int hours;
    int minutes;
    int seconds;
};

void display(struct clock t)/* ��ʾʱ��ʱ�䣬�ṹ�����������Ϊ�������� */
{
    printf("\r%02d:",t.hours);
    printf("%02d:",t.minutes);
    printf("%02d",t.seconds);
}

struct clock update(struct clock t)/* ʱ��ʱ��ÿ��1����и��� */
{/* �ṹ��������Ϊ�����ķ���ֵ */
    t.seconds++;
    if(t.seconds==60)
    {
        t.seconds=0;
        t.minutes++;
    }
    if(t.minutes==60)
    {
        t.minutes=0;
        t.hours++;
    }
    if(t.seconds==24)
        t.hours=0;
    sleep(1000);/* ϵͳ�ݶ�һ�� */
    return t;
}

int main()
{
    struct clock cl={0,0,0};/* ��ʼ����0��ʼ */
    char ch;
    printf("please press \"s\" to start my clock\n");
    printf("please press \"e\" to end my clock\n");
    display(cl);
    ch=getch();
    while(1)
    {
        if(ch=='s' || ch=='S')
        {
            cl=update(cl);
            display(cl);
            if(kbhit())/* ��⵱ǰ�Ƿ��м������� */
            {
                ch=getch();
                if(ch=='e' || ch=='E')
                    break;
            }
        }
        else if(ch=='e' || ch=='E')
            break;
        else
            ch=getch();
    }
    printf("\n");
    return 0;
}
