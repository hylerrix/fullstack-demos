#include <stdio.h>

//��֪�ڴ����к졢�ơ��ס������ڹ�5�ֲ�ͬ��ɫ��С�������δӴ���ȡ3��
//���ʵõ�3�ֲ�ͬɫ��Ŀ���ȡ������ÿ����ʾ5�ֵķ�ʽ��������е����������

enum color {red,yellow,white,blue,black};/* ����ö������ */

int main()
{
    enum color b[3];
    int i,count=0;
    for(b[0]=red;b[0]<=black;b[0]++)
        for(b[1]=red;b[1]<=black;b[1]++)
            for(b[2]=red;b[2]<=black;b[2]++)
                if(b[0]!=b[1] && b[0]!=b[2] &&  b[1]!=b[2])/* ��������ɫ��ͬ */
                {
                    count++;/* ʹ�ۼ���count+1 */
                    printf("No.%-2d ",count);
                    for(i=0;i<3;i++)
                    {
                        switch(b[i])/* ���ݲ�ͬ�������������ɫ */
                        {
                            case red:
                                printf("��");
                                break;
                            case yellow:
                                printf("��");
                                break;
                            case white:
                                printf("��");
                                break;
                            case blue:
                                printf("��");
                                break;
                            case black:
                                printf("��");
                                break;
                        }
                    }
                    if(count%5==0)/* ÿ�����5����� */
                        printf("\n");
                    else
                        printf("\t");
                }
    return 0;
}
