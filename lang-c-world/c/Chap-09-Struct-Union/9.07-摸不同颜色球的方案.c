#include <stdio.h>

//已知口袋中有红、黄、白、蓝、黑共5种不同颜色的小球，若依次从袋中取3个
//，问得到3种不同色球的可能取法。以每行显示5种的方式，输出所有的排列情况。

enum color {red,yellow,white,blue,black};/* 定义枚举类型 */

int main()
{
    enum color b[3];
    int i,count=0;
    for(b[0]=red;b[0]<=black;b[0]++)
        for(b[1]=red;b[1]<=black;b[1]++)
            for(b[2]=red;b[2]<=black;b[2]++)
                if(b[0]!=b[1] && b[0]!=b[2] &&  b[1]!=b[2])/* 三种球颜色不同 */
                {
                    count++;/* 使累加器count+1 */
                    printf("No.%-2d ",count);
                    for(i=0;i<3;i++)
                    {
                        switch(b[i])/* 根据不同情况，输出球的颜色 */
                        {
                            case red:
                                printf("红");
                                break;
                            case yellow:
                                printf("黄");
                                break;
                            case white:
                                printf("白");
                                break;
                            case blue:
                                printf("蓝");
                                break;
                            case black:
                                printf("黑");
                                break;
                        }
                    }
                    if(count%5==0)/* 每行输出5种情况 */
                        printf("\n");
                    else
                        printf("\t");
                }
    return 0;
}
