#include <stdio.h>
#include <conio.h>
#include <windows.h>

//编写一个竞赛用的时钟程序，按S键开始计时，按E键停止计时

struct clock
{
    int hours;
    int minutes;
    int seconds;
};

void display(struct clock t)/* 显示时钟时间，结构体变量整体作为函数参数 */
{
    printf("\r%02d:",t.hours);
    printf("%02d:",t.minutes);
    printf("%02d",t.seconds);
}

struct clock update(struct clock t)/* 时钟时间每隔1秒进行更新 */
{/* 结构体类型作为函数的返回值 */
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
    sleep(1000);/* 系统暂定一秒 */
    return t;
}

int main()
{
    struct clock cl={0,0,0};/* 初始化从0开始 */
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
            if(kbhit())/* 检测当前是否有键盘输入 */
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
